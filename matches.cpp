#include "matches.h"
#include "ui_matches.h"
#include <QFile>
#include<QMessageBox>
#include<QFileDialog>
matches::matches(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::matches)
{
    ui->setupUi(this);
    this->setWindowTitle("Таблица матчей");
}


matches::~matches()
{
    delete ui;
}

void matches::on_pushButton_clicked()
{
    QFile file("TabSet2.txt");
        if (file.open(QIODevice::WriteOnly))
        { //Начало условия
            QDataStream stream(&file);
            int row(ui->model->rowCount());
            int column(ui->model->columnCount());
            stream << row << column;

            for (int i = 0; i < row; i++)
                for (int j = 0; j < column; j++)
                    ui->model->item(i,j)->write(stream);
            file.close();
        }
}


void matches::on_pushButton_2_clicked()
{
    QFile file("TabSet.txt");
    if (file.open(QIODevice::ReadOnly))
    {
        QDataStream stream(&file);
        qint32 row, column;
        stream >> row >> column;

        ui->model->setRowCount(row);
        ui->model->setColumnCount(column);
        QTableWidgetItem *item;
        for (int i = 0; i < row; ++i)
        {
                    for (int j = 0; j < column; j++)
                    {
                        item = new QTableWidgetItem;
                        item->read(stream);
                        ui->model->setItem(i, j, item);
                    }
        }
            file.close();
    }
}
