#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QString>
#define APP_NAME "Lamp"
#define APP_VER "0.0.1"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "src_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    qApp->setApplicationName(QString(APP_NAME));
    qApp->setApplicationDisplayName(QString(APP_NAME));
    qApp->setApplicationVersion(QString(APP_VER));
    MainWindow w;
    w.show();

    return a.exec();
}
