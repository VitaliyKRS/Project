 #include "sqlite.h"
#include <QSqlError>
Sqlite::Sqlite()
{
   m_db = QSqlDatabase::addDatabase("QSQLITE");
   m_db.setDatabaseName("Data.sqlite");
   if (!m_db.open()){
       qDebug()<<"Fail";
   }

}

Sqlite::~Sqlite()
{

}

QAbstractTableModel* Sqlite::loadData()
{
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(m_db);
    qry->prepare("SELECT * FROM Data");
    qry->exec();
    modal->setQuery(*qry);
    return modal;

}

QAbstractTableModel* Sqlite::sorting(int column)
{
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(m_db);
    switch (column) {
    case 0:{
        qry->prepare("select * from Data order by \"Group\"");
        qry->exec();
        modal->setQuery(*qry);
        return modal;
    }
    case 1:{
        qry->prepare("select * from Data order by Name");
        qry->exec();
        modal->setQuery(*qry);
        return modal;
    }
    case 2:{
        qry->prepare("select * from Data order by \"Gradebook Number\"");
        qry->exec();
        modal->setQuery(*qry);
        return modal;
    }
    case 3:{
        qry->prepare("select * from Data order by Maths DESC");
        qry->exec();
        modal->setQuery(*qry);
        return modal;
    }
    case 4:{
        qry->prepare("select * from Data order by Drawing DESC");
        qry->exec();
        modal->setQuery(*qry);
        return modal;
    }
    case 5:{
        qry->prepare("select * from Data order by Literature DESC");
        qry->exec();
        modal->setQuery(*qry);
        return modal;
    }
    }
    return nullptr;
}

QAbstractTableModel*Sqlite::filtrationByGroup(int column)
{
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(m_db);
    switch (column) {
    case 0:{
        qry->prepare("select * from Data where \"Group\"  = 'uk-61'");
        qry->exec();
        modal->setQuery(*qry);
        return modal;
    }
    case 1:{
        qry->prepare("select * from Data where \"Group\"  = 'uk-71'");
        qry->exec();
        modal->setQuery(*qry);
        return modal;
    }
    case 2:{
        qry->prepare("select * from Data where \"Group\"  = 'uk-72'");
        qry->exec();
        modal->setQuery(*qry);
        return modal;
    }
    case 3:{
        qry->prepare("select * from Data where \"Group\"  = 'uk-81'");
        qry->exec();
        modal->setQuery(*qry);
        return modal;
    }
    }
    return nullptr;
}

QAbstractTableModel* Sqlite::filtrationBetween(int column,int firstval, int secondval)
{
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(m_db);
    switch (column) {
    case 0:{
        qry->prepare("select * from Data where Maths between "+ QString::number(firstval) +" and "+QString::number(secondval));
        qry->exec();
        modal->setQuery(*qry);
        return modal;
    }
    case 1:{
       qry->prepare("select * from Data where Drawing between "+ QString::number(firstval) +" and "+QString::number(secondval));
       qry->exec();
        modal->setQuery(*qry);
        return modal;
    }
    case 2:{
        qry->prepare("select * from Data where Literature between "+ QString::number(firstval) +" and "+QString::number(secondval));
        qry->exec();
        modal->setQuery(*qry);
        return modal;
    }
    }
    return nullptr;
}

QAbstractTableModel* Sqlite::filtrationbyName(QString name)
{
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(m_db);
    qry->prepare("select * from Data where Name like '"+name+"%'");
    qry->exec();
    modal->setQuery(*qry);
    return modal;
}

