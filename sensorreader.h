#ifndef SENSORREADER_H
#define SENSORREADER_H

#include <QObject>
#include <QSerialPort>

class SensorReader : public QObject {
    Q_OBJECT

public:
    SensorReader(QObject *parent = nullptr);
    ~SensorReader();

signals:
    void newDataAvailable(const QString &data);

public slots:
    void readData();

private:
    QSerialPort *serial;
};

#endif // SENSORREADER_H
