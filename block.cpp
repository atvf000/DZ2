#include "block.h"
#include <QMainWindow>
#include <algorithm>


bool block::isEmpty(int a)
{
    if (a == 0)
        return true;
    else
        return false;
}

 void block::addN(QVector<QVector<int>> &A)
{
    bool e = false;
    int x = qrand()%4;
    int y = qrand()%4;
    A[x][y];

    while (!e)
       e = isEmpty(A[x][y]);

    A[x][y] = qrand()%2 + 1;
}

QVector<QVector<int>> block::getBlock()
{
    return A;
}

void block::move(QVector<int> &B)
{
    for (int i = 0; i < 4; i++)
        if (B[i] == 0)
            for (int j = i; j != 0; j--)
                std::swap(B[j],B[j-1]);

    for (int i = 0; i < 3; i++)
        if (B[i] == B[i+1])
        {
            B[i+1] += 1;
            B[i] = 0;
            i++;
        }

    for (int i = 0; i < 4; i++)
        if (B[i] == 0)
            for (int j = i; j != 0; j--)
                std::swap(B[j],B[j-1]);
}

void block::setBlock(QVector<QVector<int> > B)
{
    A = B;
}

