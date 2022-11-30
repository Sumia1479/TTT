#include "tictactoewindow.h"
#include "./ui_tictactoewindow.h"

TicTacToeWindow::TicTacToeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TicTacToeWindow),
      tttModel(new TTTModel)
{
    ui->setupUi(this);
    updateScreen();

}

TicTacToeWindow::~TicTacToeWindow()
{
    delete ui;
}

void TicTacToeWindow::updateScreen(){

    QString cur = tttModel->getCurrentBoard();
    ui->board00->setText(cur[0]);
    ui->board01->setText(cur[1]);
    ui->board02->setText(cur[2]);
    ui->board10->setText(cur[3]);
    ui->board11->setText(cur[4]);
    ui->board12->setText(cur[5]);
    ui->board20->setText(cur[6]);
    ui->board21->setText(cur[7]);
    ui->board22->setText(cur[8]);

    //ui->boardLabel->setText(cur.left(3) + '\n' + cur.mid(3,3) + '\n' + cur.right(3));
    //if someone has won?
    if(tttModel->hasSomeoneWon()){
        QString msg = "";
        msg.push_back(tttModel->whosWinner());
        msg.push_back(" has Won! Press rest for a new game");
        ui->IBStatusLabel->setText(msg);
    }
    else{
        // no winner yet
        QString msg = "";
        msg.push_back(tttModel->getWhosTurn());
        msg.push_back( "'s turn");
        ui->IBStatusLabel->setText(msg);
    }
    if(tttModel->hasSomeoneWon() == false && tttModel->getGameStatus() == "Tie"){
        ui->IBStatusLabel->setText("Tie! Press Reset to Try again!");
    }
}


void TicTacToeWindow::on_board00_clicked(){
    tttModel->put(0,0);
    tttModel->setGameStatus("PlAY");
    updateScreen();
}


void TicTacToeWindow::on_board01_clicked(){
      tttModel->put(0,1);
      tttModel->setGameStatus("PlAY");
      updateScreen();
}


void TicTacToeWindow::on_board02_clicked(){
    tttModel->put(0,2);
    tttModel->setGameStatus("PlAY");
    updateScreen();
}


void TicTacToeWindow::on_board10_clicked(){
    tttModel->put(1,0);
    tttModel->setGameStatus("PlAY");
    updateScreen();
}


void TicTacToeWindow::on_board11_clicked(){
     tttModel->put(1,1);
     tttModel->setGameStatus("PlAY");
     updateScreen();
}


void TicTacToeWindow::on_board12_clicked(){
     tttModel->put(1,2);
     tttModel->setGameStatus("PlAY");
     updateScreen();
}


void TicTacToeWindow::on_board20_clicked(){
     tttModel->put(2,0);
     tttModel->setGameStatus("PlAY");
     updateScreen();
}


void TicTacToeWindow::on_board21_clicked(){
     tttModel->put(2,1);
     tttModel->setGameStatus("PlAY");
     updateScreen();
}


void TicTacToeWindow::on_board22_clicked(){
     tttModel->put(2,2);
     tttModel->setGameStatus("PlAY");
     updateScreen();
}


void TicTacToeWindow::on_Reset_Button_clicked(){
    tttModel->reset();
    //do some clean up work for your UI
    updateScreen();

}

