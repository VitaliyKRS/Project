#ifndef IDATA_H
#define IDATA_H
#include <QAbstractTableModel>
#include <QSqlDatabase>
#include <QDebug>
#include <QTableView>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "mydelegatethatpaintsred.h"

class IData{
public:
    IData(){}
    virtual QAbstractTableModel* loadData() = 0;
    virtual QAbstractTableModel* sorting(int) = 0;
    virtual QAbstractTableModel* filtrationByGroup(int) =0;
    virtual QAbstractTableModel* filtrationBetween(int,int,int) = 0;
    virtual QAbstractTableModel* filtrationbyName(QString)=0;
    virtual ~IData() {}
};

#endif // IDATA_H
