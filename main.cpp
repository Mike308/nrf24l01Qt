#include <QCoreApplication>
#include "nrf24l01controller.h"




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList <QString> pipesList;
    pipesList.append("temperatureNode");
    NRF24L01Controller radio(RPI_V2_GPIO_P1_15, RPI_V2_GPIO_P1_24, BCM2835_SPI_SPEED_8MHZ, pipesList);
    radio.connectToRadio();




    return a.exec();
}
