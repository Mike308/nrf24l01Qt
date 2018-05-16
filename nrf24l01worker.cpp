#include "nrf24l01worker.h"


NRF24L01worker::NRF24L01worker(RF24 * radio){
    this->radio = radio;
}



void NRF24L01worker::receivingLoop(){



    char msg[] = "";
    uint8_t pipeNum = 0;
    int len = 0;
    qDebug() << "Start listening";
    while(1){

        while(radio->available(&pipeNum)){
            len = radio->getDynamicPayloadSize();
            radio->read(&msg, len);
            QString stringMsg = QString(msg);
            emit updatedStatus(receivingData);
            emit dataReceived(stringMsg, pipeNum);

        }

        emit updatedStatus(receivingFinished);
        QThread::sleep(1);


    }



}









