#include "dialog.h"
#include <wiringPi.h>
#include <QApplication>
#include <softPwm.h>
#include<stdio.h>
#define PIN1 25
#define PIN2 26
#define PIN3 27
#define PIN4 28
int main(int argc, char *argv[])
{


   if (wiringPiSetup () == -1) exit (1);

   pinMode(PIN1, OUTPUT);
   pinMode(PIN2, OUTPUT);
   pinMode(PIN3, OUTPUT);
   pinMode(PIN4, OUTPUT);


    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
