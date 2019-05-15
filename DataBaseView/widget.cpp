#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),m_tableView(new QTableView()),m_loadDB(new QPushButton("Завантажити таблицю")),
      m_sortButt(new QPushButton("Сортувати")),m_filtrGrpButt(new QPushButton("Фільтрувати групи")),m_filtrBtwButt(new QPushButton("Фільтрувати інтервал"))
     ,m_filtrNameButt(new QPushButton("Фільтрувати ім'я")),m_paintButt(new QPushButton("Замалювати рядки")),m_sortBox(new QComboBox()),m_groupBox(new QComboBox())
     ,m_objBox(new QComboBox()),m_firstValue(new QLineEdit()),m_secondValue(new QLineEdit()),m_nameEdit(new QLineEdit())
{
     m_data = std::make_unique<Sqlite>();
     initializationInterface();
     initializationComboBox();
     m_firstValue->setValidator(new QIntValidator(0,100,this));
     m_secondValue->setValidator(new QIntValidator(0,100,this));
     connect(m_loadDB,SIGNAL(clicked()),this,SLOT(loadData()));
     connect(m_sortButt,SIGNAL(clicked()),this,SLOT(sorting()));
     connect(m_filtrGrpButt,SIGNAL(clicked()),this,SLOT(filtrationByGroup()));
     connect(m_paintButt,SIGNAL(clicked()),this,SLOT(paint_rows()));
     connect(m_filtrBtwButt,SIGNAL(clicked()),this,SLOT(filtrationBetween()));
     connect(m_filtrNameButt,SIGNAL(clicked()),this,SLOT(filtrationByName()));
}

Widget::~Widget()
{

}

void Widget::loadData()
{
    m_tableView->setModel(m_data->loadData());
}

void Widget::paint_rows()
{
    if(m_tableView->model() == nullptr){
        QMessageBox::critical(this,tr("Таблиця не завантажена"),tr("Завантажте таблицю!!!"));
        return;
    }

    for(int i=0;i<m_tableView->model()->columnCount();++i){
        for(int j =0;j<m_tableView->model()->rowCount();++j){
            if(m_tableView->model()->data(m_tableView->model()->index(i,j)) >=90 ){
                 m_tableView->setItemDelegateForColumn(m_tableView->model()->index(j,i).column(),new MyDelegateThatPaintsRed(this));
            }
        }
    }
}

void Widget::sorting()
{
     m_tableView->setModel(m_data->sorting(m_sortBox->currentIndex()));
}

void Widget::filtrationByGroup()
{
     m_tableView->setModel(m_data->filtrationByGroup(m_groupBox->currentIndex()));
}

void Widget::filtrationBetween()
{
    if(m_firstValue->text() == "" && m_secondValue->text() == ""){
        QMessageBox::information(this,tr("Не вибраний інтервал"),tr("Вибіріть інтервал!!"));
    }
     m_tableView->setModel(m_data->filtrationBetween(m_objBox->currentIndex(),m_firstValue->text().toInt(),m_secondValue->text().toInt()));
}

void Widget::filtrationByName()
{
    if(m_nameEdit->text() == ""){
        QMessageBox::information(this,tr("Не введене ім'я"),tr("Введіть ім'я!!"));
    }
    m_tableView->setModel(m_data->filtrationbyName(m_nameEdit->text()));
}

void Widget::initializationComboBox()
{
    m_sortBox->addItem("Group");
    m_sortBox->addItem("Name");
    m_sortBox->addItem("Gradebook Number");
    m_sortBox->addItem("Maths");
    m_sortBox->addItem("Drawing");
    m_sortBox->addItem("Literature");
    m_groupBox->addItem("uk-61");
    m_groupBox->addItem("uk-71");
    m_groupBox->addItem("uk-72");
    m_groupBox->addItem("uk-82");
    m_objBox->addItem("Maths");
    m_objBox->addItem("Drawing");
    m_objBox->addItem("Literature");
}

void Widget::initializationInterface()
{
    QVBoxLayout *rightLayout = new QVBoxLayout();
    rightLayout->addWidget(m_tableView);
    rightLayout->addWidget(m_loadDB);

    QGridLayout *leftLayout = new QGridLayout();
    leftLayout->addWidget(new QLabel("Виберіть що сортувати"),0,1,1,2);
    leftLayout->addWidget(m_sortBox,1,0);
    leftLayout->addWidget(m_sortButt,1,1,1,2);
    leftLayout->addWidget(new QLabel("Фільтрувати"),2,1,1,2);
    leftLayout->addWidget(m_groupBox,3,0);
    leftLayout->addWidget(m_filtrGrpButt,3,1,1,2);
    leftLayout->addWidget(new QLabel("Введіть імя"),4,0);
    leftLayout->addWidget(m_nameEdit,4,1);
    leftLayout->addWidget(m_filtrNameButt,4,2);
    leftLayout->addWidget(new QLabel("Введіть перший інтервал"),5,0);
    leftLayout->addWidget(m_firstValue,5,1,1,2);
    leftLayout->addWidget(new QLabel("Введіть другий інтервал"),6,0);
    leftLayout->addWidget(m_secondValue,6,1,1,2);
    leftLayout->addWidget(m_objBox,7,0);
    leftLayout->addWidget(m_filtrBtwButt,7,1,1,2);
    leftLayout->addWidget(new QLabel("Замалювати бали >= 90"),8,1,1,2);
    leftLayout->addWidget(m_paintButt,9,0,1,3);

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->setMargin(11);
    mainLayout->setSpacing(6);
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
}
