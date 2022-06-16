#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    //void on_pushButton_clicked();

    //void on_horizontalSlider_valueChanged(int value);

    //void on_pushButton_4_pressed();

    //void on_pushButton_pressed();

    //void on_pushButton_clicked(bool checked);

    //void on_Pin25_clicked(bool checked);

    void on_Pin26_clicked();

    void on_Pin27_clicked();



    void on_Pin25_clicked();

    void on_Pin28_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
