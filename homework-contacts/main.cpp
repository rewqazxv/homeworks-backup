#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

extern "C" {
#include "contacts.h"
}

int main(int argc, char *argv[]) {
    contacts_init();

    QApplication a(argc, argv);
    QTranslator ts;
    ts.load(":/translations/cn");
    a.installTranslator(&ts);
    MainWindow w;
    w.show();

    return a.exec();
}
