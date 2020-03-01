#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <tablemodel.h>
#include <QFile>
#include <QTextStream>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QVector<QVector<QString>> tools;

    QFile file("/home/stanislaw/CSVOperations/Tools.csv");

    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        std::string text = line.toUtf8().constData();
        std::cout << text << std::endl;
    }

    file.close();

    qmlRegisterType<TableModel>("TableModel", 0, 1, "TableModel");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
