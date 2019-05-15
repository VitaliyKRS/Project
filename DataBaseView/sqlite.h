#ifndef SQLITE_H
#define SQLITE_H
#include "idata.h"
class Sqlite : public IData
{
public:
    Sqlite();
    ~Sqlite()override;
    QAbstractTableModel* loadData() Q_DECL_OVERRIDE;
    QAbstractTableModel* sorting(int column) Q_DECL_OVERRIDE;
    QAbstractTableModel* filtrationByGroup(int column) Q_DECL_OVERRIDE;
    QAbstractTableModel* filtrationBetween(int column,int firstval,int secondval) Q_DECL_OVERRIDE;
    QAbstractTableModel* filtrationbyName(QString name) Q_DECL_OVERRIDE;
private:
    QSqlDatabase m_db;
};


#endif // SQLITE_H
