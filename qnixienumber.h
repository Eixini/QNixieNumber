#ifndef QNIXIENUMBER_H
#define QNIXIENUMBER_H

#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QHBoxLayout>
#include <QTimer>
#include <QTime>
#include <QMessageBox>
#include <cmath>

#include <array>
#include <vector>
#include <QDebug>
#include <QString>
#include <QPainter>
#include <QPaintEvent>
#include <QRect>

class QNixieNumber : public QWidget
{
    Q_OBJECT

public:
    QNixieNumber(QWidget *parent = nullptr);
    ~QNixieNumber();

    enum{FIXED,CHANGED}; // Для выбора режима - виджет с фиксированным числом сегментов или число сегментов зависит от значности переданного значения

public slots:

int intValue() const; // Returns the current integer value
void display(int number = 0); // Display nixie numbers
void setSegment(int value = 0); // Sets the number of segments

private:

// For easy access to values
std::array<QPixmap,10> NixieNumber
{
        QPixmap(":/numbers/nixie_numbers/n0.png"),
        QPixmap(":/numbers/nixie_numbers/n1.png"),
        QPixmap(":/numbers/nixie_numbers/n2.png"),
        QPixmap(":/numbers/nixie_numbers/n3.png"),
        QPixmap(":/numbers/nixie_numbers/n4.png"),
        QPixmap(":/numbers/nixie_numbers/n5.png"),
        QPixmap(":/numbers/nixie_numbers/n6.png"),
        QPixmap(":/numbers/nixie_numbers/n7.png"),
        QPixmap(":/numbers/nixie_numbers/n8.png"),
        QPixmap(":/numbers/nixie_numbers/n9.png")
};

    // For Debuging
    QLabel displayNum;
    QTimer timer;
    QTime time;

    int segment_; // Для хранения количества сегментов
    int value_; // Для хранения текущего значения на дисплее
    int number_; // Для хранения полученного значения в display
    int width_; // Длина 1 изображения
    int height_; // Высота 1 изображения
    int dig_; // Хренение количества знаков в цифре

    std::vector<int> number; // Для хранение цифр по отдельности из полученного числа

private slots:

void paintEvent(QPaintEvent *) override; // Переопределенный метод
int digits(int number); // Для подсчета количество знаков в цифре
int split(int number); // Для дробления числа

};
#endif // QNIXIENUMBER_H
