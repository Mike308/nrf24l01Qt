#include "nrf24l01worker.h"

nrf24l01Worker::nrf24l01Worker(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed)
{
    radio = new RF24(cePin,csPin, spiSpeed);
}


bool nrf24l01Worker::connectToRadio(uint16_t cePin, uint16_t csPin){
    
    radio->begin();
    
}

void nrf24l01Worker::selectSendingPipes(const uint8_t *adress){
    
    radio->openWritingPipe(adress);
}

void nrf24l01Worker::selectRecevingPipes(int number, const uint8_t *adress){
    
    radio->openReadingPipe(number, adress);
}

void nrf24l01Worker::receivingLoop(){

    char msg[] = " ";
    int len = 0;

    while(1){

        while(radio->available()){

            len = radio->getDynamicPayloadSize();
            radio->read(&msg, len);
            QString stringMsg = QString(msg);



        }

    }

}




