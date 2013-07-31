#include <QtWidgets>
#include "uicell.h"
#include <iostream>
#include <cell.h>

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
            //**************************************
            //cout<<"******************"<<endl;
            //cout<<"value"<<value().toString().toStdString()<<endl;
            //cout<<"formula"<<formula().toStdString()<<endl;
            return value().toString();
         }else {
            //cout<<"value- "<<value().toString().toStdString()<<endl;
            //cout<<"formula--"<<formula().toStdString()<<endl;
           return "######";}
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
    /*
        QString formulaStr = formula();
        if (formulaStr.startsWith('='))
            cachedValue = formulaStr.mid(1);
        else
            cachedValue = formulaStr;

        //UICell *c = static_cast<UICell *>(this->tableWidget()->item(row, column));
    this->tableWidget();*/

   // cout<<"type "<<currentCell->getType()<<endl;
    currentCell->setExpression(formula().toStdString());
    cout<<"type "<<currentCell->getType()<<endl;
   if(this->currentCell->getType()==TEXT){
   //if(formula().toStdString()==""){
        cachedValue=formula();
    }
    else {
    currentCell->setExpression(formula().toStdString());
    cachedValue=this->currentCell->getValue();
    }
    return cachedValue;
}

void UICell::setValue(QVariant v){
    cachedValue=v;
    cout<<"set valueeeee a "<<endl;
}

void UICell::setValue(QString v){
    cachedValue=v;
    cout<<"set valueeeee a "<<endl;
}

void UICell::setCell(cell*c){
    currentCell=c;
}

/*
QVariant UICell::evalExpression(const QString &str, int &pos) const
{
    QVariant result = evalTerm(str, pos);
    while (str[pos] != QChar::Null) {
        QChar op = str[pos];
        if (op != '+' && op != '-')
            return result;
        ++pos;

        QVariant term = evalTerm(str, pos);
        if (result.type() == QVariant::Double
                && term.type() == QVariant::Double) {
            if (op == '+') {
                result = result.toDouble() + term.toDouble();
            } else {
                result = result.toDouble() - term.toDouble();
            }
        } else {
            result = Invalid;
        }
    }
    return result;
}
*/

/*
QVariant UICell::evalTerm(const QString &str, int &pos) const
{
    QVariant result = evalFactor(str, pos);
    while (str[pos] != QChar::Null) {
        QChar op = str[pos];
        if (op != '*' && op != '/')
            return result;
        ++pos;

        QVariant factor = evalFactor(str, pos);
        if (result.type() == QVariant::Double
                && factor.type() == QVariant::Double) {
            if (op == '*') {
                result = result.toDouble() * factor.toDouble();
            } else {
                if (factor.toDouble() == 0.0) {
                    result = Invalid;
                } else {
                    result = result.toDouble() / factor.toDouble();
                }
            }
        } else {
            result = Invalid;
        }
    }
    return result;
}
*/

/*
QVariant UICell::evalFactor(const QString &str, int &pos) const
{
    QVariant result;
    bool negative = false;

    if (str[pos] == '-') {
        negative = true;
        ++pos;
    }

    if (str[pos] == '(') {
        ++pos;
        result = evalExpression(str, pos);
        if (str[pos] != ')')
            result = Invalid;
        ++pos;
    } else {
        QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
        QString token;

        while (str[pos].isLetterOrNumber() || str[pos] == '.') {
            token += str[pos];
            ++pos;
        }

        if (regExp.exactMatch(token)) {
            int column = token[0].toUpper().unicode() - 'A';
            int row = token.mid(1).toInt() - 1;

            UICell *c = static_cast<UICell *>(
                              tableWidget()->item(row, column));
            if (c) {
                result = c->value();
            } else {
                result = 0.0;
            }
        } else {
            bool ok;
            result = token.toDouble(&ok);
            if (!ok)
                result = Invalid;
        }
    }

    if (negative) {
        if (result.type() == QVariant::Double) {
            result = -result.toDouble();
        } else {
            result = Invalid;
        }
    }
    return result;
}
*/
