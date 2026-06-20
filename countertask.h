#ifndef COUNTERTASK_H
#define COUNTERTASK_H

#include <QObject>
#include <QRunnable>

class CounterTask : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit CounterTask(QObject *parent = nullptr);
    void run() override;
signals:
    void countChanged(int value);
    void finished();
};

#endif // COUNTERTASK_H
