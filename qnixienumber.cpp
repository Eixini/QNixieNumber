#include "qnixienumber.h"

QNixieNumber::QNixieNumber(QWidget *parent) : QWidget(parent)
{
    width_ = NixieNumber[0].width();
    height_ = NixieNumber[0].height();
}

int QNixieNumber::intValue() const {  return value_; }

void QNixieNumber::display(int num)
{
    number_ = num;

    for(int i = 0; i < segment_ ; ++i)       // Цикл для дробления числа и запись отдельныч цифр в массив
        number.push_back(split(number_));

    std::reverse(number.begin(),number.end());
}

void QNixieNumber::setSegment(int value) { segment_ = value; } // Установка количества сегментов

void QNixieNumber::paintEvent(QPaintEvent *)
{
    QPainter paint(this);

    for(int i = 0; i < segment_ ; ++i)
    {
        paint.drawPixmap(width_ * i,0, NixieNumber[number[i]]);
    }
}

int QNixieNumber::split(int number)
{
    int n = number % 10;            // получение последней цифры из числа
    number_ = (number - n) / 10;    // обновление числа, для дальнейшего действий с ним
    return n;                       // возврат отсеченной части
}

QNixieNumber::~QNixieNumber() {}
