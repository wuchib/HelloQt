#include "drawwidget.h"
#include <QPainter>
#include <QPaintEvent>
#include <QPen>

DrawWidget::DrawWidget(QWidget *parent)
    : QWidget{parent}
{}

void DrawWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // painter.setPen(Qt::red);
    // painter.setBrush(Qt::yellow);
    // painter.drawRect(10, 10, 100, 50);

    // painter.drawEllipse(150, 10, 100, 50);

    // painter.setPen(QPen(Qt::blue, 3));
    // painter.drawLine(10, 100, 300, 100);

    // painter.drawText(10, 150, "hello Qt!");

    // 加载图片
    QPixmap pix("C:/Users/19233/Pictures/7f609112f542cc4549d3bad942dcdb02.jpg");
    int w = pix.width();
    int h = pix.height();
    painter.drawPixmap(0, 0, pix);

    // 像素操作
    QImage img(50, 50, QImage::Format_ARGB32);
    for(int y = 0; y < img.height(); y++){
        for(int x = 0; x < img.width(); x++){
            img.setPixelColor(x, y, QColor(x, y, 128));
        }
    }

    painter.drawPixmap(w, 0, QPixmap::fromImage(img));

    // 红线
    painter.setPen(QPen(Qt::red, 2));
    painter.drawLine(0, h, w, h);
}