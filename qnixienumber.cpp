#include "qnixienumber.h"

QNixieNumber::QNixieNumber(QWidget *parent) : QWidget(parent)
{
    time = time.currentTime();

    width_ = NixieNumber[0].width();
    height_ = NixieNumber[0].height();

    //timer.start(1000);
    //connect(&timer, &QTimer::timeout ,this, &QNixieNumber::testSegment); // for debuging

}

int QNixieNumber::intValue() const {}

void QNixieNumber::display(int num){}

void QNixieNumber::setSegment(int val){}

void QNixieNumber::test()
{

    time = time.addSecs(1);
    // Splitting value
    int s1 = time.second() % 10;
    displayNum.setPixmap(NixieNumber[s1]); // test

}

void QNixieNumber::testSegment()
{
    int n = 2;

    QRect rect;

    rect.setHeight(height_);
    rect.setWidth(width_ * n);

    QPaintEvent pevent(rect);

    paintEvent(&pevent);

}

void QNixieNumber::paintEvent(QPaintEvent *paintevent)
{

    Q_UNUSED(paintevent);

    QPainter paint(this);

    time = time.currentTime();
    time = time.addSecs(1);
    // Splitting value
    int s1 = time.second() % 10;
    int s2 = (time.second() - s1) / 10;

    paint.drawPixmap(0,0,NixieNumber[s2]);
    paint.drawPixmap(width_,0,NixieNumber[s1]);
}

QNixieNumber::~QNixieNumber() {}
