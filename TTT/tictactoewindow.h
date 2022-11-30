#ifndef TICTACTOEWINDOW_H
#define TICTACTOEWINDOW_H

#include <QMainWindow>
#include "tttmodel.h"
QT_BEGIN_NAMESPACE
namespace Ui { class TicTacToeWindow; }
QT_END_NAMESPACE

class TicTacToeWindow : public QMainWindow
{
    Q_OBJECT

public:
    TicTacToeWindow(QWidget *parent = nullptr);
    ~TicTacToeWindow();

private slots:
    void on_board00_clicked();
    void on_board01_clicked();
    void on_board02_clicked();
    void on_board10_clicked();
    void on_board11_clicked();
    void on_board12_clicked();
    void on_board20_clicked();
    void on_board21_clicked();
    void on_board22_clicked();
    void on_Reset_Button_clicked();

private:
    Ui::TicTacToeWindow *ui;
    TTTModel *tttModel;
    void updateScreen();


};
#endif // TICTACTOEWINDOW_H
