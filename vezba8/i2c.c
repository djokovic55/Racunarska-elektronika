// primer rada sa PCF8563 koji ispisuje tekuce vreme
// u terminalu svakih 5 sekundi
#include <bcm2835.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/fcntl.h>
#include <errno.h>
#include <wiringPi.h>
#include <lcd.h>
const int RS = 3; 
const int EN = 14; 
const int D0 = 4; 
const int D1 = 12; 
const int D2 = 13; 
const int D3 = 6; 

#define changeHexToInt(hex) ((((hex)>>4) *10 ) + ((hex)%16))

//adrese registara
#define SEK 0x02
#define MIN 0x03
#define SAT 0x04
#define DAY 0x05
#define MONTH 0x07
#define YEAR 0x08
 unsigned char WriteBuf[2];
 unsigned char WriteBuf1[2];
 
 unsigned char ReadBuf;
 unsigned char g8563_Store[6];
 // sec,min,sat
 unsigned char init8563_Store[6]={0x00,0x59,0x08, 0x05, 0x05, 0x22};
 
void P8563_settime()
{
	WriteBuf[0] = SEK;
	WriteBuf[1] = g8563_Store[0];
	wiringPiI2CWrite(WriteBuf,2);
	
	WriteBuf[0] = MIN;
	WriteBuf[1] = g8563_Store[1];
	wiringPiI2CWrite(WriteBuf,2);

	WriteBuf[0] = SAT;
	WriteBuf[1] = g8563_Store[2];
	wiringPiI2CWrite(WriteBuf,2);
}

void P8563_setdate()
{
	WriteBuf1[0] = DAY;
	WriteBuf1[1] = g8563_Store[3];
	wiringPiI2CWrite(WriteBuf1,2);
	
	WriteBuf1[0] = MONTH;
	WriteBuf1[1] = g8563_Store[4];
	wiringPiI2CWrite(WriteBuf1,2);

	WriteBuf1[0] = YEAR;
	WriteBuf1[1] = g8563_Store[5];
	wiringPiI2CWrite(WriteBuf1,2);
}

void P8563_init()
{
	unsigned char i;
	for(i=0;i<=6;i++)
		g8563_Store[i]=init8563_Store[i];

	P8563_settime();
	P8563_setdate(); //date
	printf("Postavi početno tekuće vreme i datum\n");

	//inicijalizacija RTC-a
	WriteBuf[0] = 0x0;
	WriteBuf[1] = 0x00; //normalni rezim rada
	wiringPiI2CWrite(WriteBuf,2);
	
		//inicijalizacija RTC-a
	WriteBuf1[0] = 0x0;
	WriteBuf1[1] = 0x00; //normalni rezim rada
	wiringPiI2CWrite(WriteBuf1,2);
}
void P8563_Readtime()
{
	unsigned char time[7];
	WriteBuf[0] = SEK;
	bcm2835_i2c_write_read_rs(WriteBuf, 1, time, 7);

	g8563_Store[0] = time[0] & 0x7f;
	g8563_Store[1] = time[1] & 0x7f;
	g8563_Store[2] = time[2] & 0x3f;

	g8563_Store[0] = changeHexToInt(g8563_Store[0]);
	g8563_Store[1] = changeHexToInt(g8563_Store[1]);
	g8563_Store[2] = changeHexToInt(g8563_Store[2]);
}

void P8563_Readdate()
{
	unsigned char date[7];
	WriteBuf1[0] = DAY;
	bcm2835_i2c_write_read_rs(WriteBuf1, 1, date, 7);

	g8563_Store[3] = date[0] & 0x3f;
	g8563_Store[4] = date[2] & 0x1f;
	g8563_Store[5] = date[3] & 0xff;

	g8563_Store[3] = changeHexToInt(g8563_Store[3]);
	g8563_Store[4] = changeHexToInt(g8563_Store[4]);
	g8563_Store[5] = changeHexToInt(g8563_Store[5]);
}

int main(int argc, char **argv)
{
if (!bcm2835_init())
	return 1;

 //int lcd_h;
 //lcd_h = lcdInit(2, 16, 4, RS, EN, D0, D1, D2, D3, D0, D1, D2, D3);
 
 bcm2835_i2c_begin();
// adresa PCF8563 na I2C magistrali
 bcm2835_i2c_setSlaveAddress(0x51);
 bcm2835_i2c_set_baudrate(10000);
 printf("start..........\n");
 P8563_init() ;

 while(1)
 {
	P8563_Readtime();
	P8563_Readdate();
	printf("Sati:%d Minuti:%d Sekunde:%d\n", g8563_Store[2], g8563_Store[1], g8563_Store[0]);
	bcm2835_delay(2000);
	
	printf("Dani:%d Meseci:%d Godine:%d\n", g8563_Store[3], g8563_Store[4], g8563_Store[5]);
	
	/*
	lcdPosition(lcd_h, 0,0);
	lcdPrintf("h:%d m:%d s:%d\n", g8563_Store[2], g8563_Store[1], g8563_Store[0]);
	
	
	lcdPosition(lcd_h, 0,1);
	lcdPrintf("d:%d m:%d g:%d\n", g8563_Store[3], g8563_Store[4], g8563_Store[5]);
	
	delay(2000);
	lcdClear(lcd_h);
	*/
}

 bcm2835_i2c_end();
 bcm2835_close();

 return 0;
}
