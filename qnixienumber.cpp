#include "qnixienumber.h"

QNixieNumber::QNixieNumber(QWidget *parent) : QWidget(parent)
{

}

int QNixieNumber::intValue() const {}

void QNixieNumber::display(int num){}

void QNixieNumber::setSegment(int val){}

void QNixieNumber::callTest()
{

    time.currentTime();
    connect(&timer, &QTimer::timeout ,this, &QNixieNumber::test); // for debuging
    timer.start(1000);

    hbox.addWidget(&displayNum);
    hbox.addWidget(&displayNum2);

    setLayout(&hbox);
}

void QNixieNumber::test()
{

    time = time.addSecs(1);
    // Splitting value
    int s1 = time.second() % 10;
    int s2 = (time.second() - s1) % 100;
    number = {NixieNumber[s2], NixieNumber[s1]}; // set value
    NixieNumber[s1];

    displayNum.setPixmap(number[0]); // test
    displayNum2.setPixmap(number[1]); // test

}

QNixieNumber::~QNixieNumber() {}
