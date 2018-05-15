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
    NRF24L01worker(RF24 * radio);

private:
    RF24 * radio;

signals:
    void dataReceived(QString data, uint8_t pipeNum);

public slots:
    void receivingLoop();




    










};

#endif // NRF24L01WORKER_H
