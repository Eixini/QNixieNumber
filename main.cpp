#include "qnixienumber.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QNixieNumber window;
    window.setWindowTitle("Nixie Numbers");
    window.setFixedSize(200,100);

    window.show();
    return app.exec();
}
