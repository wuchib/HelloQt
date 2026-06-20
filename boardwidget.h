#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>
#include <QGraphicsScene>
class BoardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BoardWidget(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent *event) override;
private:
    QGraphicsScene *scene;
signals:
};

#endif // BOARDWIDGET_H
