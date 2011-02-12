#ifndef SCTRANSISTION_H
#define SCTRANSISTION_H

#include "transitionattributes.h"
#include <QObject>
#include <QList>
#include <QPointF>

#include "scdatamodel_global.h"

class SCDATAMODELSHARED_EXPORT  SCTransition : public QObject
{
    Q_OBJECT

public:
    SCTransition(QObject * parent);
    ~SCTransition();

    void setPath(QList<QPointF> & path);
    void setAttributes ( TransitionAttributes & ta);

    QString event;
    QString cond;
    QString target;
    TransitionAttributes::TRANSISTION_TYPE type;


signals:
    void selected();
    void unselected();

private slots:
    void handleLineSelected();
    void handleLineUnSelected();

private:

    TransitionAttributes _attributes;
    QList<QPointF>  _path;

};

#endif // SCTRANSISTION_H
