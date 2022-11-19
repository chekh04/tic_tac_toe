#include "gamestate.h"
#include "dialog.h"
#include <iostream>

using namespace std;

GameState::GameState(string name1, string name2, int size)
{
    boardSize = size;

    user *user1 = new user();
    user *user2 = new user();

    user1->name = name1;
    user2->name = name2;

    user1->img = QIcon(":/resources/assets/cross_large.png");
    user2->img = QIcon(":/resources/assets/zero_large.png");

    playersList.append(user1);
    playersList.append(user2);

    for(int i = 0; i < boardSize; i++) {
        QList<int> subStateList;
        for(int j = 0; j < boardSize; j++) {
            subStateList.append(2);
        }
        state.append(subStateList);
    }
}



void GameState::checkForWinner(int x, int y, int val) {
    filledButtons++;

            for(int i = 0; i < boardSize; i++){
                if(state[x][i] != val)
                    break;
                if(i == boardSize-1){
                    showWinner(playersList[val]->name);
                    return;
                }
            }

            for(int i = 0; i < boardSize; i++){
                if(state[i][y] != val)
                    break;
                if(i == boardSize-1){
                    showWinner(playersList[val]->name);
                    return;
                }
            }

            if(x == y){

                        for(int i = 0; i < boardSize; i++){
                            if(state[i][i] != val)
                                break;
                            if(i == boardSize-1){
                                showWinner(playersList[val]->name);
                                return;
                            }
                        }
                    }

            if(x + y == boardSize - 1){
                        for(int i = 0; i < boardSize; i++){
                            if(state[i][(boardSize-1)-i] != val)
                                break;
                            if(i == boardSize-1){
                                showWinner(playersList[val]->name);
                                return;
                            }
                        }
                    }
            if(filledButtons == boardSize*boardSize) {
                 showNoWinner();
            }
}

void GameState::showGameState() {
    for(int i = 0; i < boardSize; i++) {
        for(int j = 0; j < boardSize; j++) {
            cout<<state[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"========"<<endl<<endl;
}
void GameState::updateGameState(int x, int y, int currentUserIndex) {
    state[x][y] = currentUserIndex;
    checkForWinner(x,y,currentUserIndex);

    this->updateCurrentUser();
}
void GameState::updateCurrentUser() {
    if(!currentUserIndex) {
        currentUserIndex++;
    } else {
        currentUserIndex--;
    }
}

void GameState::showNoWinner() {
    QMessageBox *box = new QMessageBox();
    box->setGeometry(0,0, 350, 100);
    box->information(this, "Game is over", "There is no winner. Try again!");
    if(box->Ok) {
        restartGame();
    }

}
void GameState::showWinner(string winner) {
    QMessageBox *box = new QMessageBox();
    box->setGeometry(0,0, 300, 100);
    box->information(this, "Game is over", QString::fromStdString(winner+ " has won!"));
    if(box->Ok) {
        restartGame();
    }

}
void GameState::restartGame() {
    Dialog *welcomeDialog = new Dialog(0);
    welcomeDialog->setWindowTitle("Tic Tac Toe");
    welcomeDialog->setWindowIcon(QIcon(":/resources/assets/title_ico.png"));
    welcomeDialog->setFixedSize(300, 400);
    welcomeDialog->show();
    emit gameOver();
}



GameState::~GameState(){

}


