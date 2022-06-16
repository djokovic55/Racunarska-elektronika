#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <string.h>
#include <sys/fcntl.h>
#include <errno.h>
#include <lcd.h>

// dodela vrednosti za konkretne pinove 
// prema gornjoj tabeli i semi DVK512

const int RS = 3; 
const int EN = 14; 
const int D0 = 4; 
const int D1 = 12; 
const int D2 = 13; 
const int D3 = 6; 

int main() {
	

	int lcd_h;

	int x=0, y=0;
	
	if (wiringPiSetup() < 0){
		 fprintf (stderr, "Greška pri inicijalizaciji: 	%s\n", strerror (errno));
		 return 1 ;
	}

	lcd_h = lcdInit(2, 16, 4, RS, EN, D0, D1, D2, D3, D0, D1, D2, D3);
	
	int i=0, taster_pritisnut1=0, taster_pritisnut2=0, taster_pritisnut3=0, taster_pritisnut4=0;
	int r_value1, r_value2, r_value3, r_value4;

	if(wiringPiSetup() == -1)
		exit(1);

	pinMode(21, INPUT);
	pinMode(22, INPUT);
	pinMode(23, INPUT);
	pinMode(24, INPUT);

	pinMode(0, OUTPUT);

	digitalWrite(25, HIGH);

	if(softPwmCreate(28, 0, 100) != 0)
		exit(2);

	lcdHome(lcd_h);
	lcdDisplay(lcd_h, 1);
	lcdCursor(lcd_h, 1);
	lcdCursorBlink(lcd_h, 1);

	while(1) {
		r_value1 = digitalRead(21);
		digitalWrite(25, r_value1);


		if(!r_value1 && !taster_pritisnut1){
			taster_pritisnut1 = 1;
			delay(20);
			
			x++;
			if(x > 15)
				x=0;
			lcdPosition(lcd_h, x, y);

			
		}

		if(r_value1) {
			taster_pritisnut1 = 0;
			delay(20);
		}

		r_value2 = digitalRead(22);
		digitalWrite(25, r_value2);

		if(!r_value2 && !taster_pritisnut2){
			taster_pritisnut2 = 1;
			delay(20);

			x--;
			if(x < 0 )
				x=15;
			lcdPosition(lcd_h, x, y);
		}

		if(r_value2){
			taster_pritisnut2 = 0;
			delay(20);
		}
//GORE DOLE
		r_value3 = digitalRead(23);
		digitalWrite(25, r_value3);

		if(!r_value3 && !taster_pritisnut3){
			taster_pritisnut3 = 1;
			delay(20);

			y++;
			if(x > 1 )
				y = 0;
			lcdPosition(lcd_h, x, y);
		}

		if(r_value3){
			taster_pritisnut3 = 0;
			delay(20);
		}

		r_value4 = digitalRead(24);
		digitalWrite(25, r_value4);

		if(!r_value4 && !taster_pritisnut4){
			taster_pritisnut4 = 1;
			delay(20);

			y--;
			if(y < 0 )
				y=1;
			lcdPosition(lcd_h, x, y);
		}

		if(r_value4){
			taster_pritisnut4 = 0;
			delay(20);
		}

	}
		return 0;

}