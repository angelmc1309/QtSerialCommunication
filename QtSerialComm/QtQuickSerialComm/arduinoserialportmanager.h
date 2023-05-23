#ifndef ARDUINOSERIALPORTMANAGER_H
#define ARDUINOSERIALPORTMANAGER_H

#include <QObject>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QByteArray>
#include <QException>

class ArduinoSerialPortManager : public QObject
{
    Q_OBJECT

public:
    explicit ArduinoSerialPortManager(QObject *parent = nullptr);
    ~ArduinoSerialPortManager();
    void initialize();

    void change_led_state(bool state);

private:
    QSerialPort *arduino = nullptr;

    int ARDUINO_VENDOR_ID = 9025;
    int ARDUINO_PRODUCT_ID = 578;

signals:

};

#endif // ARDUINOSERIALPORTMANAGER_H
