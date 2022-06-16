#ifndef DIALOG_H
#define DIALOG_H

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
QT_CHARTS_USE_NAMESPACE
#include <QDialog>
#include<QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE
#include <wiringPiI2C.h>
#include <wiringPi.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QTimer *myTimer1;
        int obrisi;
        int t;
        int fd;
         QLineSeries *series;
         QChart *chart;
         QChartView *chartView;
         int adcVal;
public slots:
    void Read();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
