#ifndef AUTORISATION_H
#define AUTORISATION_H

#include <QDialog>

namespace Ui {
class Autorisation;
}

class Autorisation : public QDialog
{
    Q_OBJECT

public:
    explicit Autorisation(QWidget *parent = nullptr);
    ~Autorisation();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Autorisation *ui;
};

#endif // AUTORISATION_H
