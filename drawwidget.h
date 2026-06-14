#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>

class DrawWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DrawWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

signals:
};

#endif // DRAWWIDGET_H
