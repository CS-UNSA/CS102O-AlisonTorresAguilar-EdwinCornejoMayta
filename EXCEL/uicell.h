#ifndef UICELL_H
#define UICELL_H

#include <QTableWidgetItem>
#include "definedtypes.h"
class cell;
class UISpreadsheet;
class UICell : public QTableWidgetItem
{
public:
    /**
     * @brief UICell
     */
    UICell();

    /**
     * @brief clone
     * @return
     */
    QTableWidgetItem *clone() const;

    /**
     * @brief setData
     * @param role
     * @param value
     */
    void setData(int role, const QVariant &value);

    /**
     * @brief data
     * @param role
     * @return
     */
    QVariant data(int role) const;

    /**
     * @brief setFormula
     * @param formula
     */
    void setFormula(const QString &formula);

    /**
     * @brief formula
     * @return
     */
    QString formula() const;

    /**
     * @brief setDirty
     */
    void setDirty();

    /**
     * @brief setValue
     */
    void setValue(QVariant);

    /**
     * @brief setValue
     */
    void setValue(QString);

    /**
     * @brief value
     * @return
     */
    QVariant value() const;

    /**
     * @brief setCell
     * @param c
     */
    void setCell(cell*c);

    void update();

    inline void setWidget(UISpreadsheet *w){widget=w;}

private:

    mutable QVariant cachedValue;
    mutable bool cacheIsDirty;
    UISpreadsheet *widget;
    cell* currentCell;

};


#endif // UICELL_H
