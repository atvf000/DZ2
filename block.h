#ifndef BLOCK_H
#define BLOCK_H
#include <QMainWindow>


class block
{
     QVector<QVector<int>> A;
public:
    block();
    void addN(QVector<QVector<int>> &A);
    bool isEmpty(int a);
    QVector<QVector<int>> getBlock();
    void move(QVector<int> &A);
    void setBlock( QVector<QVector<int>> B);
};

#endif // BLOCK_H
