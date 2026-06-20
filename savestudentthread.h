#ifndef SAVESTUDENTTHREAD_H
#define SAVESTUDENTTHREAD_H

#include <QObject>
#include <QThread>

class SaveStudentThread : public QThread
{
    Q_OBJECT
public:
    explicit SaveStudentThread(QObject *parent = nullptr);
    void run() override{
        for(int i = 0; i <= 100; i++){
            QThread::msleep(30);
            emit progressChanged(i);
        }
    }
signals:
    void progressChanged(int value);
};

#endif // SAVESTUDENTTHREAD_H
