#ifndef NRF24L01WORKER_H
#define NRF24L01WORKER_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QTime>

#include "3rdparty/RF24.h"
#include "3rdparty/RF24_config.h"



class NRF24L01worker : public QObject
{
    Q_OBJECT
public:
     NRF24L01worker(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed);
     NRF24L01worker(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed, uint64_t * receivingPipes);
     NRF24L01worker(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed, QList<uint64_t> receivingPipesList);
     NRF24L01worker(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed, QList<uint64_t> receivingPipesList, uint64_t sendingPipe);
     NRF24L01worker(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed, uint64_t * receivingPipes, uint64_t * sendingPipes);


private:
     RF24 * radio;
     QList <uint64_t> receivingPipesList;
     int cnt = 0;
     int testCnt = 0;
     void selectRecevingPipes(int number, uint64_t adress);
     void receivingLoop();
     void setRecevingPipes();
     uint64_t sendingPipe;
     bool helper;
     void openWritePipe(uint64_t address);



     


signals:
     void dataReceived(QString data, uint8_t pipeNum);

public slots:
    bool connectToRadio();
    void selectSendingPipes(uint64_t  adress);
    void sendDataSlot(QString data);
    void test();



    










};

#endif // NRF24L01WORKER_H
