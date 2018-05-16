#include <QCoreApplication>
#include "example.h"




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    QList <QString> pipesList;
//    pipesList.append("temperatureNode");
//    pipesList.append("humidityNode");
   // QList<uint64_t> pipesList;
    //pipesList.append(0xF0F0F0F0E101);
    //pipesList.append(0xF0F0F0F0F101);
   // qDebug () << "Reading from adress: " << pipesList;
    //NRF24L01Network radio(RPI_V2_GPIO_P1_15, BCM2835_SPI_CS0, BCM2835_SPI_SPEED_8MHZ, pipesList, 0xF0F0F0F0E101);
//    NRF24L01Controller radio(RPI_V2_GPIO_P1_15, BCM2835_SPI_CS0, BCM2835_SPI_SPEED_8MHZ);
//    radio.connectToRadio();
//    radio.selectSendingPipes(0xF0F0F0F0E101);
//    radio.selectRecevingPipe(1, 0xF0F0F0F0F101);
//    radio.sendData("Test1");
//    radio.sendData("Test2");
//    radio.startListening();

    Example example(RPI_V2_GPIO_P1_15, BCM2835_SPI_CS0, BCM2835_SPI_SPEED_8MHZ);
    example.sendData("Test att");
    example.startListening();

    qDebug () << "Test...";




    return a.exec();
}
