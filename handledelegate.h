#ifndef HANDLEDELEGATE_H
#define HANDLEDELEGATE_H

#include <QStyledItemDelegate>
#include <QStyleOptionButton>
#include <QApplication>
#include <QMouseEvent>

class HandleDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit HandleDelegate(QObject *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const override;

    bool editorEvent(QEvent *event, QAbstractItemModel *model,
                     const QStyleOptionViewItem &option,
                     const QModelIndex &index) override;
signals:
    void editClicked(int row);
    void deleteClicked(int row);
};

#endif // HANDLEDELEGATE_H
