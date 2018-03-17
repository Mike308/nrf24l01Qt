#ifndef NRF24L01WORKER_H
#define NRF24L01WORKER_H

#include <QObject>
#include <QThread>

#include "3rdparty/RF24.h"
#include "3rdparty/RF24_config.h"

class nrf24l01Worker : public QObject
{
    Q_OBJECT
public:
     nrf24l01Worker(uint16_t cePin, uint16_t csPin, uint32_t spiSpeed);

private:
     RF24 * radio;
     QThread *radioThread;
     bool isAvailable();
     bool isAvailable(uint8_t *pipeNum);


signals:
     void dataReceived(QString data, uint8_t pipeNum);

public slots:
    bool connectToRadio();
    void selectSendingPipes(const uint8_t * adress);
    void selectRecevingPipes(int number, const uint8_t * adress);










};

#endif // NRF24L01WORKER_H
