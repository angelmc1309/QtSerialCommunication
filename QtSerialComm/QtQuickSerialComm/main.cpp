#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "arduinoblinkerstate.h"
#include "arduinoserialportmanager.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;


    ArduinoBlinkerState arduino_blinker_state;

    ArduinoSerialPortManager arduino_serial_manager;

    arduino_serial_manager.initialize();

    QObject::connect(&arduino_blinker_state, &ArduinoBlinkerState::led_stateChanged,
                     &arduino_serial_manager, &ArduinoSerialPortManager::change_led_state);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    QQmlContext * context(engine.rootContext());
    context->setContextProperty("arduino_blinker_state", &arduino_blinker_state);
    return app.exec();
}
