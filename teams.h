#ifndef TEAMS_H
#define TEAMS_H

#include <QDialog>

namespace Ui {
class teams;
}

class teams : public QDialog
{
    Q_OBJECT

public:
    explicit teams(QWidget *parent = nullptr);
    ~teams();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::teams *ui;
};

#endif // TEAMS_H
