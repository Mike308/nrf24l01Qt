#ifndef NRF24L01WORKER_H
#define NRF24L01WORKER_H

#include <QObject>
#include <QThread>
#include <QDebug>

#include "3rdparty/RF24.h"
#include "3rdparty/RF24_config.h"

class NRF24L01worker : public QObject
{
    Q_OBJECT
public:
     NRF24L01worker(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed);
     NRF24L01worker(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed, uint64_t * receivingPipes);
     NRF24L01worker(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed, QList<QString> receivingPipesList);
     NRF24L01worker(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed, uint64_t * receivingPipes, uint64_t * sendingPipes);


private:
     RF24 * radio;
     QList <QString>  receivingPipesList;
     int cnt = 0;
     void selectRecevingPipes(int number, const uint8_t * adress);
     void receivingLoop();
     void setRecevingPipes();



     


signals:
     void dataReceived(QString data, uint8_t pipeNum);

public slots:
    bool connectToRadio();
    void selectSendingPipes(const uint8_t * adress);


    










};

#endif // NRF24L01WORKER_H
