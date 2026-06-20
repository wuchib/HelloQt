#ifndef COUNTERWIDGET_H
#define COUNTERWIDGET_H

#include <QWidget>
#include <QMutex>

class CounterWidget : public QWidget
{
    Q_OBJECT
    QMutex m_mutex;
    int m_sharedCounter = 0; // 共享计数器
    int m_finishedCount = 0; // 已完成的任务数
public:
    explicit CounterWidget(QWidget *parent = nullptr);

signals:
};

#endif // COUNTERWIDGET_H
