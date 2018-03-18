#include "nrf24l01controller.h"

NRF24L01Controller::NRF24L01Controller(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed)
{
    workerObject = new NRF24L01worker(cePin, csPin, spiSpeed);
    workerThread = new QThread();
    workerObject->moveToThread(workerThread);

    connect(workerThread, SIGNAL(started()), workerObject, SLOT(connectToRadio()));
    connect(workerThread, SIGNAL(finished()), workerObject, SLOT(deleteLater()));

    connect(this, SIGNAL(connectToRadioSignal()), workerObject, SLOT(connectToRadio()));
    connect(this, SIGNAL(selectSendingPipesSignal(const uint8_t*)), workerObject, SLOT(selectSendingPipes(const uint8_t*)));
    connect(this, SIGNAL(selectRecevingPipesSingal(int,const uint64_t)), workerObject, SLOT(selectRecevingPipes(int,const uint64_t)));




}



bool NRF24L01Controller::connectToRadio(){

    workerThread->start();



}

void NRF24L01Controller::selectSendingPipes(const uint8_t *adress){

    emit selectSendingPipesSignal(adress);
}

void NRF24L01Controller::selectRecevingPipes(int number, const uint64_t adress){

    emit selectRecevingPipesSingal(number, adress);

}




