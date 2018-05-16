#include "example.h"

Example::Example(QObject *parent) : QObject(parent)
{

}

Example::Example(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed){
    network = new NRF24L01Network(cePin, csPin, spiSpeed);
    connect(network, SIGNAL(receivedMessageFromNode(QString,QString)), this, SLOT(dataReceived(QString,QString)));
    network->connectToRadio();
    network->selectRecevingPipe(1, 0xF0F0F0F0F101);
    network->selectSendingPipes(0xF0F0F0F0E101);
    network->updateNodeAddressList("dhtNode");

}

void Example::sendData(QString data){
    network->sendData(data);
}

void Example::startListening(){
    network->startListening();
}

void Example::dataReceived(QString data, QString node){
    qDebug () << "Received data from node: " << node << "|" << data;
}







