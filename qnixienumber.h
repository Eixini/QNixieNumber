#ifndef QNIXIENUMBER_H
#define QNIXIENUMBER_H

#include <QWidget>
#include <QPixmap>
#include <QTimer>
#include <QMessageBox>
#include <cmath>
#include <vector>
#include <array>
#include <QDebug>
#include <QString>
#include <QPainter>
#include <QPaintEvent>
#include <QRect>

class QNixieNumber : public QWidget
{
    Q_OBJECT

    enum mode {NIXIE,REALNIXIE}; // Для выбора стиля отображения цифр

public:
    QNixieNumber(QWidget *parent = nullptr);
    ~QNixieNumber();

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

std::array<QPixmap,10> RealNixieNumber
{
        QPixmap(":/numbers/realnixie_numbers/rn0.png"),
        QPixmap(":/numbers/realnixie_numbers/rn1.png"),
        QPixmap(":/numbers/realnixie_numbers/rn2.png"),
        QPixmap(":/numbers/realnixie_numbers/rn3.png"),
        QPixmap(":/numbers/realnixie_numbers/rn4.png"),
        QPixmap(":/numbers/realnixie_numbers/rn5.png"),
        QPixmap(":/numbers/realnixie_numbers/rn6.png"),
        QPixmap(":/numbers/realnixie_numbers/rn7.png"),
        QPixmap(":/numbers/realnixie_numbers/rn8.png"),
        QPixmap(":/numbers/realnixie_numbers/rn9.png")
};

    QTimer timer;

    int segment_; // Для хранения количества сегментов
    int value_; // Для хранения текущего значения на дисплее
    int number_; // Для хранения полученного значения в display
    int width_; // Длина 1 изображения
    int height_; // Высота 1 изображения

    std::vector<int> number; // Для хранение цифр по отдельности из полученного числа

private slots:

void paintEvent(QPaintEvent *) override; // Переопределенный метод
int split(int number); // Для дробления числа

};
#endif // QNIXIENUMBER_H
