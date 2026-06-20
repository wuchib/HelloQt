#include "weatherwidget.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QMessageBox>

WeatherWidget::WeatherWidget(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout *container = new QVBoxLayout;

    QLineEdit *cityEdit = new QLineEdit;

    QPushButton *btn = new QPushButton("查询");

    QLabel *label = new QLabel("");

    container->addWidget(cityEdit);
    container->addWidget(btn);
    container->addWidget(label);

    connect(cityEdit, &QLineEdit::returnPressed, btn, &QPushButton::click);
    connect(btn, &QPushButton::clicked, this, [=](){
        if(cityEdit->text() == ""){
            QMessageBox::information(this,"提示", "请输入要查询天气的城市");
            return;
        }
        // 1.创建管理器
        QNetworkAccessManager *manger = new QNetworkAccessManager(this);
        // 2.构造请求
        QString city = cityEdit->text();
        QNetworkRequest request(QUrl("http://wttr.in/" + city + "?format=%l:+%t"));
        btn->setEnabled(false);
        label->setText("加载中...");
        // 3.发送 GET 请求，拿到 reply
        QNetworkReply *reply = manger->get(request);

        connect(reply, &QNetworkReply::finished, this, [=](){
            if(reply->error() == QNetworkReply::NoError){
                QByteArray data = reply->readAll();
                label->setText(data);
            }else{
                label->setText("查询失败: " + reply->errorString());
            }
            btn->setEnabled(true);
            reply->deleteLater();
        });
    });
    setLayout(container);
}
