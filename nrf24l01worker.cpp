#include "nrf24l01worker.h"

NRF24L01worker::NRF24L01worker(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed)
{
    radio = new RF24(cePin,csPin, spiSpeed);


}


NRF24L01worker::NRF24L01worker(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed, QList<QString> receivingPipesList){
    radio = new RF24(cePin, csPin, spiSpeed);
    this->receivingPipesList.append(receivingPipesList);
}





bool NRF24L01worker::connectToRadio(){
    qDebug () << "Connecting to radio...";
    bool result = radio->begin();
    radio->printDetails();
    this->receivingLoop();
    return result;

    
}

void NRF24L01worker::selectSendingPipes(const uint8_t *adress){
    
    radio->openWritingPipe(adress);
}


void NRF24L01worker::selectRecevingPipes(int number, const uint8_t * adress){

    radio->openReadingPipe(number, adress);

}

void NRF24L01worker::receivingLoop(){



    char msg[] = "";
    uint8_t pipeNum;
    int len = 0;

    for (int i = 0; i < receivingPipesList.size(); i++){

        qDebug () << "Pipe: " << receivingPipesList[i];
        QByteArray adress = receivingPipesList[i].toLatin1();
        this->selectRecevingPipes(i+1, (uint8_t*)receivingPipesList[i].toLocal8Bit().data());
    }

    qDebug () << "Start listening...";

    radio->startListening();


    while(1){

        while(radio->available(&pipeNum)){

            if (pipeNum == 1){
                len = radio->getDynamicPayloadSize();
                radio->read(&msg, len);
                QString stringMsg = QString(msg);
                qDebug () << "Received data from pipe 1: " << stringMsg;
                emit dataReceived(stringMsg, pipeNum);
                QThread::sleep(1);

            }else {

                len = radio->getDynamicPayloadSize();
                radio->read(&msg, len);
                QString stringMsg = QString(msg);
                qDebug () << "Received data from other one: " << stringMsg;
                emit dataReceived(stringMsg, pipeNum);
                QThread::sleep(1);


            }


        }

    }



}







