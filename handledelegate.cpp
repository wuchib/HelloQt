#include "handledelegate.h"
#include <QStyle>
HandleDelegate::HandleDelegate(QObject *parent)
    : QStyledItemDelegate{parent}
{}

void HandleDelegate::paint(QPainter *painter,
                           const QStyleOptionViewItem &option,
                           const QModelIndex &index) const
{
    QRect rect = option.rect;
    int halfWidth = rect.width() / 2;

    // 编辑按钮
    QStyleOptionButton editBtn;
    editBtn.rect = QRect(rect.left() + 4, rect.top() + 4, halfWidth - 8, rect.height() - 8);
    editBtn.text = "编辑";
    editBtn.state = QStyle::State_Enabled;
    QApplication::style()->drawControl(QStyle::CE_PushButton, &editBtn, painter);

    // 删除按钮
    QStyleOptionButton delBtn;
    delBtn.rect = QRect(rect.left() + halfWidth + 4, rect.top() + 4, halfWidth - 8, rect.height() - 8);
    delBtn.text = "删除";
    delBtn.state = QStyle::State_Enabled;
    QApplication::style()->drawControl(QStyle::CE_PushButton, &delBtn, painter);
}

bool HandleDelegate::editorEvent(QEvent *event, QAbstractItemModel *model,
                                 const QStyleOptionViewItem &option,
                                 const QModelIndex &index)
{
    if(event->type() == QEvent::MouseButtonRelease){
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        QPoint pos = mouseEvent->pos() - option.rect.topLeft();  // 相对于单元格
        int halfWidth = option.rect.width() / 2;
        if(pos.x() < halfWidth)
            emit editClicked(index.row());
        else
            emit deleteClicked(index.row());
        return true;
    }
    return QStyledItemDelegate::editorEvent(event, model, option, index);
}
