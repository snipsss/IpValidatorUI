#pragma once
#include <QItemDelegate>
#include <QStyleOption>

class CustomDelegate : public QItemDelegate
{
public:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        QStyleOptionViewItem opt = option;
        //QStyleOption(&opt, index);

        // Highlight values greater than 50 in column 2 as green
        if (index.column() == 1 && index.data().toInt() > 50) {
            opt.palette.setColor(QPalette::Text, Qt::green);
        }

        QItemDelegate::paint(painter, opt, index);
    }
};
