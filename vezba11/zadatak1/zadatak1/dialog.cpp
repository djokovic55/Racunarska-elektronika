#include "dialog.h"
#include "ui_dialog.h"
#include <wiringPi.h>
#include <lcd.h>
#include <QApplication>
#include <string.h>

const int RS = 3;
const int EN = 14;
const int D0 = 4;
const int D1 = 12;
const int D2 = 13;
const int D3 = 6;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->lineEdit, SIGNAL(textChanged(QString)), ui->pushButton, SLOT(clicked()));
    connect(ui->lineEdit_2, SIGNAL(textChanged(QString)), ui->pushButton, SLOT(clicked()));

}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_lineEdit_textChanged(const QString &arg1)
{


}

void Dialog::on_lineEdit_2_textChanged(const QString &arg1)
{

}

void Dialog::on_pushButton_clicked()
{
    int lcd_h;
    lcd_h = lcdInit(2, 16, 4, RS, EN, D0, D1, D2, D3, D0, D1, D2, D3);

    QString var1 = ui->lineEdit->text();
    QString var2 = ui->lineEdit_2->text();

    const char *cs1 = var1.toStdString().c_str();
     const char *cs2 = var2.toStdString().c_str();

    lcdPosition(lcd_h, 0,0);
    lcdPrintf(lcd_h, "%s", cs1);



    lcdPosition(lcd_h, 0,1);
    lcdPrintf(lcd_h, "%s", cs2);



}
