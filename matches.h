#ifndef MATCHES_H
#define MATCHES_H

#include <QDialog>

namespace Ui {
class matches;
}

class matches : public QDialog
{
    Q_OBJECT

public:
    explicit matches(QWidget *parent = nullptr);
    ~matches();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::matches *ui;
};

#endif // MATCHES_H
