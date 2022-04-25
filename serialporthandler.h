#ifndef SERIALPORTHANDLER_H
#define SERIALPORTHANDLER_H

#include <QObject>
#include <QSerialPort>

class SerialPortHandler : public QObject
{
    Q_OBJECT

    QSerialPort SerialPort;
public:
    explicit SerialPortHandler(QObject *parent = nullptr);

public slots:
    void ShowSerialPorts();
    void PrintData();
    void SendData();

signals:
    QString SendSignal();
    void PrintSignal(QString Data);

public slots:
};

#endif // SERIALPORTHANDLER_H
