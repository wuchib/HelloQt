#include "mutextask.h"
#include <QMutexLocker>

MutexTask::MutexTask(QMutex *mutex, int *counter, QObject *parent)
    : QObject(parent), m_mutex(mutex), m_counter(counter)
{}

void MutexTask::run()
{
    for(int i = 0; i < 1000; i++){
        QMutexLocker locker(m_mutex);
        (*m_counter)++;
    }
    emit finished();
}
