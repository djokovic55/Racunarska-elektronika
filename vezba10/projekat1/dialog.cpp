#include "dialog.h"
#include "ui_dialog.h"
#include <wiringPi.h>
#include <softPwm.h>
#include<stdio.h>
#define PIN1 25
#define PIN2 26
#define PIN3 27
#define PIN4 28

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

/*
void Dialog::on_horizontalSlider_valueChanged(int value)
{
    softPwmCreate(PIN1, 0, 100);

    softPwmWrite(PIN1, value);
}

*/




void Dialog::on_Pin26_clicked()
{
    int value = digitalRead(PIN2);
    if(value == 1){
        digitalWrite(PIN2, LOW);
    }else
        digitalWrite(PIN2, HIGH);

}

void Dialog::on_Pin27_clicked()
{
    int value = digitalRead(PIN3);
    if(value == 1){
        digitalWrite(PIN3, LOW);
    }else
        digitalWrite(PIN3, HIGH);
}



void Dialog::on_Pin25_clicked()
{
    int value = digitalRead(PIN1);
    if(value == 1){
        digitalWrite(PIN1, LOW);
    }else
        digitalWrite(PIN1, HIGH);

}

void Dialog::on_Pin28_clicked()
{
    int value = digitalRead(PIN4);
    if(value == 1){
        digitalWrite(PIN4, LOW);
    }else
        digitalWrite(PIN4, HIGH);
}
