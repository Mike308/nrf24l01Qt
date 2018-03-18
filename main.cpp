#include <QCoreApplication>

#include "nrf24l01controller.h"
//#include "3rdparty/RF24.h"
//#include "3rdparty/RF24_config.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const uint64_t pipeAdress = 0xE6E6E6E6E6E6; // Needs to be the same for communicating between 2 NRF24L01

//    RF24 radio(RPI_V2_GPIO_P1_15, RPI_V2_GPIO_P1_24, BCM2835_SPI_SPEED_8MHZ);
//    radio.begin();

//    radio.available()

    NRF24L01Controller radio(RPI_V2_GPIO_P1_15, RPI_V2_GPIO_P1_24, BCM2835_SPI_SPEED_8MHZ);
    radio.connectToRadio();
    radio.selectRecevingPipes(1, pipeAdress);



    return a.exec();
}
