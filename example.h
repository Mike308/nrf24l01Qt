#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <QObject>
#include "nrf24l01network.h"

class Example : public QObject
{
    Q_OBJECT
public:
    explicit Example(QObject *parent = 0);
    Example(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed);
    void sendData(QString data);
    void startListening();


private:
    NRF24L01Network *network;


signals:

public slots:
    void dataReceived(QString data, QString node);
};

#endif // EXAMPLE_H
