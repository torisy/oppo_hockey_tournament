#ifndef PLAYERS_H
#define PLAYERS_H

#include <QDialog>

namespace Ui {
class players;
}

class players : public QDialog
{
    Q_OBJECT

public:
    explicit players(QWidget *parent = nullptr);
    ~players();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::players *ui;
    void table();
};

#endif // PLAYERS_H
