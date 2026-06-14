#include "personinfowidget.h"
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QFormLayout>
#include <QVBoxLayout>

PersonInfoWidget::PersonInfoWidget(QWidget *parent)
    : QWidget(parent)
{
    QLineEdit *nameEdit = new QLineEdit();
    QComboBox *sexEdit = new QComboBox();
    sexEdit->addItem("男");
    sexEdit->addItem("女");
    QDateEdit *dateEdit = new QDateEdit();
    dateEdit->date().toString("yyyy-MM-dd");
    QTextEdit *descEdit = new QTextEdit();
    // 表单盒子
    QFormLayout *formBox = new QFormLayout;
    formBox->addRow("姓名", nameEdit);
    formBox->addRow("性别", sexEdit);
    formBox->addRow("出生日期", dateEdit);
    formBox->addRow("简介", descEdit);

    QPushButton *saveBtn = new QPushButton("保存");
    QLabel *label = new QLabel;

    // 最外层大盒子
    QVBoxLayout *container = new QVBoxLayout;
    container->addLayout(formBox);
    container->addWidget(saveBtn);
    container->addWidget(label);
    setLayout(container);

    connect(saveBtn, &QPushButton::clicked, this, [=](){
        QString name = nameEdit->text();
        QString sex = sexEdit->currentText();
        QString date = dateEdit->text();
        QString desc = descEdit->toPlainText();
        label->setText("姓名: " + name + "\n性别: " + sex +
                       "\n出生: " + date + "\n简介: " + desc);
    });
}

PersonInfoWidget::~PersonInfoWidget()
{
}