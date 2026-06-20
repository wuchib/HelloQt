#ifndef MUTEXTASK_H
#define MUTEXTASK_H

#include <QObject>
#include <QRunnable>
#include <QMutex>

class MutexTask : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit MutexTask(QMutex *mutex, int *counter, QObject *parent = nullptr);
    void run() override;
signals:
    void changed(int value);
    void finished();
private:
    QMutex *m_mutex;
    int *m_counter;
};

#endif // MUTEXTASK_H
