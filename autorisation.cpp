#include "autorisation.h"
#include "ui_autorisation.h"
#include "registration.h"
#include <QString>
#include <QFile>
#include <QMessageBox>

Autorisation::Autorisation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Autorisation)
{
    ui->setupUi(this);
    this->setWindowTitle("Авторизация");
}

void Autorisation::on_pushButton_2_clicked()
{
    registration window;
    window.setModal(true);
    window.exec();
}

void Autorisation::on_pushButton_clicked()
{
    QString logon;
    QString password;
    QString username;
    QString logon1;
    QFile file("reg.bin");
    if (file.open(QIODevice::ReadOnly))
    {
        logon = file.readLine();
        password = file.readLine();
    file.close();
    }   
    QString login1 = ui -> login1 -> text();
    QString passwd1 = ui -> passwd1 -> text();
    logon1 = login1 + "\r\n";
    if (((logon1 == logon) && (passwd1 == password)) || (login1 == "admin" && passwd1 == "123"))
    {
        QFile file1("auto.txt");
        if (file1.open(QIODevice::WriteOnly | QIODevice::Append)) {
            file1.write(login1.toUtf8());
            file1.close();
            QFile file2("users.bin");
            if (file2.open(QIODevice::WriteOnly | QIODevice::Append)) {
                file2.resize(0);
                file2.write("users");
                file2.close();
        }
        QMessageBox::information(this,"Авторизация","Вы успешно зашли в систему");
        close();
     }
    else
        QMessageBox::warning(this,"Ошибка авторизации","Неправильный логин или пароль");
    }
}


Autorisation::~Autorisation()
{
    delete ui;
}
