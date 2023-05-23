#include "arduinoserialportmanager.h"

ArduinoSerialPortManager::ArduinoSerialPortManager(QObject *parent)
    : QObject{parent}
{

}

ArduinoSerialPortManager::~ArduinoSerialPortManager()
{
    if(arduino){
        arduino->close();

        delete arduino;
    }
}

void ArduinoSerialPortManager::initialize()
{

    bool arduino_is_available = false;
    QString arduino_port_name = "COM3";
    arduino = new QSerialPort();

    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            if(serialPortInfo.vendorIdentifier() == ARDUINO_VENDOR_ID){
                if(serialPortInfo.productIdentifier() == ARDUINO_PRODUCT_ID){
                    arduino_port_name = serialPortInfo.portName();
                    arduino_is_available = true;
                }
            }
        }
    }

    if(!arduino_is_available){
        throw new QException();
    }

    // Set the serial port settings
    arduino->setPortName("COM3");
    arduino->setBaudRate(QSerialPort::Baud9600);
    arduino->setDataBits(QSerialPort::Data8);
    arduino->setParity(QSerialPort::NoParity);
    arduino->setStopBits(QSerialPort::OneStop);
    arduino->setFlowControl(QSerialPort::NoFlowControl);
    qDebug() << "PORT opened: " << arduino->open(QSerialPort::WriteOnly);

    qDebug() << "Device opned";

    QByteArray byteArray;
    byteArray.append(0xFF);  // Example byte to send (ASCII value of 'A')
    arduino->write(byteArray);

}

void ArduinoSerialPortManager::change_led_state(bool state)
{


    // Write the byte array to the serial port
    state ? arduino->write("1") : arduino->write("0");


    qDebug() << "Led now: " <<state<<"\n";

}
