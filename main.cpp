#include <QCoreApplication>

#include "3rdparty/RF24.h"
#include "3rdparty/utility/includes.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    RF24 radio(RPI_V2_GPIO_P1_15, RPI_V2_GPIO_P1_24, BCM2835_SPI_SPEED_8MHZ);
    radio.begin();
    radio.open

    radio.available()


    return a.exec();
}
