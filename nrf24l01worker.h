#ifndef NRF24L01WORKER_H
#define NRF24L01WORKER_H

#include <QObject>
#include "3rdparty/RF24.h"
#include "3rdparty/RF24_config.h"

class nrf24l01Worker : public QObject
{
    Q_OBJECT
public:
    explicit nrf24l01Worker(QObject *parent = 0);

signals:

public slots:
    bool connectToRadio(uint16_t cePin, uint16_t csPin);
    void selectSendingPipes(int number, const uint8_t * adress);
    void selectRecevingPipes(int number, const uint8_t * adress);
    bool isAvailable();
    bool isAvailable(uint8_t *pipeNum);






};

#endif // NRF24L01WORKER_H
