#ifndef NRF24L01CONTROLLER_H
#define NRF24L01CONTROLLER_H

#include <QObject>
#include <QThread>

#include "nrf24l01worker.h"
#include "3rdparty/RF24.h"
#include "3rdparty/RF24_config.h"

#define DEBUG 1


class NRF24L01Controller : public QObject
{
    Q_OBJECT



public:
    NRF24L01Controller(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed);
    void connectToRadio();
    void selectSendingPipes(uint64_t address);
    void selectRecevingPipe(uint8_t i, uint64_t address);
    void sendData(QString data);
    void startListening();
    enum {receivingData, endOfReceiving};
    int getStatus() const;

private:
    NRF24L01worker *workerObject;
    QThread *workerThread;
    RF24 * radio;
    int status;


signals:
    void onDataReceived(QString data, uint8_t pipeNum);


public slots:
    void dataReceived(QString data, uint8_t pipeNum);
    void getStatus(int status);







};

#endif // NRF24L01CONTROLLER_H
