#include "nrf24l01controller.h"

NRF24L01Controller::NRF24L01Controller(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed)
{
    radio = new RF24(cePin, csPin);
//    workerObject = new NRF24L01worker(cePin, csPin, spiSpeed, receivingPipesList, sendingPipe);
//    qRegisterMetaType<uint8_t>("uint8_t");
//    qRegisterMetaType<uint64_t>("uint64_t");
//    connect(workerThread, SIGNAL(started()), workerObject, SLOT(connectToRadio()));
//    connect(workerThread, SIGNAL(finished()), workerObject, SLOT(deleteLater()));
//    connect(workerObject, SIGNAL(dataReceived(QString,uint8_t)),this,SLOT(dataReceived(QString,uint8_t)));
}



//NRF24L01Controller::NRF24L01Controller(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed, QList<uint64_t> receivingPipesList){
//    qRegisterMetaType<uint8_t>("uint8_t");
//    qRegisterMetaType<uint64_t>("uint64_t");
//    workerObject = new NRF24L01worker(cePin, csPin, spiSpeed, receivingPipesList);
//    workerThread = new QThread();
//    workerObject->moveToThread(workerThread);
//    connect(workerThread, SIGNAL(started()), workerObject, SLOT(connectToRadio()));
//    connect(workerThread, SIGNAL(finished()), workerObject, SLOT(deleteLater()));
//    connect(this, SIGNAL(connectToRadioSignal()), workerObject, SLOT(connectToRadio()));
//    connect(this, SIGNAL(selectSendingPipesSignal(uint64_t)), workerObject, SLOT(selectSendingPipes(uint64_t)));
//    connect(workerObject, SIGNAL(dataReceived(QString,uint8_t)),this,SLOT(dataReceived(QString,uint8_t)));
//}

//NRF24L01Controller::NRF24L01Controller(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed, QList<uint64_t> receivingPipesList, uint64_t sendingPipe){
//    qDebug () << "Constructor with sending pipe...";
//    radio = new RF24(cePin, csPin);
//    workerObject = new NRF24L01worker(cePin, csPin, spiSpeed, receivingPipesList, sendingPipe);
//    qRegisterMetaType<uint8_t>("uint8_t");
//    qRegisterMetaType<uint64_t>("uint64_t");
//    connect(workerThread, SIGNAL(started()), workerObject, SLOT(connectToRadio()));
//    connect(workerThread, SIGNAL(finished()), workerObject, SLOT(deleteLater()));
//    connect(workerObject, SIGNAL(dataReceived(QString,uint8_t)),this,SLOT(dataReceived(QString,uint8_t)));
//}

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
    emit onDataReceived(data,pipeNum);

}



void NRF24L01Controller::sendMessage(QString message){
    qDebug () << "Sending data...: " << message;
    char * buf;
    QByteArray ba = message.toLatin1();
    buf = ba.data();
    radio->stopListening();
    radio->powerDown();
    radio->powerUp();
    radio->write(buf, 128);
    radio->startListening();
}











