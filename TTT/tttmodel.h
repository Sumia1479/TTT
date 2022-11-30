#ifndef TTTMODEL_H
#define TTTMODEL_H

#include <QObject>

class TTTModel
{
public:
    TTTModel();

    void reset();
    void put(int row, int col);
    QString getCurrentBoard(); // "---XOXX--"
    char getWhosTurn(); // "X" or "O" or if  someone already won, return anything it does not matter
    bool hasSomeoneWon(); // return if someone has won
    char whosWinner(); // return "x" or "o" if there's a winner , return anything if there is no winner yet
    QString getGameStatus();
    void setGameStatus(QString status);
private:
    //my own data struture and booleab variable and checking logic if the game has end?
    //finsih implementation of the functions above
    QString board_status_;
    char current_turn_;
    QString game_status_;
    //TTTModel *current_box_clicked_;


};

#endif // TTTMODEL_H
