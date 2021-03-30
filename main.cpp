#include "qnixienumber.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QNixieNumber window;
    window.setWindowTitle("Nixie Numbers");
    window.setFixedHeight(100);

    window.show();
    return app.exec();
}
