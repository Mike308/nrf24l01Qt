#ifndef NRF24L01CONTROLLER_H
#define NRF24L01CONTROLLER_H

#include <QObject>
#include <QThread>

#include "nrf24l01worker.h"
#include "3rdparty/RF24.h"
#include "3rdparty/RF24_config.h"


class NRF24L01Controller : public QObject
{
    Q_OBJECT



public:
    NRF24L01Controller(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed);
    //    NRF24L01Controller(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed, QList<uint64_t> receivingPipesList);
    //    NRF24L01Controller(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed, QList<uint64_t> receivingPipesList, uint64_t sendingPipe);
    void connectToRadio();
    void selectSendingPipes(uint64_t address);
    void selectRecevingPipe(uint8_t i, uint64_t address);
    void sendMessage(QString message);


private:
    NRF24L01worker *workerObject;
    QThread *workerThread;
    RF24 * radio;

signals:
    void onDataReceived(QString data, uint8_t pipeNum);


public slots:

    void dataReceived(QString data, uint8_t pipeNum);







};

#endif // NRF24L01CONTROLLER_H
