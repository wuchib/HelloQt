#ifndef PERSONINFOWIDGET_H
#define PERSONINFOWIDGET_H

#include <QWidget>

class PersonInfoWidget : public QWidget
{
    Q_OBJECT


public:
    explicit PersonInfoWidget(QWidget *parent = nullptr);
    ~PersonInfoWidget() override;
};
#endif // PERSONINFOWIDGET_H
