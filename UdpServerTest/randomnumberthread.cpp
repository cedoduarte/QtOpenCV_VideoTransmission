#include "randomnumberthread.h"

#include <QRandomGenerator64>

RandomNumberThread::RandomNumberThread(QObject *parent)
    : QThread(parent)
{
}

void RandomNumberThread::run()
{
    while (true)
    {
        emit newNumber(QRandomGenerator64::global()->generate() % 101);
        QThread::msleep(500);
    }
}
