#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include "gamestate.h"
#include "board.h"

using namespace std;

class Widget : public QWidget
{

public:
    Widget(QWidget *parent = 0);
    Widget(GameState *state, Board *board, QWidget *parent = 0);
    ~Widget();

};
#endif // WIDGET_H
