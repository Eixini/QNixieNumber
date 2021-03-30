#include "qnixienumber.h"

QNixieNumber::QNixieNumber(QWidget *parent) : QWidget(parent)
{
    time = time.currentTime();

    width_ = NixieNumber[0].width();
    height_ = NixieNumber[0].height();

    display(523009);

    timer.start(1000);
    connect(&timer, &QTimer::timeout,this,QOverload<>::of(&QNixieNumber::update));

}

int QNixieNumber::intValue() const
{
    return value_;
}

void QNixieNumber::display(int num)
{
    number_ = num;

    if(QNixieNumber::CHANGED)
    {


    }
    else if(QNixieNumber::FIXED)
    {

        dig_ = digits(number_); // Получение количество знаков в цифре

        for(int i = dig_; 0 < i; --i)
        {
              number[i-1] = split(number_);
        }

        // Теперь необходимо создатьвать сегменты и инициализировать их значениями

    }
    else
    {
        QMessageBox::warning(this,"Ошибка", "Вами выбран неверный режим ENUM");
    }

}

void QNixieNumber::setSegment(int value)
{
    segment_ = value;
}

void QNixieNumber::paintEvent(QPaintEvent *)
{

    QPainter paint(this);

    //time = time.currentTime();
    // Splitting value
    //int s1 = time.second() % 10;
    //int s2 = (time.second() - s1) / 10;

    //paint.drawPixmap(0,0,NixieNumber[0]);
    //paint.drawPixmap(width_,0,NixieNumber[s1]);

    for(int i = 0; i < dig_; i++)
    {
        paint.drawPixmap(width_ * i,0, NixieNumber[i]);
    }
}

int QNixieNumber::digits(int number)
{
    return (number==0? 1: int (log10 (number) + 1));
}

int QNixieNumber::split(int number)
{
    int n = number % 10;            // получение последней цифры из числа
    number_ = (number - n) / 10;    // обновление числа, для дальнейшего действий с ним
    return n;                       // возврат отсеченной части
}

QNixieNumber::~QNixieNumber() {}
