#ifndef NRF24L01WORKER_H
#define NRF24L01WORKER_H

#include <QObject>

class nrf24l01Worker : public QObject
{
    Q_OBJECT
public:
    explicit nrf24l01Worker(QObject *parent = 0);

signals:

public slots:
};

#endif // NRF24L01WORKER_H