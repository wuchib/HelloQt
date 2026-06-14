#ifndef SAVETHREAD_H
#define SAVETHREAD_H

#include <QThread>

class SaveThread : public QThread
{
    Q_OBJECT
public:
    explicit SaveThread(QObject *parent = nullptr);
    void run() override{
        for(int i = 0; i <= 100; i++){
            QThread::msleep(30);
            emit progressChanged(i);
        }
    }
signals:
    void progressChanged(int value);
};

#endif // SAVETHREAD_H
