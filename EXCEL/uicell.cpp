#include <QtWidgets>
#include "uicell.h"
#include <iostream>
#include <cell.h>
#include <QApplication>
#include <QMessageBox>
#include <QInputDialog>
#include <QIcon>
#include "uispreadsheet.h"
using namespace std;
UICell::UICell()
{
    setDirty();
}

QTableWidgetItem *UICell::clone() const
{
    return new UICell(*this);
}

void UICell::setData(int role, const QVariant &value)
{
    QTableWidgetItem::setData(role, value);
    if (role == Qt::EditRole)
        setDirty();

}

QVariant UICell::data(int role) const
{
    if (role == Qt::DisplayRole) {
       if (value().isValid()) {
         // cout<<"value ****************"<<value().toString().toStdString()<<endl;
        //  currentCell->update();
        //   this->QTableWidgetItem.

           return value().toString();

         }else {
           return "######";
    }
    } else if (role == Qt::TextAlignmentRole) {
        if (value().type() == QVariant::String) {
            return int(Qt::AlignLeft | Qt::AlignVCenter);
        } else {
            return int(Qt::AlignRight | Qt::AlignVCenter);
        }
    } else {
        return QTableWidgetItem::data(role);
    }
}

void UICell::setFormula(const QString &formula)
{
    setData(Qt::EditRole, formula);
}

QString UICell::formula() const
{
    return data(Qt::EditRole).toString();

}

void UICell::setDirty()
{
    cacheIsDirty = true;
}

const QVariant Invalid;

QVariant UICell::value() const
{
  try {
        currentCell->setExpression(formula().toStdString());
        if(this->currentCell->getType()==TEXT){
            cachedValue=formula();
        }
        else {
        currentCell->setExpression(formula().toStdString());
        cachedValue=this->currentCell->getValue();
        cout<<formula().toStdString()<<endl;

    }

    }catch(const char* msg){
   cerr << msg << endl;
  // const QString m=QObject::tr(msg);

 //  widget->messageToShow(QObject:: tr (msg));
 /*  QMessageBox::information(widget,QObject::tr("Spreadsheet"),
          QObject:: tr ("The information cannot be pasted because the copy "
              "and paste areas aren't the same size."));
   return cachedValue;*/
   }
    return cachedValue;
}

void UICell::update()
{
    currentCell->update();
}

void UICell::setValue(QVariant v){
    cachedValue=v;
}

void UICell::setValue(QString v){
    cachedValue=v;
}

void UICell::setCell(cell*c){
    currentCell=c;
}


