#include <iostream>
#include <string>
#include "MineSweeper.h"
#include <cstdlib>
using namespace std;
void MineSweeper::run(){
    newGame();
}
void MineSweeper::newGame(){
    while (1){
        cout << "Please input map width: "; cin >> sizeX;
        cout << "Please input map height: "; cin >> sizeY;
        if (sizeX > 0 && sizeY > 0){
            break;
        } else {
            cout << "Input Error!" << endl;
        }
    }
    while (1){
        cout << "Please input number of mines: "; cin >> mineNum;
        if (mineNum > 0 && mineNum < sizeY * sizeX){
            break;
        } else {
            cout << "Input Error!" << endl;
        }
    }

    createNewMap();
    generateMines();
    render();
    countMine();
    openGrid(0, 0);
}

void MineSweeper::createNewMap(){
   map = new Grid* [sizeY];
   for (int i = 0; i < sizeY ; i++){
       map[i] = new Grid [sizeX];
   }
}

void MineSweeper::countMine(){
    for (int i = 0 ; i < sizeY ; i++){
        for (int j = 0 ; j < sizeX; j++){
            int cou = 0;
            for (int k = i - 1; k <=  i + 1; k++){
                for (int l = j - 1; l <= j + 1; l++){
                    if (k < 0 || k + 1> sizeY) continue;
                    if (l < 0 || l + 1> sizeX) continue; 
                    if (map[k][l].getIsMine() && !map[i][j].getIsMine()){
                        cou++;
                    }
                }
            }
            map[i][j].setMineCount(cou);
        }
    }
}

bool explode = false;

void MineSweeper::openGrid(int pressedPosY, int pressedPosX){
    while(1){
        cout << "Please enter the coordinate (x, y) you want to press: " ;
        cin >> pressedPosX;  cin >> pressedPosY;
        if (isPosValid(pressedPosY, pressedPosX)){
            if (map[pressedPosY][pressedPosX].getIsMine()){
                explodeAllMines();
                explode = true;
            } 
            else if(map[pressedPosY][pressedPosX].getIsOpen()){
                cout << "Grid (" << pressedPosX << ", " << pressedPosY << ") is already pressed!" << endl;
                continue;
            } 
            if (map[pressedPosY][pressedPosX].getMineCount() == 0){
                propagateWhiteSpace(pressedPosY, pressedPosX);
            }
            if (map[pressedPosY][pressedPosX].getMineCount() > 0){
                map[pressedPosY][pressedPosX].open();
            }
            checkWin();
        } else {
            cout << "Invalid coordinate!" << endl;
        }
    }
}

void MineSweeper::checkWin(){
    
    bool win = false;
    string de;
 
    if (((sizeY) * (sizeX)) - map[0][0].getGridOpenCount() - mineNum == 0){
        for (int i = 0 ; i < sizeY; i++){
            for (int j = 0; j < sizeX; j++){
                map[i][j].open();
            }
        }

        //output start
        cout << "   ";
        for (int k = 0 ;k < sizeX;k++){
            if (k / 10 >= 1) cout << k;
                else cout << " " << k;
        }
        cout << endl;
        cout << "  --";
        for (int k = 0 ; k < sizeX; k++){
            cout << "--";
        }
        cout << endl;
        for (int i = 0 ; i < sizeY ; i++){
            if (i / 10 >= 1) cout << i << "|";
            else cout << " "<< i << "|";
            for (int j = 0 ; j < sizeX; j++){
                map[i][j].render();
            }
            cout << "|" << endl;
        }
        cout << "  --";                     
        for (int k = 0 ; k < sizeX; k++){
            cout << "--";
        }
        cout << endl;
        //output end
        win = true;        
        cout << "you win!" << endl;
        map[0][0].resetGridOpenCount();
    }

    else if (explode) {
        explode = false;
        for (int i = 0 ; i < sizeY; i++){
            for (int j = 0; j < sizeX; j++){
                map[i][j].open();
            }
        }

        //output start
        cout << "   ";
        for (int k = 0 ;k < sizeX;k++){
            if (k / 10 >= 1) cout << k;
                else cout << " " << k;
        }
        cout << endl;
        cout << "  --";
        for (int k = 0 ; k < sizeX; k++){
            cout << "--";
        }
        cout << endl;
        for (int i = 0 ; i < sizeY ; i++){
            if (i / 10 >= 1) cout << i << "|";
            else cout << " "<< i << "|";
            for (int j = 0 ; j < sizeX; j++){
                map[i][j].render();
            }
            cout << "|" << endl;
        }
        cout << "  --";                     
        for (int k = 0 ; k < sizeX; k++){
            cout << "--";
        }
        cout << endl;
        //output end

        map[0][0].resetGridOpenCount();
        cout << "Mine explode! You lose!" << endl << endl;
        cout << "Do you want to play another round? (y/n) "; cin >> de;
        if (de == "y") newGame();
        else if (de == "n") exit(0);
    }
    else if (!win && !explode) {

        //output start
        cout << "   ";
        for (int k = 0 ;k < sizeX;k++){
            if (k / 10 >= 1) cout << k;
                else cout << " " << k;
        }
        cout << endl;
        cout << "  --";
        for (int k = 0 ; k < sizeX; k++){
            cout << "--";
        }
        cout << endl;
        for (int i = 0 ; i < sizeY ; i++){
            if (i / 10 >= 1) cout << i << "|";
            else cout << " "<< i << "|";
            for (int j = 0 ; j < sizeX; j++){
                map[i][j].render();
            }
            cout << "|" << endl;
        }
        cout << "  --";                     
        for (int k = 0 ; k < sizeX; k++){
            cout << "--";
        }
        cout << endl;
        //output end
    }
    if (win) {
        win = false;
        while (1){
            cout << "Do you want to play another round? (y/n) "; cin >> de;
            if (de == "y") newGame();
            else if (de == "n") exit(0);
        }
    }
}

void MineSweeper::propagateWhiteSpace(int y, int x){
    if (!isPosValid(y, x)) return;
    else if (map[y][x].getIsMine()) return;
    else if (map[y][x].getIsOpen()) return;
    else if (map[y][x].getMineCount() != 0) {
        map[y][x].open();
        return;
    }
    else {
        map[y][x].open();
        propagateWhiteSpace(y - 1, x);
        propagateWhiteSpace(y + 1, x);
        propagateWhiteSpace(y, x + 1);
        propagateWhiteSpace(y, x - 1);
    }
}

bool MineSweeper::isPosValid(int a,int b){
    if (a >= 0 && a < sizeY && b >= 0 && b < sizeX){
        return true;
    } else {
        return false;
    }
}

void MineSweeper::explodeAllMines(){
    for (int i = 0 ; i <sizeY ; i++){
        for (int j = 0 ; j < sizeX; j++){
            if (map[i][j].getIsMine()){
                map[i][j].setExplode();
            }
            map[i][j].open();
        }
    }
}

void MineSweeper::render(){
    cout << "   ";      
    for (int k = 0 ;k < sizeX;k++){
        if (k / 10 >= 1) cout << k;
        else cout << " " << k;
    }
    cout << endl;
    cout << "  --";
    for (int k = 0 ; k < sizeX; k++){
        cout << "--";
    }
    cout << endl;
    for (int i = 0 ; i < sizeY; i++){
        if (i / 10 >= 1){
            cout << i << "|";
        } else if (i / 10 < 1){
            cout << " " << i << "|";
        }
        for (int j = 0 ; j < sizeX ; j++){
            if (!map[i][j].getIsOpen()) wcout << L"\u2B1C";
            else if (map[i][j].getIsOpen() && map[i][j].getMineCount() > 0){
                cout << map[i][j].getMineCount();
            } else if (map[i][j].getIsOpen() && map[i][j].getMineCount() == 0){
                cout << "  ";
            }
        }
            cout << "|";
            cout << endl;
    }
    cout << "  --";
    for (int k = 0 ; k < sizeX; k++){
        cout << "--";
    }
    cout << endl;
}
