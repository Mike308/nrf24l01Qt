#ifndef NRF24L01NETWORK_H
#define NRF24L01NETWORK_H

#include <QDebug>

#include "nrf24l01controller.h"


class NRF24L01Network : public NRF24L01Controller
{
    Q_OBJECT

public:
    NRF24L01Network(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed);
    void updateNodeAddressList(QString nodeAddress);
private:
    QList<QString> nodeAdressList;


signals:
    void receivedMessageFromNode(QString data, QString nodeAddress);

public slots:
    void receiveMessage(QString data, uint8_t pipeNum);

};

#endif // NRF24L01NETWORK_H
