#ifndef SCOREDELEGATE_H
#define SCOREDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>
class ScoreDelegate : public QStyledItemDelegate
{
public:
    explicit ScoreDelegate(QObject *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const override
    {
        // 获取成绩值
        int score = index.data().toInt();

        // 根据分数选颜色
        QColor color;
        if (score >= 90) color = Qt::green;
        else if (score >= 60) color = QColor("#ff9800");  // 橙色
        else color = Qt::red;

        painter->save();
        painter->setPen(color);
        // 居中绘制文字
        painter->drawText(option.rect, Qt::AlignCenter, QString::number(score));
        painter->restore();
    }
};

#endif // SCOREDELEGATE_H
