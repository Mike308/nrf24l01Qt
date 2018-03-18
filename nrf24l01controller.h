#ifndef NRF24L01CONTROLLER_H
#define NRF24L01CONTROLLER_H

#include <QObject>
#include <QThread>

#include "nrf24l01worker.h"


class NRF24L01Controller : public QObject
{
    Q_OBJECT



public:
    NRF24L01Controller(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed);
    bool connectToRadio();
    void selectSendingPipes(const uint8_t * adress);
    void selectRecevingPipes(int number, const uint64_t  adress);

private:
    NRF24L01worker *workerObject;
    QThread *workerThread;

signals:

    bool connectToRadioSignal();
    void selectSendingPipesSignal(const uint8_t * adress);
    void selectRecevingPipesSingal(int number, const uint64_t adress);







};

#endif // NRF24L01CONTROLLER_H
