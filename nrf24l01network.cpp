#include "nrf24l01network.h"

NRF24L01Network::NRF24L01Network(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed) : NRF24L01Controller(cePin, csPin, spiSpeed)
{
    connect(this, SIGNAL(onDataReceived(QString,uint8_t)), this, SLOT(receiveMessage(QString,uint8_t)));
}

void NRF24L01Network::updateNodeAddressList(QString nodeAddress){
    this->nodeAdressList.append(nodeAddress);
}

void NRF24L01Network::receiveMessage(QString data, uint8_t pipeNum){
    QStringList items = data.split("|");
    if (this->nodeAdressList.contains(items.at(0))) emit receivedMessageFromNode(items.at(1), items.at(0));
//    qDebug () << "Received data from node "<< pipeNum << ":" << data << "at: " << QTime::currentTime().toString();
}








