#ifndef STUDENTWIDGET_H
#define STUDENTWIDGET_H

#include <QWidget>
#include <QStandardItemModel>
class StudentWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StudentWidget(QWidget *parent = nullptr);
private:
    void saveToFile(QStandardItemModel *model);
    void loadFromFile(QStandardItemModel *model);
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // STUDENTWIDGET_H