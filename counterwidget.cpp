#include "counterwidget.h"
// #include "countertask.h"
#include "mutextask.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QThreadPool>
#include <qDebug>

CounterWidget::CounterWidget(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout *contanier = new QVBoxLayout;

    QLabel *label = new QLabel("Task正在运行：");
    QPushButton *button = new QPushButton("开始计数");

    contanier->addWidget(label);
    contanier->addWidget(button);
    setLayout(contanier);

    int cores = QThreadPool::globalInstance()->maxThreadCount();
    qDebug() << "CPU cores:" << QThreadPool::globalInstance()->maxThreadCount();
    connect(button, &QPushButton::clicked, this, [=](){
        for(int i = 0; i < cores; i++){
            // CounterTask *task = new CounterTask;
            // connect(task, &CounterTask::countChanged, label, [=](int value){
            //     label->setText("Task正在运行：" + QString::number(value) + "/100");
            // });
            // QThreadPool::globalInstance()->start(task);
            MutexTask *task = new MutexTask(&m_mutex, &m_sharedCounter);
            connect(task, &MutexTask::finished, this, [=](){
                m_finishedCount++;
                if (m_finishedCount == cores) {
                    label->setText("完成: " + QString::number(m_sharedCounter));
                }
            });
            QThreadPool::globalInstance()->start(task);
        };
    });
}