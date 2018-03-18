#include "nrf24l01worker.h"

NRF24L01worker::NRF24L01worker(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed)
{
    radio = new RF24(cePin,csPin, spiSpeed);
    this->radioConnected = false;


}


bool NRF24L01worker::connectToRadio(){
    qDebug () << "Connecting to radio...";
    radio->begin();
    radio->printDetails();
    this->receivingLoop();

    
}

void NRF24L01worker::selectSendingPipes(const uint8_t *adress){
    
    radio->openWritingPipe(adress);
}

void NRF24L01worker::selectRecevingPipes(int number, const uint64_t adress){
    
    radio->openReadingPipe(number, adress);
}

void NRF24L01worker::receivingLoop(){



    char msg[] = "";
    int ReceivedMessage[1] = {000};
    int len = 0;
    qDebug () << "Start listening...";
    radio->startListening();


    while(1){

        while(radio->available()){

            len = radio->getDynamicPayloadSize();
            radio->read(&msg, len);
            QString stringMsg = QString(msg);
            qDebug () << "Received data: " << stringMsg;
            emit dataReceived(stringMsg, 0);
            QThread::sleep(1);


        }

    }



}







