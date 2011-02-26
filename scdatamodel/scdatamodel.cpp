#include "scdatamodel.h"
#include <QFile>
#include <QDebug>
#include <QStandardItemModel>
#include <QMapIterator>

SCDataModel::SCDataModel(QObject * parent) :
        QObject (parent), _reader(), _writer(0), _level(0),_topLevel(0),
        _currentState(NULL), _currentTransition(NULL),_topState(NULL),
        _qtDM(0)
{
    _qtDM = new QStandardItemModel(this);

    // TODO destructor
}

QStandardItemModel * SCDataModel::getStandardModel()
{
    return _qtDM;
}

QStandardItem * SCDataModel::makeAStateItem(SCState *st)
{

    QStandardItem * item = new QStandardItem(0,1);
    QString name = st->attributes.value("name")->asString();
    item->setData( name, Qt::UserRole );

    return item;
}

QStandardItem * SCDataModel::makeATransitionItem(SCTransition *tr)
{

    QStandardItem * item = new QStandardItem(0,0);

    return item;

}


bool SCDataModel::save(QString fileName, QString& errorMessage)
{


    QFile file(fileName);

    if ( ! file.open(QIODevice::WriteOnly))
    {
        errorMessage = QString("error opening file for write");
        return false;
    }

    _writer = new QXmlStreamWriter(&file);

    _writer->setAutoFormatting(true);

    _writer->writeStartDocument();
    _writer->writeStartElement("scxml");
    _writer->writeAttribute("xmlns", "http://www.w3.org/2005/07/scxml");

    _topState->writeSCVXML( *_writer );

    _writer->writeEndDocument();

    file.close();

    errorMessage = QString("sucess");
    return true;
}

void SCDataModel::open(QString file)
{

    connect(&_reader, SIGNAL(done(bool, QStringList)), this, SLOT(handleReaderDone(bool, QStringList)));

    connect(&_reader, SIGNAL(makeANewState(StateAttributes*)), this, SLOT(handleMakeANewState(StateAttributes*)));
    connect(&_reader, SIGNAL(enterStateElement()), this, SLOT(handleTransitDown()));
    connect(&_reader, SIGNAL(leaveStateElement()), this, SLOT(handleTransitUp()));

    connect(&_reader, SIGNAL(makeANewTransistion(TransitionAttributes*)), this, SLOT(handleMakeANewTransition(TransitionAttributes*)));
    connect(&_reader, SIGNAL(leaveTransistionElement()), this, SLOT(handleLeaveTransitionElement()));
    connect(&_reader, SIGNAL(makeANewTransistionPath(TransitionPathAttribute*)), this, SLOT(handleMakeANewTransitionPath(TransitionPathAttribute*)));

    _reader.readFile(file);
    _reader.start();
}


void SCDataModel::getStates(QList<SCState *>& list)
{
    if ( _topState == NULL ) list = QList<SCState *>();

    return _topState->getStates(list);
}


SCState * SCDataModel::getStateByName(QString name)
{
    QList<SCState *> list;
    _topState->getAllStates(list);

    for(int i =0; i < list.count(); i++)
    {
        SCState *st = list.at(i);
        if ( st->attributes.value("name")->asString() == name)
            return st;
    }
    return NULL;
}


void SCDataModel::getAllStates(QList<SCState *>& list)
{
    return _topState->getAllStates(list);
}

void SCDataModel::handleTransitDown()
{
    _level ++;
    qDebug() << "down level = " + QString::number(_level);
}

void SCDataModel::handleTransitUp()
{
    _level --;

    qDebug() << "up level = " + QString::number(_level);

    if ( ! _currentState ) return;


    if (_currentState->parent())
        _currentState = dynamic_cast<SCState*> (_currentState->parent());
}

void SCDataModel::handleMakeANewState(StateAttributes*  sa)
{
    SCState * state = NULL;

    if ( _currentState == 0)
        _topLevel = _level;

    if ( _topLevel == _level )
    {
        state = new SCState();
        state->setObjectName( sa->value("name")->asString() );
        _topState = state;

        sa->setParent(state);
        state->attributes.setAttributes( *sa);

        // insert the new state into the Qt Data Model

        QStandardItem * root = _qtDM->invisibleRootItem();
        QStandardItem * thisItem = makeAStateItem(state);
        root->appendRow( thisItem );
        state->setParentItem(root);
        state->setItem (thisItem);


        qDebug() << "adding new state at top level : " + sa->value("name")->asString();
    }
    else if ( _level > _topLevel)
    {
        state = new SCState(_currentState);
        state->setObjectName( sa->value("name")->asString() );
        sa->setParent(state);
        state->attributes.setAttributes( *sa);


        // insert the new state into the Qt Data Model

        QStandardItem * parent = _currentState->getItem();
        QStandardItem * thisItem = makeAStateItem(state);
        state->setItem (thisItem);
        parent->appendRow( thisItem );

        qDebug() << "adding state at level  :" + QString::number(_level) + ", name : " + sa->value("name")->asString();
    }



    _currentState  = state;

    emit newStateSignal(state);


    // clean up memory for passed in attributes

    QMapIterator<QString,IAttribute*> i(*sa);
    while (i.hasNext())
    {
        QString key  = i.next().key();
        IAttribute* sourceAttr = sa->value(key)  ;
        delete sourceAttr;
    }
    delete sa;

}



void SCDataModel::handleMakeANewTransition(TransitionAttributes * ta)
{
    qDebug() << "handleMakeANewTransition, : "  + ta->value("target")->asString();

    SCTransition * transition = new SCTransition(_currentState);

    if ( _currentState == 0)
        return;

    transition->attributes.setAttributes(*ta);

    _currentTransition = transition;
    _currentState->addTransistion(transition);


    // clean up memory for passed in attributes

    QMapIterator<QString,IAttribute*> i(*ta);
    while (i.hasNext())
    {
        QString key  = i.next().key();
        IAttribute* sourceAttr = ta->value(key)  ;
        delete sourceAttr;
    }

    delete ta;

    emit newTransitionSignal(_currentTransition);

}

void SCDataModel::handleLeaveTransitionElement()
{
    qDebug() << "handleLeaveTransitionElement ";

    //    _currentTransition->creationDone();


}

void SCDataModel::handleMakeANewTransitionPath ( TransitionAttributes::TransitionPathAttribute * tp)
{

    qDebug() << "handleMakeANewTransitionPath : " ;

    if ( _currentState == 0)
        return;

    if ( _currentTransition == 0 ) return;

    TransitionAttributes::TransitionPathAttribute *path =
            dynamic_cast<TransitionAttributes::TransitionPathAttribute *>( _currentTransition->attributes.value("path"));

    path->setValue( tp->asString());

}

void SCDataModel::handleReaderDone(bool sucess, QStringList message)
{

    if ( ! sucess )
    {
        emit openCompleted ( sucess, message);
        return;
    }
    // connect transistions to target states

    QList<SCTransition*> * masterTransistionList = new QList<SCTransition*>();


    // first query all states for their originating transitions
    // and make a master list
    _topState->getAllTransitions(*masterTransistionList);


    // second, pass the master list to all states/substates so they
    // can look up themselves in the target fields and make the target
    // connections

    //_topState->makeTargetConnections( * masterTransistionList);

    delete masterTransistionList;

    message.append(QString("sucessfully linked transitions"));

    emit openCompleted ( sucess, message);

}

