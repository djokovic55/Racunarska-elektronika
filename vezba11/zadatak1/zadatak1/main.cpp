#include "dialog.h"
#include <lcd.h>
#include <wiringPi.h>
#include <QApplication>

const int RS = 3;
const int EN = 14;
const int D0 = 4;
const int D1 = 12;
const int D2 = 13;
const int D3 = 6;


int main(int argc, char *argv[])
{

    int lcd_h;

    if (wiringPiSetup() < 0){
         fprintf (stderr, "Greška pri inicijalizaciji: 	%s\n", strerror (errno));
         return 1 ;
    }

    lcd_h = lcdInit(2, 16, 4, RS, EN, D0, D1, D2, D3, D0, D1, D2, D3);

    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
