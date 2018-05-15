#include "nrf24l01controller.h"

NRF24L01Controller::NRF24L01Controller(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed)
{
    radio = new RF24(cePin, csPin, spiSpeed);
    //    workerObject = new NRF24L01worker(cePin, csPin, spiSpeed, receivingPipesList, sendingPipe);
    //    qRegisterMetaType<uint8_t>("uint8_t");
    //    qRegisterMetaType<uint64_t>("uint64_t");
    //    connect(workerThread, SIGNAL(started()), workerObject, SLOT(connectToRadio()));
    //    connect(workerThread, SIGNAL(finished()), workerObject, SLOT(deleteLater()));
    //    connect(workerObject, SIGNAL(dataReceived(QString,uint8_t)),this,SLOT(dataReceived(QString,uint8_t)));
}




void NRF24L01Controller::connectToRadio(){
    radio->begin();
}

void NRF24L01Controller::selectRecevingPipe(uint8_t i, uint64_t address){
    radio->openReadingPipe(i, address);
}

void NRF24L01Controller::selectSendingPipes(uint64_t address){
    radio->openWritingPipe(address);
}


void NRF24L01Controller::dataReceived(QString data, uint8_t pipeNum){
    qDebug() << "Data: " << data;
    emit onDataReceived(data,pipeNum);

}


void NRF24L01Controller::sendData(QString data){
    qDebug () << "Sending data...: " << data;
    char * buf;
    QByteArray ba = data.toLatin1();
    buf = ba.data();
    radio->stopListening();
    radio->powerDown();
    radio->powerUp();
    radio->write(buf, 128);
    radio->startListening();
}

void NRF24L01Controller::startListening(){
    radio->startListening();
    workerObject = new NRF24L01worker(radio);
    workerThread = new QThread();
    workerObject->moveToThread(workerThread);
    qRegisterMetaType<uint8_t>("uint8_t");
    connect(workerThread, SIGNAL(started()), workerObject, SLOT(receivingLoop()));
    connect(workerThread, SIGNAL(finished()), workerObject, SLOT(deleteLater()));
    connect(workerObject, SIGNAL(dataReceived(QString,uint8_t)), this, SLOT(dataReceived(QString,uint8_t)));
    workerThread->start();
}















