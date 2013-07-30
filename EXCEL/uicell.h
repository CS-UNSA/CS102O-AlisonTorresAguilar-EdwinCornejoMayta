#ifndef UICELL_H
#define UICELL_H

#include <QTableWidgetItem>

class cell;
class UICell : public QTableWidgetItem
{
public:
    UICell();

    QTableWidgetItem *clone() const;
    void setData(int role, const QVariant &value);
    QVariant data(int role) const;
    void setFormula(const QString &formula);
    QString formula() const;
    void setDirty();
    void setValue(QVariant);
    void setValue(QString);
    QVariant value() const;
    void setCell(cell*c);
private:
   //QVariant value() const;
   //QVariant evalExpression(const QString &str, int &pos) const;
   //QVariant evalTerm(const QString &str, int &pos) const;
   //QVariant evalFactor(const QString &str, int &pos) const;
   //QVariant value;
    mutable QVariant cachedValue;
    mutable bool cacheIsDirty;
    cell* currentCell;
};


#endif // UICELL_H
