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
    NRF24L01Controller(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed, QList<uint64_t> receivingPipesList);
    NRF24L01Controller(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed, QList<uint64_t> receivingPipesList, uint64_t sendingPipe);



private:
    NRF24L01worker *workerObject;
    QThread *workerThread;

signals:

    bool connectToRadioSignal();
    void selectSendingPipesSignal(uint64_t address);
    void selectRecevingPipesSingal(int number, const uint64_t adress);
    void selectRecevingPipesSingal(int number, const uint8_t * adress);
    void onDataReceived(QString data, uint8_t pipeNum);
    void sendMessageSignal(QString message);
    void testSingal();

public slots:

    void dataReceived(QString data, uint8_t pipeNum);
    void connectToRadio();
    void selectSendingPipes(uint64_t address);
    void sendMessage(QString message);
    void testSlot();






};

#endif // NRF24L01CONTROLLER_H
