#include "registration.h"
#include "ui_registration.h"
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QDir>

using namespace std;

registration::registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration)
{
    ui->setupUi(this);
    this->setWindowTitle("Регистрация");
}

void registration::on_pushButton_clicked()
{
int t = 0;
QString login = ui -> login -> text();
QString passwd = ui -> passwd -> text();
 if (passwd.length() < 6) QMessageBox::warning(this,"Ошибка регистрации","Длинна пароля должна быть более 6 символов");
QString fname = "reg.bin";
QFile file(fname);
if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
    file.resize(0);
    file.write(login.toUtf8()+"\r\n");
    t++;
    file.write(passwd.toUtf8());
    t++;
    file.close();
}
    bool trainer = ui -> Trainer -> isChecked();
     if (trainer == true)
     {
         QFile file1("user.txt");
         if (file1.open(QIODevice::WriteOnly | QIODevice::Append)) {
         file1.resize(0);
         file1.write("trainer");
         file1.close();
         }
         t++;
     }
     bool player = ui -> Player -> isChecked();
      if (player == true)
      {
          QFile file1("user.txt");
          if (file1.open(QIODevice::WriteOnly | QIODevice::Append)) {
          file1.resize(0);
          file1.write("player");
          file1.close();
          }
          t++;
      }
      if (player == false && trainer == false) QMessageBox::warning(this,"Ошибка регистрации","Вы не выбрали профиль регистрации");
if (t == 3) close();
}

registration::~registration()
{
    delete ui;
}
