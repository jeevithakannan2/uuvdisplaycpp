#include "sensorreader.h"

SensorReader::SensorReader(QObject *parent) : QObject(parent) {
    serial = new QSerialPort(this);
    // Configure the serial port, e.g., port name, baud rate, etc.
    serial->setPortName("COM3");  // Example port name, change as needed
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->open(QIODevice::ReadOnly);
    connect(serial, &QSerialPort::readyRead, this, &SensorReader::readData);
}

SensorReader::~SensorReader() {
    serial->close();
    delete serial;
}

void SensorReader::readData() {
    QByteArray data = serial->readAll();
    emit newDataAvailable(QString(data));
}
