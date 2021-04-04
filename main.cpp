#include "qnixienumber.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QNixieNumber window;
    window.setWindowTitle("Nixie Numbers");

    window.setSegment(9);
    window.display(123456789);

    window.show();
    return app.exec();
}
