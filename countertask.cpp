#include "countertask.h"
#include <QThread>

CounterTask::CounterTask(QObject *parent)
    : QObject{parent}
{}

void CounterTask::run()
{
    for(int i = 0; i<= 100; i++){
        QThread::msleep(20);
        emit countChanged(i);
    }
    emit finished();
}