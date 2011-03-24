#include "formeditorwindow.h"

#include <QVariant>
#include <QtGui>
#include <QLabel>
#include <QList>
#include <QStandardItemModel>
#include <QVariant>
#include "customtreewidgetitem.h"

FormEditorWindow::FormEditorWindow(QWidget *parent, SCDataModel *dataModel) :
        QMainWindow(parent, Qt::WindowStaysOnTopHint),
        dm(dataModel),
        _currentlySelected(NULL)
{

    createActions();

    createMenus();
    createToolbars();


    // central widget and outter layout

    QHBoxLayout *layout = new QHBoxLayout;
    QWidget *widget = new QWidget;
    widget->setLayout(layout);
    setCentralWidget(widget);

    //  start tree view

    stateChartTreeView = new QTreeWidget();
    stateChartTreeView->setColumnCount(1);
    connect ( stateChartTreeView, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(handleTreeViewItemClicked(QTreeWidgetItem*,int)));
    layout->addWidget (stateChartTreeView );

    QVBoxLayout *vlayout = new QVBoxLayout;
    layout->addLayout(vlayout );

    selectedChartItem = new QLabel();
    vlayout->addWidget( selectedChartItem);


    //  property table

    propertyTable = new QTableWidget();
    propertyTable->setColumnCount(2);
    vlayout->addWidget( propertyTable );


    setWindowTitle(tr("State Chart Editor"));
    setUnifiedTitleAndToolBarOnMac(true);


    QList<SCState*> states;
    states.append( dm->getTopState());

    connect (dm, SIGNAL(newTransitionSignal(SCTransition*)), this, SLOT(handleNewTransition(SCTransition*)));

    loadTree (NULL, states);
}

void FormEditorWindow::handleNewTransition(SCTransition*)
{
    QList<SCState*> states;
    states.append( dm->getTopState());

    stateChartTreeView->clear();

    loadTree (NULL, states);
}


void FormEditorWindow::handlePropertyCellChanged(int r, int c)
{
    if ( c != 1 ) return;

    IAttribute * attr;

    QString key = propertyTable->item(r,0)->text();
    QString value = propertyTable->item(r,1)->text();

    SCState * state = dynamic_cast<SCState*>(_currentlySelected);
    if ( state != NULL )
    {
        attr = state->attributes.value(key);
    }
    else
    {
        SCTransition * transition = dynamic_cast<SCTransition*>(_currentlySelected);
        if ( transition == NULL) return;

        attr = transition->attributes.value(key);
    }


    attr->setValue(value);

}


// recursively walk through the state tree and build the tree view

void FormEditorWindow::loadTree ( CustomTreeWidgetItem * parentItem , QList<SCState*> & states)
{

    int c = states.count();

    for(int i = 0; i < c; i++)
    {
        SCState * st = states.at(i);

        if ( !  st ) continue;

        CustomTreeWidgetItem * item=0;

        if (parentItem == 0)
        {
            item = new CustomTreeWidgetItem();
            stateChartTreeView->addTopLevelItem((QTreeWidgetItem*)item);
        }
        else
        {
            item = new CustomTreeWidgetItem(parentItem);
        }


        item->setData( st);

        item->setText(0, st->attributes.value("name")->asString());

        // get all transitions in this state
        QList<SCTransition*> transitions;

        st->getTransitions(transitions);

        loadTree (item, transitions);

        // get all substates of this state
        QList<SCState*> subStates;

        st->getStates(subStates);

        loadTree (item, subStates);

    }

}

void FormEditorWindow::loadTree ( CustomTreeWidgetItem * parentItem , QList<SCTransition*> & transitions)
{

    int c = transitions.count();

    for(int i = 0; i < c; i++)
    {
        SCTransition * tr = transitions.at(i);

        if ( !  tr ) continue;

        CustomTreeWidgetItem * item=0;

        item = new CustomTreeWidgetItem(parentItem);

        item->setData( tr);

        item->setText(0, tr->attributes.value("target")->asString());

    }

}


IAttributeContainer * FormEditorWindow::getCurrentlySelectedAttributes()
{
    IAttributeContainer * attributes;
    SCState * st = dynamic_cast<SCState *>(  _currentlySelected );
    if ( st!= NULL)
    {
        _currentlySelected = st;
        attributes =  & st->attributes;
    }
    else
    {
        SCTransition * transition = dynamic_cast<SCTransition *>(  _currentlySelected );
        if ( transition == NULL) return NULL;
        _currentlySelected = transition;
        attributes =  & transition->attributes;
    }

    return attributes;
}

QString FormEditorWindow::getCurrentlySelectedTitle()
{
    QString title;

    IAttributeContainer * attributes;
    SCState * st = dynamic_cast<SCState *>(  _currentlySelected );
    if ( st!= NULL)
    {
        attributes =  & st->attributes;
        IAttribute* attr = attributes->value("name")  ;
        title = attr->asString();

    }
    else
    {
        SCTransition * transition = dynamic_cast<SCTransition *>(  _currentlySelected );
        if ( transition == NULL) QString("programming error getCurrentlySelectedTitle ");
        attributes =  & transition->attributes;
        IAttribute* attr = attributes->value("target")  ;
        title = attr->asString();
    }

    return title;
}

QString FormEditorWindow::getCurrentlySelectedType()
{


    SCState * st = dynamic_cast<SCState *>(  _currentlySelected );
    if ( st!= NULL)
    {
        return QString("State");
    }
    else
    {
        SCTransition * transition  = dynamic_cast<SCTransition *>(  _currentlySelected );
        if ( transition == NULL) return QString("programming error getCurrentlySelectedType ");
        return QString("Transition");
    }
}

void FormEditorWindow::handleTreeViewItemClicked(QTreeWidgetItem* qitem,int )
{

    CustomTreeWidgetItem * item = dynamic_cast<CustomTreeWidgetItem*>(qitem);

    // display the type : State or Transition
    // display the name of the item
    // load its attributes in the table

    int row = 0;

    _currentlySelected =  item->data();

    // load the Title

    QString selectedItemTitle = getCurrentlySelectedType()  + " : " +  getCurrentlySelectedTitle();

    selectedChartItem->setText(selectedItemTitle );


    // clear the tabel, delete the old table items
    for (int r =0; r <propertyTable->rowCount(); r++ )
    {
        QTableWidgetItem * item = propertyTable->itemAt(r,0);
        delete item;
        item = propertyTable->itemAt(r,1);
        delete item;
    }

    propertyTable->clear();


    // load the new attributes

    IAttributeContainer * attributes =  getCurrentlySelectedAttributes();


    disconnect(propertyTable, SIGNAL(cellChanged(int,int)), this, SLOT(handlePropertyCellChanged(int,int)));

    propertyTable->setRowCount(attributes->count());

    QMapIterator<QString,IAttribute*> i(*attributes);
    while (i.hasNext())
    {
        QString key  = i.next().key();
        IAttribute* attr = attributes->value(key)  ;

        connect ( attr, SIGNAL(changed(IAttribute*)), this, SLOT(handlePropertyChanged(IAttribute*)));

        QTableWidgetItem * propName = new QTableWidgetItem(key);

        propName->setFlags( (propName->flags() & (~Qt::ItemIsEditable)) | ((Qt::ItemIsEnabled)));

        QTableWidgetItem * propValue = new QTableWidgetItem(attr->asString());

        propValue->setFlags(propValue->flags() | (Qt::ItemIsEditable) | (Qt::ItemIsEnabled));

        propertyTable->setItem(row, 0, propName);
        propertyTable->setItem(row++, 1, propValue);

    }

    connect(propertyTable, SIGNAL(cellChanged(int,int)), this, SLOT(handlePropertyCellChanged(int,int)));


}

void FormEditorWindow::handlePropertyChanged(IAttribute *attr)
{
    for (int r =0; r <propertyTable->rowCount(); r++ )
    {
        QString txt = propertyTable->item(r,0)->text();
        QString key = attr->key() ;

        if (  txt == key )
        {
            propertyTable->item(r,1)->setText( attr->asString() );
        }
    }
}

void FormEditorWindow::backgroundButtonGroupClicked(QAbstractButton *button)
{

}


void FormEditorWindow::buttonGroupClicked(int id)
{

}


void FormEditorWindow::deleteItem()
{

}


void FormEditorWindow::pointerGroupClicked(int)
{

}


void FormEditorWindow::bringToFront()
{

}

void FormEditorWindow::insertTransition()
{
    SCState * st = dynamic_cast<SCState *> (_currentlySelected);

    if ( st == NULL ) return;

    dm->insertNewTransition(st,"test event");

}

void FormEditorWindow::insertState()
{

}

void FormEditorWindow::sendToBack()
{

}




void FormEditorWindow::textInserted(QGraphicsTextItem *)
{

}


void FormEditorWindow::currentFontChanged(const QFont &)
{

}


void FormEditorWindow::fontSizeChanged(const QString &)
{

}


void FormEditorWindow::sceneScaleChanged(const QString &scale)
{

}


void FormEditorWindow::textColorChanged()
{

}


void FormEditorWindow::itemColorChanged()
{

}


void FormEditorWindow::lineColorChanged()
{

}


void FormEditorWindow::textButtonTriggered()
{

}


void FormEditorWindow::fillButtonTriggered()
{

}





void FormEditorWindow::lineButtonTriggered()
{

}


void FormEditorWindow::handleFontChange()
{

}




void FormEditorWindow::about()
{
    QMessageBox::about(this, tr("About Visual State Chart"),
                       tr("<b>VisualSC</b>  is a State Chart Editor "
                          "which read/writes from/to SCXML"));
}




void FormEditorWindow::createActions()
{
    insertStateAction = new QAction(QIcon(":/FormEditorWindow/statebutton.bmp"), tr("Insert State"), this);
    insertStateAction->setShortcut(tr("Ctrl+I"));
    insertStateAction->setStatusTip(tr("Insert State"));
    connect(insertStateAction, SIGNAL(triggered()), this, SLOT(insertState()));


    insertTransitionAction = new QAction(QIcon(":/FormEditorWindow/transitionbutton.bmp"), tr("Insert Transition"), this);
    insertTransitionAction->setShortcut(tr("Ctrl+I"));
    insertTransitionAction->setStatusTip(tr("Insert Transition"));
    connect(insertTransitionAction, SIGNAL(triggered()), this, SLOT(insertTransition()));


    toFrontAction = new QAction(QIcon(":/FormEditorWindow/bringtofront.png"),
                                tr("Bring to &Front"), this);
    toFrontAction->setShortcut(tr("Ctrl+F"));
    toFrontAction->setStatusTip(tr("Bring item to front"));
    connect(toFrontAction, SIGNAL(triggered()), this, SLOT(bringToFront()));


    sendBackAction = new QAction(QIcon(":/FormEditorWindow/sendtoback.png"),
                                 tr("Send to &Back"), this);
    sendBackAction->setShortcut(tr("Ctrl+B"));
    sendBackAction->setStatusTip(tr("Send item to back"));
    connect(sendBackAction, SIGNAL(triggered()), this, SLOT(sendToBack()));

    deleteAction = new QAction(QIcon(":/FormEditorWindow/delete.png"),
                               tr("&Delete"), this);
    deleteAction->setShortcut(tr("Delete"));
    deleteAction->setStatusTip(tr("Delete item from diagram"));
    connect(deleteAction, SIGNAL(triggered()), this, SLOT(deleteItem()));

    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcuts(QKeySequence::Quit);
    exitAction->setStatusTip(tr("Quit VisualSC Editor"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    boldAction = new QAction(tr("Bold"), this);
    boldAction->setCheckable(true);
    QPixmap pixmap(":/FormEditorWindow/bold.png");
    boldAction->setIcon(QIcon(pixmap));
    boldAction->setShortcut(tr("Ctrl+B"));
    connect(boldAction, SIGNAL(triggered()), this, SLOT(handleFontChange()));

    italicAction = new QAction(QIcon(":/FormEditorWindow/italic.png"),   tr("Italic"), this);
    italicAction->setCheckable(true);
    italicAction->setShortcut(tr("Ctrl+I"));
    connect(italicAction, SIGNAL(triggered()), this, SLOT(handleFontChange()));

    underlineAction = new QAction(QIcon(":/FormEditorWindow/underline.png"),  tr("Underline"), this);
    underlineAction->setCheckable(true);
    underlineAction->setShortcut(tr("Ctrl+U"));
    connect(underlineAction, SIGNAL(triggered()), this, SLOT(handleFontChange()));

    aboutAction = new QAction(tr("A&bout"), this);
    aboutAction->setShortcut(tr("Ctrl+B"));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
}



void FormEditorWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(exitAction);

    itemMenu = menuBar()->addMenu(tr("&Item"));
    itemMenu->addAction(deleteAction);
    itemMenu->addSeparator();
    itemMenu->addAction(toFrontAction);
    itemMenu->addAction(sendBackAction);
    itemMenu->addAction(insertTransitionAction);
    itemMenu->addAction(insertStateAction);

    aboutMenu = menuBar()->addMenu(tr("&Help"));
    aboutMenu->addAction(aboutAction);
}


void FormEditorWindow::createToolbars()
{


    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(deleteAction);
    editToolBar->addAction(toFrontAction);
    editToolBar->addAction(sendBackAction);
    editToolBar->addAction(insertTransitionAction);
    editToolBar->addAction(insertStateAction);

    fontCombo = new QFontComboBox();
    connect(fontCombo, SIGNAL(currentFontChanged(QFont)),
            this, SLOT(currentFontChanged(QFont)));

    fontSizeCombo = new QComboBox;
    fontSizeCombo->setEditable(true);
    for (int i = 8; i < 30; i = i + 2)
        fontSizeCombo->addItem(QString().setNum(i));
    QIntValidator *validator = new QIntValidator(2, 64, this);
    fontSizeCombo->setValidator(validator);
    connect(fontSizeCombo, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(fontSizeChanged(QString)));

    fontColorToolButton = new QToolButton;
    fontColorToolButton->setPopupMode(QToolButton::MenuButtonPopup);
    fontColorToolButton->setMenu(createColorMenu(SLOT(textColorChanged()),
                                                 Qt::black));
    textAction = fontColorToolButton->menu()->defaultAction();
    fontColorToolButton->setIcon(createColorToolButtonIcon(
            ":/FormEditorWindow/textpointer.png", Qt::black));
    fontColorToolButton->setAutoFillBackground(true);
    connect(fontColorToolButton, SIGNAL(clicked()),
            this, SLOT(textButtonTriggered()));



    fillColorToolButton = new QToolButton;
    fillColorToolButton->setPopupMode(QToolButton::MenuButtonPopup);
    fillColorToolButton->setMenu(createColorMenu(SLOT(itemColorChanged()),
                                                 Qt::white));
    fillAction = fillColorToolButton->menu()->defaultAction();
    fillColorToolButton->setIcon(createColorToolButtonIcon(
            ":/FormEditorWindow/floodfill.png", Qt::white));
    connect(fillColorToolButton, SIGNAL(clicked()),
            this, SLOT(fillButtonTriggered()));



    lineColorToolButton = new QToolButton;
    lineColorToolButton->setPopupMode(QToolButton::MenuButtonPopup);
    lineColorToolButton->setMenu(createColorMenu(SLOT(lineColorChanged()),
                                                 Qt::black));
    lineAction = lineColorToolButton->menu()->defaultAction();
    lineColorToolButton->setIcon(createColorToolButtonIcon(
            ":/FormEditorWindow/linecolor.png", Qt::black));
    connect(lineColorToolButton, SIGNAL(clicked()),
            this, SLOT(lineButtonTriggered()));

    textToolBar = addToolBar(tr("Font"));
    textToolBar->addWidget(fontCombo);
    textToolBar->addWidget(fontSizeCombo);
    textToolBar->addAction(boldAction);
    textToolBar->addAction(italicAction);
    textToolBar->addAction(underlineAction);

    colorToolBar = addToolBar(tr("Color"));
    colorToolBar->addWidget(fontColorToolButton);
    colorToolBar->addWidget(fillColorToolButton);
    colorToolBar->addWidget(lineColorToolButton);

    QToolButton *pointerButton = new QToolButton;
    pointerButton->setCheckable(true);
    pointerButton->setChecked(true);
    pointerButton->setIcon(QIcon(":/FormEditorWindow/pointer.png"));
    QToolButton *linePointerButton = new QToolButton;
    linePointerButton->setCheckable(true);
    linePointerButton->setIcon(QIcon(":/FormEditorWindow/linepointer.png"));

    pointerTypeGroup = new QButtonGroup(this);
    pointerTypeGroup->addButton(pointerButton, int(0));
    pointerTypeGroup->addButton(linePointerButton,
                                int(1));
    connect(pointerTypeGroup, SIGNAL(buttonClicked(int)),
            this, SLOT(pointerGroupClicked(int)));

    sceneScaleCombo = new QComboBox;
    QStringList scales;
    scales << tr("50%") << tr("75%") << tr("100%") << tr("125%") << tr("150%");
    sceneScaleCombo->addItems(scales);
    sceneScaleCombo->setCurrentIndex(2);
    connect(sceneScaleCombo, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(sceneScaleChanged(QString)));

    pointerToolbar = addToolBar(tr("Pointer type"));
    pointerToolbar->addWidget(pointerButton);
    pointerToolbar->addWidget(linePointerButton);
    pointerToolbar->addWidget(sceneScaleCombo);


}





QMenu *FormEditorWindow::createColorMenu(const char *slot, QColor defaultColor)
{
    QList<QColor> colors;
    colors << Qt::black << Qt::white << Qt::red << Qt::blue << Qt::yellow;
    QStringList names;
    names << tr("black") << tr("white") << tr("red") << tr("blue")
            << tr("yellow");

    QMenu *colorMenu = new QMenu(this);
    for (int i = 0; i < colors.count(); ++i) {
        QAction *action = new QAction(names.at(i), this);
        action->setData(colors.at(i));
        action->setIcon(createColorIcon(colors.at(i)));
        connect(action, SIGNAL(triggered()),
                this, slot);
        colorMenu->addAction(action);
        if (colors.at(i) == defaultColor) {
            colorMenu->setDefaultAction(action);
        }
    }
    return colorMenu;
}


QIcon FormEditorWindow::createColorToolButtonIcon(const QString &imageFile,
                                                  QColor color)
{
    QPixmap pixmap(50, 80);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    QPixmap image(imageFile);
    QRect target(0, 0, 50, 60);
    QRect source(0, 0, 42, 42);
    painter.fillRect(QRect(0, 60, 50, 80), color);
    painter.drawPixmap(target, image, source);

    return QIcon(pixmap);
}


QIcon FormEditorWindow::createColorIcon(QColor color)
{
    QPixmap pixmap(20, 20);
    QPainter painter(&pixmap);
    painter.setPen(Qt::NoPen);
    painter.fillRect(QRect(0, 0, 20, 20), color);

    return QIcon(pixmap);
}
