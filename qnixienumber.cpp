#include "qnixienumber.h"

QNixieNumber::QNixieNumber(QWidget *parent) : QWidget(parent)
{
    time = time.currentTime();

    timer.start(1000);
    connect(&timer, &QTimer::timeout ,this, &QNixieNumber::test); // for debuging

    hbox.addWidget(&displayNum);

    setLayout(&hbox);
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

QNixieNumber::~QNixieNumber() {}
