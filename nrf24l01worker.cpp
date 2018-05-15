#include "nrf24l01worker.h"

NRF24L01worker::NRF24L01worker(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed)
{
    radio = new RF24(cePin,csPin, spiSpeed);


}



NRF24L01worker::NRF24L01worker(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed, QList<uint64_t> receivingPipesList){
    radio = new RF24(cePin, csPin, spiSpeed);
    this->receivingPipesList.append(receivingPipesList);
}
NRF24L01worker::NRF24L01worker(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed, QList<uint64_t> receivingPipesList, uint64_t sendingPipe){
    radio = new RF24(cePin, csPin, spiSpeed);
    this->receivingPipesList.append(receivingPipesList);
    this->sendingPipe = sendingPipe;
}





bool NRF24L01worker::connectToRadio(){
    qDebug () << "Connecting to radio...";
    bool result = radio->begin();
    radio->printDetails();
    this->openWritePipe(sendingPipe);
    this->sendDataSlot("AT+START: "+ QTime::currentTime().toString());
    this->sendDataSlot("AT+START2: " + QTime::currentTime().toString());
    this->helper = true;
    this->receivingLoop();
    return result;
}

void NRF24L01worker::openWritePipe(uint64_t address){
    qDebug() << "Opening writing pipe: " << address;
    radio->openWritingPipe(address);
}

void NRF24L01worker::selectSendingPipes(uint64_t address){

}


void NRF24L01worker::selectRecevingPipes(int number, uint64_t  adress){

    radio->openReadingPipe(number, adress);
    qDebug() << "Selected for: " << QString::number(adress,16).toUpper()  <<"no: " << number;

}

void NRF24L01worker::sendDataSlot(QString data){
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

void NRF24L01worker::receivingLoop(){



    char msg[] = "";
    uint8_t pipeNum = 0;
    int len = 0;


    for (int i = 0; i < receivingPipesList.size(); i++){
        qDebug () << "Pipe: " << receivingPipesList[i];
        this->selectRecevingPipes(i+2, receivingPipesList[i]);
    }



    qDebug () << "Start listening...";
    radio->startListening();



    while(1){

        QThread::sleep(1);

        while(radio->available(&pipeNum) && this->helper == true){
            len = radio->getDynamicPayloadSize();
            radio->read(&msg, len);
            QString stringMsg = QString(msg);
            emit dataReceived(stringMsg, pipeNum);
            testCnt++;
       }



    }



}

void NRF24L01worker::test(){
    qDebug () << "TEST.....";
}







