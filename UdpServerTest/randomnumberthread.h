#ifndef RANDOMNUMBERTHREAD_H
#define RANDOMNUMBERTHREAD_H

#include <QThread>

class RandomNumberThread : public QThread
{
    Q_OBJECT
public:
    RandomNumberThread(QObject *parent = nullptr);
signals:
    void newNumber(int number);
protected:
    void run() override;
};

#endif // RANDOMNUMBERTHREAD_H
