#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "players.h"
#include "teams.h"
#include "matches.h"
#include "autorisation.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{ 
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{ 
    QString fname = "users.bin";
    QFile file(fname);
    file.resize(0);
    file.close();
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    QFile file("users.bin");
    QString login;
    if (!file.open(QIODevice::ReadOnly))
        return;
    login = file.readLine();
    if (login == "users")
    {
    players window;
    window.setModal(true);
    window.exec();
    }
    else
        QMessageBox::warning(this,"Ошибка авторизации","Для просмотра вы должны авторизоваться");
}

void MainWindow::on_pushButton_4_clicked()
{
    QFile file("users.bin");
    QString login;
    if (!file.open(QIODevice::ReadOnly))
        return;
    login = file.readLine();
    if (login == "users")
    {
    teams window;
    window.setModal(true);
    window.exec();
    }
    else
        QMessageBox::warning(this,"Ошибка авторизации","Для просмотра вы должны авторизоваться");
}

void MainWindow::on_pushButton_3_clicked()
{
    QFile file("users.bin");
    QString login;
    if (!file.open(QIODevice::ReadOnly))
        return;
    login = file.readLine();
    if (login == "users")
    {
    matches window;
    window.setModal(true);
    window.exec();
    }
    else
        QMessageBox::warning(this,"Ошибка авторизации","Для просмотра вы должны авторизоваться");
}


void MainWindow::on_action_2_triggered()
{
    Autorisation window;
    window.setModal(true);
    window.exec();
}


void MainWindow::on_action_3_triggered()
{
    QFile file("auto.txt");
    file.resize(0);
    QString fname = "users.bin";
    QFile file1(fname);
    file1.resize(0);
    file1.close();
    QMessageBox::information(this,"Выход из системы","Вы успешно вышли из системы");
}

void MainWindow::on_action_4_triggered()
{
    QFile file("auto.txt");
    QString(login);
    if (!file.open(QIODevice::ReadOnly))
        return;
    login = file.readAll();
    if (login == "admin")
        QMessageBox::information(this,"Профиль","Вы зашли как admin. Вам доступен просмотр и изменение всех таблиц приложения");
    else
        if (login == "") QMessageBox::warning(this,"Ошибка просмотра профиля","Вы еще не авторизовались");
}
