#ifndef MYDELEGATETHATPAINTSRED_H
#define MYDELEGATETHATPAINTSRED_H
#include <QStyledItemDelegate>
#include <QPainter>
#include <QApplication>

class MyDelegateThatPaintsRed : public QStyledItemDelegate
{
    Q_OBJECT
public:
    MyDelegateThatPaintsRed(QObject *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionViewItem &option,
                                    const QModelIndex &index) const Q_DECL_OVERRIDE;
};

#endif // MYDELEGATETHATPAINTSRED_H
