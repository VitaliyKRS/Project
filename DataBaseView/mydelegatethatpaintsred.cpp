#include "mydelegatethatpaintsred.h"

MyDelegateThatPaintsRed::MyDelegateThatPaintsRed(QObject *parent) : QStyledItemDelegate (parent)
{

}

void MyDelegateThatPaintsRed::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QStyleOptionViewItem opt = option;
    initStyleOption(&opt, index);
    QStyle* style = opt.widget ? opt.widget->style() : QApplication::style();
    if(index.data().toInt()>=90){
    painter->setPen(QColor(Qt::red));
    }
    auto data = index.data().toString();
    opt.text = data;
    style->drawItemText(painter, opt.rect, opt.displayAlignment, opt.palette, true,
                                opt.text);

    painter->restore();
}
