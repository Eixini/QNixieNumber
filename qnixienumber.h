#ifndef QNIXIENUMBER_H
#define QNIXIENUMBER_H

#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QHBoxLayout>
#include <QTimer>
#include <QTime>

#include <array>
#include <QDebug>
#include <QString>
#include <QPainter>
#include <QPaintEvent>
#include <QRect>

class QNixieNumber : public QWidget
{
    Q_OBJECT

    static int value_; //

public:
    QNixieNumber(QWidget *parent = nullptr);
    ~QNixieNumber();

public slots:

int intValue() const; // Returns the current integer value
void display(int num); // Display nixie numbers
void setSegment(int val); // Sets the number of segments

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


    QHBoxLayout hbox;

    // For Debuging
    QLabel displayNum;
    QTimer timer;
    QTime time;

    std::array<QPixmap,2> number;

    int width_;
    int height_;

private slots:

void test(); // for debuging
void testSegment(); // for debuging

void paintEvent(QPaintEvent *paintevent) override; // Переопределенный метод

};
#endif // QNIXIENUMBER_H
