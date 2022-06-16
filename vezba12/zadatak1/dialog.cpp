#include "dialog.h"
#include "ui_dialog.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <QTime>
#include <QTimer>
#include <QLCDNumber>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/fcntl.h>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QTimer *mytimer1 = new QTimer(this);
    connect(mytimer1, SIGNAL(timeout()), this, SLOT(rtcReadTimeSlot()));

    mytimer1->start(500);
}
float temperatura(void) //očitavanje temperature
{
    int fd = -1, ret;
    char *tmp1, tmp2[10], ch='t';
    char devname_head[50] =  "/sys/devices/w1_bus_master1/28-00000cfbb0e4";
    char devname_end[10] = "/w1_slave";
    char dev_name[100];
    long value;
    float integer, decimal;
    char buffer[100];
    int i,j;

    strcpy(dev_name, devname_head);

    strcat(dev_name, devname_end);

    if ((fd = open(dev_name, O_RDONLY)) < 0)
    {
        perror("Greška pri otvaranju!");
        exit(1);
    }
    ret = read(fd, buffer, sizeof(buffer));
    if (ret < 0)
    {
        perror("Greška pri čitanju!");
        exit(1);
    }
    tmp1 = strchr(buffer, ch);
    sscanf(tmp1, "t=%s", tmp2);
    value = atoi(tmp2);
    integer = value / 1000;
    decimal = value % 1000;
    printf("Temperatura je %d.%d\n", integer,decimal);
    close(fd);
    float x = float(integer) + float(decimal/1000);
    return x;
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::rtcReadTimeSlot()
{



     float tem = temperatura();
    QString temp = QString::number(tem);
    //QString x = "sdfasdf";
     ui->lineEdit->setText(temp);

}





void Dialog::on_lineEdit_textChanged(const QString &arg1)
{

}
