#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QKeyEvent>
#include <QFormLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // ui->setupUi(this);
    // connect(ui->pushButton,
    //         &QPushButton::clicked,
    //         this,
    //         [=]()
    //         {
    //             QMessageBox::information(
    //                 this,
    //                 "测试",
    //                 "Qt运行成功"
    //                 );
    //         });
    // connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::testClick);
    setWindowTitle("布局练习");

    // 表单
    QFormLayout *form = new QFormLayout;

    // 表单项
    QLineEdit *nameEdit = new QLineEdit(this);
    nameEdit->setPlaceholderText("请输入姓名");
    QSpinBox *ageSpinBox = new QSpinBox(this);
    nameEdit->setPlaceholderText("请输入年龄");

    form->addRow("姓名", nameEdit);
    form->addRow("年龄", ageSpinBox);

    // 提交按钮
    QPushButton *submitBtn = new QPushButton("提交", this);

    // 垂直布局
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addLayout(form);
    vbox->addWidget(submitBtn);

    connect(submitBtn, &QPushButton::clicked, this, [=](){
        // QMessageBox::information(this, "测试", "运行成功");
        QMessageBox::information(this, "提交", "姓名: " + nameEdit->text() + "\n年龄: " + QString::number(ageSpinBox->value()));
    });

    QWidget *central = new QWidget(this);
    central->setLayout(vbox);
    setCentralWidget(central);
}

// void

// void MainWindow::testClick()
// {
//     QMessageBox::information(this, "测试", "运行成功");
// }

// void MainWindow::testClick1()
// {

// }

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape){
        close();
    }
    QMainWindow::keyPressEvent(event);
}

MainWindow::~MainWindow()
{
    delete ui;
}

