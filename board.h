#ifndef BOARD_H
#define BOARD_H
#include "gamestate.h"
#include <QWidget>
#include <QLabel>
#include <QPushButton>

class Board: public QWidget
{

public:
    Board(GameState *state, QWidget *parent = 0);
    QList<QList<QPushButton*>> btnList;
    QGridLayout *grid;
private:
    GameState *state;
    QLabel *user1Label;
    QLabel *user2Label;
    QLabel *currentPlayer;
    QString currentUserStyles = "font-size: 15px;font-weight: bold;text-transform: uppercase;color: #22558f;";
    QString usualUserStyles = "font-size: 15px;text-transform: uppercase";

    void changeCurrentUserLabelStyles();

private slots:
    void btnClick();

};

#endif // BOARD_H
