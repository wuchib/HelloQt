// #include "mainwindow.h"
// #include "personinfowidget.h"
// #include "todolista.h"
// #include "drawwidget.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
// #include "counterwidget.h"
// #include "weatherwidget.h"
// #include "studentwidget.h"
#include "boardwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "HelloQt_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    BoardWidget w;
    w.show();
    return QApplication::exec();
}
