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

private:
     RF24 * radio;
     void receivingLoop();

     


signals:
     void dataReceived(QString data, uint8_t pipeNum);

public slots:
    bool connectToRadio();
    void selectSendingPipes(const uint8_t * adress);
    void selectRecevingPipes(int number, const uint64_t adress);

    










};

#endif // NRF24L01WORKER_H
