#include "studentwidget.h"
#include "savestudentthread.h"
#include <QLineEdit>
#include <QPushButton>
#include <QTableView>
#include <QStandardItemModel>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QProgressBar>
#include <QMessageBox>
#include <QKeyEvent>
// 持久化
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
// 线程
#include <QThread>


StudentWidget::StudentWidget(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout *container = new QVBoxLayout;

    QFormLayout *form = new QFormLayout;
    QTableView *table = new QTableView;
    QHBoxLayout *footer = new QHBoxLayout;

    // form里面的组件
    QLineEdit *nameEdit = new QLineEdit;
    QLineEdit *numEdit = new QLineEdit;
    QLineEdit *coreEdit = new QLineEdit;
    QPushButton *addBtn = new QPushButton("添加");
    form->addRow("姓名", nameEdit);
    form->addRow("学号", numEdit);
    form->addRow("成绩", coreEdit);
    form->addWidget(addBtn);

    // 表格
    QStandardItemModel *model = new QStandardItemModel(0, 3, this);
    model->setHorizontalHeaderLabels({"姓名","学号","成绩"});
    table->setModel(model);


    // 底部
    QProgressBar *bar = new QProgressBar;
    QPushButton *saveBtn = new QPushButton("保存");
    QPushButton *delBtn = new QPushButton("删除");
    // delBtn->setEnabled(false);
    footer->addWidget(bar);
    footer->addWidget(saveBtn);
    footer->addWidget(delBtn);

    container->addLayout(form);
    container->addWidget(table);
    container->addLayout(footer);

    setLayout(container);

    // 添加
    connect(addBtn, &QPushButton::clicked, this, [=](){
        if(nameEdit->text() == "" || numEdit->text() == "" || coreEdit->text() == ""){
            QMessageBox::information(this, "提示", "请输入必填项");
            return;
        }

        QList<QStandardItem *> row;
        row << new QStandardItem(nameEdit->text())
            << new QStandardItem(numEdit->text())
            << new QStandardItem(coreEdit->text());
        model->appendRow(row);
    });

    //删除
    connect(delBtn, &QPushButton::clicked, this, [=](){
        QModelIndex index = table->currentIndex();
        if(!index.isValid()){
            QMessageBox::information(this, "提示", "请先选择数据");
            return;
        }
        model->removeRow(index.row());
    });

    SaveStudentThread *worker = new SaveStudentThread(this);

    connect(worker, &SaveStudentThread::progressChanged, bar, &QProgressBar::setValue);
    connect(worker, &SaveStudentThread::finished, this, [=](){
        saveToFile(model);
        saveBtn->setEnabled(true);
    });

    //保存
    connect(saveBtn, &QPushButton::clicked, this, [=](){
        bar->setValue(0);
        saveBtn->setEnabled(false);
        worker->start();
    });

    // 加载数据
    loadFromFile(model);
}

void StudentWidget::saveToFile(QStandardItemModel *model)
{
    QJsonArray arr;
    for (int i = 0; i < model->rowCount(); i++){
        QJsonObject obj;
        obj["name"] = model->item(i, 0)->text();
        obj["num"] = model->item(i, 1)->text();
        obj["core"] = model->item(i, 2)->text();
        arr.append(obj);
    }
    QJsonDocument doc(arr);
    QFile file("students.json");
    file.open(QIODevice::WriteOnly);
    file.write(doc.toJson());
    file.close();
}

void StudentWidget::loadFromFile(QStandardItemModel *model)
{
    QFile file("students.json");
    if(!file.open(QIODevice::ReadOnly))
        return;
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    QJsonArray arr = doc.array();
    for (int i = 0; i < arr.size(); i++){
        QJsonObject obj = arr[i].toObject();
        QList<QStandardItem *> row;
        row << new QStandardItem(obj["name"].toString())
            << new QStandardItem(obj["num"].toString())
            << new QStandardItem(obj["core"].toString());
        model->appendRow(row);
    }
}


void StudentWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) close();
    QWidget::keyPressEvent(event);
}