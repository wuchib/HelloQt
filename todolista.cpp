#include "todolista.h"
#include "qevent.h"
#include <QLineEdit>
#include <QPushButton>
#include <QTableView>
#include <QStandardItemModel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QMessageBox>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>


todolistA::todolistA(QWidget *parent)
    : QWidget(parent)
{
    // 头部
    QLineEdit *keyWordEdit = new QLineEdit;
    QPushButton *btn = new QPushButton("添加");
    QHBoxLayout *headerBox = new QHBoxLayout;
    headerBox->addWidget(keyWordEdit);
    headerBox->addWidget(btn);

    // 中间
    QStandardItemModel *model = new QStandardItemModel(0, 2, this);
    model->setHorizontalHeaderLabels({"任务","状态"});
    QTableView *view = new QTableView(this);
    view->setModel(model);

    // 底部
    QPushButton *delBtn = new QPushButton("删除");
    QPushButton *finishBtn = new QPushButton("完成");
    QHBoxLayout *footerBox = new QHBoxLayout;
    footerBox->addWidget(delBtn);
    footerBox->addWidget(finishBtn);

    // 整体
    QVBoxLayout *container = new QVBoxLayout;
    container->addLayout(headerBox);
    container->addWidget(view);
    container->addLayout(footerBox);

    setLayout(container);

    connect(keyWordEdit, &QLineEdit::returnPressed, btn, &QPushButton::click);

    // 添加行
    connect(btn, &QPushButton::clicked, this, [=](){
        if(keyWordEdit->text() == ""){
            QMessageBox::information(this, "提示", "请输入要添加的待办事项");
            return;
        }
        QList<QStandardItem *> row;
        row << new QStandardItem(keyWordEdit->text()) << new QStandardItem("进行中");
        model->appendRow(row);
        keyWordEdit->clear();
        keyWordEdit->setFocus();
        saveToFile(model);
    });

    // 删除
    connect(delBtn, &QPushButton::clicked, this, [=](){
        QModelIndex index = view->currentIndex();
        if(!index.isValid()){
            QMessageBox::information(this,"提示", "请先选择一个任务");
            return;
        }
        model->removeRow(index.row());
        saveToFile(model);
    });
    // 完成
    connect(finishBtn, &QPushButton::clicked, this, [=](){
        QModelIndex index = view->currentIndex();
        if(!index.isValid()){
            QMessageBox::information(this,"提示", "请先选择一个任务");
            return;
        }
        model->item(index.row(), 1)->setText("已完成");
        saveToFile(model);
    });

    loadFromFile(model);
}


// 保存数据
void todolistA::saveToFile(QStandardItemModel *model)
{
    QJsonArray arr;
    for (int i = 0; i < model -> rowCount(); i++){
        QJsonObject obj;
        obj["task"] = model->item(i, 0)->text();
        obj["status"] = model->item(i, 1)->text();
        arr.append(obj);
    }
    QJsonDocument doc(arr);
    QFile file("todos.json");
    file.open(QIODevice::WriteOnly);
    file.write(doc.toJson());
    file.close();
}

// 加载数据
void todolistA::loadFromFile(QStandardItemModel *model)
{
    QFile file("todos.json");
    if(!file.open(QIODevice::ReadOnly))
        return; // 文件不存在，首次启动跳过
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    QJsonArray arr = doc.array();
    for(auto val : arr){
        QJsonObject obj = val.toObject();
        QList<QStandardItem *> row;
        row << new QStandardItem(obj["task"].toString())
            << new QStandardItem(obj["status"].toString());
        model->appendRow(row);
    }
    file.close();
}


todolistA::~todolistA()
{

}