#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QStatusBar>
#include "idata.h"
#include "sqlite.h"
#include "mydelegatethatpaintsred.h"
#include <memory>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
    void loadData();
    void paint_rows();
    void sorting();
    void filtrationByGroup();
    void filtrationBetween();
    void filtrationByName();
private:
    void initializationComboBox();
    void initializationInterface();
private:
    std::unique_ptr<IData> m_data;
    QTableView *m_tableView;
    QPushButton *m_loadDB;
    QPushButton *m_sortButt;
    QPushButton *m_filtrGrpButt;
    QPushButton *m_filtrBtwButt;
    QPushButton *m_filtrNameButt;
    QPushButton *m_paintButt;
    QComboBox *m_sortBox;
    QComboBox *m_groupBox;
    QComboBox *m_objBox;
    QLineEdit *m_firstValue;
    QLineEdit *m_secondValue;
    QLineEdit *m_nameEdit;

};

#endif // WIDGET_H
