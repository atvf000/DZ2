#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "block.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
   void print();
   int pow (int a, int b);
   void create();
   void moveR();
   void moveL();
   void move(int (&B)[4]);
   void addN();
   void moveU();
   void moveD();
   bool isEmpty(int a);
   int isEnd();
   void keyPressEvent(QKeyEvent *event);


private slots:
   void on_cheat_clicked();

   void on_restart_clicked();

   void on_exit_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
