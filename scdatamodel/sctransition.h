/*
    visualsc - Visual State Chart Editing for SCXML State Engines
    Copyright (C) 2011  David W. Drell (david@davidwdrell.net) and
    Contributing Authors:


    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SCTRANSISTION_H
#define SCTRANSISTION_H

#include "transitionattributes.h"
#include <QObject>
#include <QList>
#include <QPointF>
class SCState;
#include "scdatamodel_global.h"
class QXmlStreamWriter;
#include "scitem.h"

/**

  \class   SCTransition
  \ingroup DataModel
  \brief   The class represents a transition in a state-chart Data-Model

  The transition does not contain children elements. The transiton does contain a public attribute container as
  well as convenience methods to accessing the attributes. Since te attribute container is public,
  attributes can be accessed directly.

  The transition holds a reference to the target state.

  */

class SCDATAMODELSHARED_EXPORT  SCTransition : public SCItem
{
    Q_OBJECT

public:
    SCTransition(QObject * parent);

    ~SCTransition();

    virtual IAttributeContainer * getAttributes(); //reimplemented from base SCItem
    void    setAttributeValue(QString key, QString value);
    QString getAttributeValue(QString key);
    void    writeSCVXML(QXmlStreamWriter & sw);
    SCState *targetState();

     //public data members

    TransitionAttributes attributes;

signals:
    void selected();
    void unselected();

private slots:
    void handleLineSelected();
    void handleLineUnSelected();

private:

    SCState *       _targetState;

};


#endif // SCTRANSISTION_H
