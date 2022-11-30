#include "tttmodel.h"
#include <iostream>
TTTModel::TTTModel():current_turn_{'X'},board_status_{"---------"},game_status_{"Begin"}{
    //reset();
}

void TTTModel::reset(){
    current_turn_ = 'X';
    board_status_ = "---------";
    game_status_ = "Play";

}
void TTTModel::put(int row, int col){
    if(row == 0 && col == 0 && board_status_[0] == '-'){
       board_status_[0] = getWhosTurn();
       if(getWhosTurn() == 'X' && hasSomeoneWon() == false) {
           current_turn_ = 'O';
       }
       else if(getWhosTurn() == 'O' && hasSomeoneWon() == false){
           current_turn_ = 'X';
       }

    }
    else if(row == 0 && col == 1 && board_status_[1] == '-'){
       board_status_[1] = getWhosTurn();
       if(getWhosTurn() == 'X' && hasSomeoneWon() == false) {
           current_turn_ = 'O';
       }
       else if(getWhosTurn() == 'O' && hasSomeoneWon() == false){
           current_turn_ = 'X';
       }
    }
    else if(row == 0 && col == 2 &&  board_status_[2] == '-'){
       board_status_[2] = getWhosTurn();
       if(getWhosTurn() == 'X' && hasSomeoneWon() == false) {
           current_turn_ = 'O';
       }
       else if(getWhosTurn() == 'O' && hasSomeoneWon() == false){
           current_turn_ = 'X';
       }
    }
    else if(row == 1 && col == 0 && board_status_[3] == '-'){
       board_status_[3] = getWhosTurn();
       if(getWhosTurn() == 'X' && hasSomeoneWon() == false) {
           current_turn_ = 'O';
       }
       else if(getWhosTurn() == 'O' && hasSomeoneWon() == false){
           current_turn_ = 'X';
       }
    }
    else if(row == 1 && col == 1 &&  board_status_[4] == '-'){
       board_status_[4] = getWhosTurn();
       if(getWhosTurn() == 'X' && hasSomeoneWon() == false) {
           current_turn_ = 'O';
       }
       else if(getWhosTurn() == 'O' && hasSomeoneWon() == false){
           current_turn_ = 'X';
       }
    }
    else if(row == 1 && col == 2 &&  board_status_[5] == '-'){
       board_status_[5] = getWhosTurn();
       if(getWhosTurn() == 'X' && hasSomeoneWon() == false) {
           current_turn_ = 'O';
       }
       else if(getWhosTurn() == 'O' && hasSomeoneWon() == false){
           current_turn_ = 'X';
       }
    }

    else if(row == 2 && col == 0 &&  board_status_[6] == '-'){
       board_status_[6] = getWhosTurn();
       if(getWhosTurn() == 'X' && hasSomeoneWon() == false) {
           current_turn_ = 'O';
       }
       else if(getWhosTurn() == 'O' && hasSomeoneWon() == false){
           current_turn_ = 'X';
        }
    }
    else if(row == 2 && col == 1 &&  board_status_[7] == '-'){
       board_status_[7] = getWhosTurn();
       if(getWhosTurn() == 'X' && hasSomeoneWon() == false) {
           current_turn_ = 'O';
       }
       else if(getWhosTurn() == 'O' && hasSomeoneWon() == false){
           current_turn_ = 'X';
        }
    }

       else if(row == 2 && col == 2 &&  board_status_[8] == '-'){
       board_status_[8] = getWhosTurn();

       if(getWhosTurn() == 'X' && hasSomeoneWon() == false) {
           current_turn_ = 'O';
       }
       else if(getWhosTurn() == 'O' && hasSomeoneWon() == false){
           current_turn_ = 'X';
       }
    }

}

QString TTTModel::getCurrentBoard(){
    return board_status_;
}

char TTTModel::getWhosTurn(){
    return current_turn_;

} // "X" or "O" or if  someone already won, return anything it does not matter

bool TTTModel::hasSomeoneWon(){
    // Rows
    if (board_status_[0] != '-' && board_status_[0] == board_status_[1] && board_status_[1] == board_status_[2]) return true;
    if (board_status_[3] != '-' && board_status_[3] == board_status_[4] && board_status_[4] == board_status_[5]) return true;
    if (board_status_[6] != '-' && board_status_[6] == board_status_[7] && board_status_[7] == board_status_[8]) return true;
    // Columns
    if (board_status_[0] != '-' && board_status_[0] == board_status_[3] && board_status_[3] == board_status_[6]) return true;
    if (board_status_[1] != '-' && board_status_[1] == board_status_[4] && board_status_[4] == board_status_[7]) return true;
    if (board_status_[2] != '-' && board_status_[2] == board_status_[5] && board_status_[5] == board_status_[8]) return true;

    // Diagonals
    if (board_status_[0] != '-' && board_status_[0] == board_status_[4] && board_status_[4] == board_status_[8]) return true;
    if (board_status_[2] != '-' && board_status_[2] == board_status_[4] && board_status_[4] == board_status_[6]) return true;

    //tie
    bool tie = true;
    for(int i = 0; i < board_status_.size();i++){
        if(board_status_[i] == '-') tie = false;
    }
    if(tie) game_status_ = "Tie";
    return false;
} // return if someone has won

char TTTModel::whosWinner(){
    if(hasSomeoneWon()){
        return getWhosTurn();
    }
    return ' ';
} // return "x" or "o" if there's a winner , return anything if there is no winner yet

QString TTTModel::getGameStatus(){
    return game_status_;
}

void TTTModel::setGameStatus(QString status){
    game_status_ = status;

}
