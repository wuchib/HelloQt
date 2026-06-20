#include "boardwidget.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QKeyEvent>
BoardWidget::BoardWidget(QWidget *parent)
    : QWidget{parent}
{
    scene = new QGraphicsScene(this);
    QHBoxLayout *container = new QHBoxLayout;

    QVBoxLayout *leftBox = new QVBoxLayout;

    QPushButton *rectBtn = new QPushButton("矩形");
    QPushButton *circleBtn = new QPushButton("圆形");
    QPushButton *textBtn = new QPushButton("文字");
    leftBox->addWidget(rectBtn);
    leftBox->addWidget(circleBtn);
    leftBox->addWidget(textBtn);
    leftBox->addStretch();

    QGraphicsView *view = new QGraphicsView(scene, this);
    setFocusPolicy(Qt::StrongFocus);
    container->addLayout(leftBox);
    container->addWidget(view);

    setLayout(container);

    connect(rectBtn, &QPushButton::clicked, this, [=](){
        QGraphicsRectItem *rect = scene->addRect(50, 50, 100, 80, QPen(Qt::red), QBrush(Qt::yellow));
        rect->setFlag(QGraphicsItem::ItemIsMovable);          // 可拖动
        rect->setFlag(QGraphicsItem::ItemIsSelectable);        // 可选中
        rect->setFlag(QGraphicsItem::ItemIsFocusable);         // 可获焦点
    });

    connect(circleBtn, &QPushButton::clicked, this, [=](){
        QGraphicsEllipseItem *circle = scene->addEllipse(200, 50, 100, 80, QPen(Qt::blue), QBrush(Qt::green));
        circle->setFlag(QGraphicsItem::ItemIsMovable);          // 可拖动
        circle->setFlag(QGraphicsItem::ItemIsSelectable);        // 可选中
        circle->setFlag(QGraphicsItem::ItemIsFocusable);         // 可获焦点
    });

    connect(textBtn, &QPushButton::clicked, this, [=](){
        QGraphicsTextItem *text = scene->addText("这是文字");
        text->setFlag(QGraphicsItem::ItemIsMovable);          // 可拖动
        text->setFlag(QGraphicsItem::ItemIsSelectable);        // 可选中
        text->setFlag(QGraphicsItem::ItemIsFocusable);         // 可获焦点
    });
}

void BoardWidget::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Delete) {
        QList<QGraphicsItem *> selected = scene->selectedItems();
        for (QGraphicsItem *item : selected) {
            scene->removeItem(item);
            delete item;
        }
    }
    QWidget::keyPressEvent(event);
}
