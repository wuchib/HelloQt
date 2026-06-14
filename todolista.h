#ifndef TODOLISTA_H
#define TODOLISTA_H

#include <QWidget>
#include <QStandardItemModel>
class todolistA : public QWidget
{
    Q_OBJECT


public:
    explicit todolistA(QWidget *parent = nullptr);
    ~todolistA() override;

private:
    void saveToFile(QStandardItemModel *model);
    void loadFromFile(QStandardItemModel *model);
};



#endif // TODOLISTA_H
