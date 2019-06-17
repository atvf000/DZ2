#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QTime>
#include <QKeyEvent>
#include <algorithm>

    int A[4][4];
    int score = 0;
    int end = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(600,800);
    this->setFixedSize(600,800);
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));

    QPixmap bg(":/source/source/background.jpg");
    ui->background->setPixmap(bg);
    ui->cheat->setStyleSheet("QPushButton{background:#ECC400; color: white}");
    ui->restart->setStyleSheet("QPushButton{background:#EF9960; color: white}");
    ui->exit->setStyleSheet("QPushButton{background:#EF9960; color: white}");

    create();
    print();

}

int MainWindow::isEnd()
{
    int e = 0;
    int f = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            if (A[i][j] == 11)
                return 1;
            if (A[i][j] == 0)
                e++;
        }

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            if (i != 0)
                if (A[i-1][j] == A[i][j])
                    f++;
            if (i != 3)
                if (A[i+1][j] == A[i][j])
                    f++;
            if (j != 0)
                if (A[i][j-1] == A[i][j])
                    f++;
            if (j != 3)
                if (A[i][j+1] == A[i][j])
                    f++;
        }
    if (e == 0 && f == 0)
        return -1;
    else
        return 0;
}

 int MainWindow::pow (int a, int b)
 {
     int res = 1;
     for (int i = 0; i < b; i++)
         res *=a;
     return res;
 }

void MainWindow::print()
{
     QPixmap b[16];
     for (int i = 0, k = 0; i < 4; i++)
         for  (int j = 0; j < 4; j++)
         {
          QString path = ":/source/source/" + (QString::fromStdString(std::to_string((pow(2,A[i][j])))))+ ".jpg";
             b[k] = QPixmap(path);
             k++;
         }

    ui->b11->setPixmap(b[0]);
    ui->b12->setPixmap(b[1]);
    ui->b13->setPixmap(b[2]);
    ui->b14->setPixmap(b[3]);
    ui->b21->setPixmap(b[4]);
    ui->b22->setPixmap(b[5]);
    ui->b23->setPixmap(b[6]);
    ui->b24->setPixmap(b[7]);
    ui->b31->setPixmap(b[8]);
    ui->b32->setPixmap(b[9]);
    ui->b33->setPixmap(b[10]);
    ui->b34->setPixmap(b[11]);
    ui->b41->setPixmap(b[12]);
    ui->b42->setPixmap(b[13]);
    ui->b43->setPixmap(b[14]);
    ui->b44->setPixmap(b[15]);
    ui->score->setStyleSheet("QLabel {color : white; }");
    ui->score->setText(QString::fromStdString(std::to_string(score)));
}

void MainWindow::moveR()
{
    for (int k = 0; k < 4; k++)
        move(A[k]);
    addN();
    print();

    end = isEnd();
    if (end == 1)
    {
        QPixmap w(":/source/source/win.png");
        ui->win->setPixmap(w);
        return;
    }
    else if (end == -1)
    {
        QPixmap w(":/source/source/lose.png");
        ui->win->setPixmap(w);
        return;
    }
}

void MainWindow::moveL()
{
    for (int k = 0; k < 4; k++)
    {
        int B[4];
        for (int i = 0; i < 4; i++)
            B[i]=A[k][3-i];
        move(B);
        for (int i = 0; i < 4; i++)
            A[k][3-i]=B[i];
    }
    addN();
    print();

    end = isEnd();
    if (end == 1)
    {
        QPixmap w(":/source/source/win.png");
        ui->win->setPixmap(w);
        return;
    }
    else if (end == -1)
    {
        QPixmap w(":/source/source/lose.png");
        ui->win->setPixmap(w);
        return;
    }
}

void MainWindow::moveD()
{
    for (int k = 0; k < 4; k++)
    {
        int B[4];
        for (int i = 0; i < 4; i++)
            B[i]=A[i][k];
        move(B);
        for (int i = 0; i < 4; i++)
            A[i][k]=B[i];
    }
    addN();
    print();

    end = isEnd();
    if (end == 1)
    {
        QPixmap w(":/source/source/win.png");
        ui->win->setPixmap(w);
        return;
    }
    else if (end == -1)
    {
        QPixmap w(":/source/source/lose.png");
        ui->win->setPixmap(w);
        return;
    }

}

void MainWindow::moveU()
{
    for (int k = 0; k < 4; k++)
    {
        int B[4];
        for (int i = 0; i < 4; i++)
            B[i]=A[3-i][k];
        move(B);
        for (int i = 0; i < 4; i++)
            A[3-i][k]=B[i];
    }
    addN();
    print();

    end = isEnd();
    if (end == 1)
    {
        QPixmap w(":/source/source/win.png");
        ui->win->setPixmap(w);
    }
    else if (end == -1)
    {
        QPixmap w(":/source/source/lose.png");
        ui->win->setPixmap(w);
    }
}

void MainWindow::move(int (&B)[4])
{
    for(int i = 0; i < 4;i++)
    {
        if (B[i] == 0)
            for (int j = i; j > 0; j--)
                std::swap(B[j],B[j-1]);
    }

    for (int i = 3; i > 0; i--)
        if (B[i-1] == B[i] && B[i] != 0)
        {
            pow(2,B[i]);
            B[i] += 1;
            B[i-1] = 0;
            i--;
        }

    for(int i = 0; i < 4;i++)
    {
        if (B[i] == 0)
            for (int j = i; j > 0; j--)
                std::swap(B[j],B[j-1]);
    }
}

bool MainWindow::isEmpty(int a)
{
    if (a == 0)
        return true;
    else
        return false;
}

void MainWindow::addN()
{
    int x;
    int y;
   bool e = false;

   while (!e)
   {
      x = qrand()%4;
      y = qrand()%4;
      e = isEmpty(A[x][y]);
   }

   A[x][y] = qrand()%2 + 1;
   score += pow(2,A[x][y]);
}

void MainWindow::create()
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            A[i][j] = 0;

    for (int k = 0; k < 2; k++)
        addN();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (end == 0)
    {
    if (event->key() == Qt::Key_D)
        moveR();
    if (event->key() == Qt::Key_A)
        moveL();
    if (event->key() == Qt::Key_W)
        moveU();
    if (event->key() == Qt::Key_S)
        moveD();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_cheat_clicked()
{
    A[0][0] = 10;
    A[0][1] = 10;
    print();
}

void MainWindow::on_restart_clicked()
{
    ui->win->clear();
     score = 0;
     end = 0;
     create();
     print();
}

void MainWindow::on_exit_clicked()
{
    close();
}
