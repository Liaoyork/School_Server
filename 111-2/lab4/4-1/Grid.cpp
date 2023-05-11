#include <iostream>
#include "Grid.h"
using namespace std;

void Grid::setMine(){
   isMine = true;
}

void Grid::setExplode(){
   isExplode = true; 
}

void Grid::setMineCount(int mC){
    mineCount = mC;
}

void Grid::open(){
    //cout << "gg";
    isOpen = true;
    gridOpenCount++;
}

bool Grid::getIsMine(){
    if (isMine){
        return true;
    }
    return false;
}
bool Grid::getIsOpen(){
    if (isOpen){
        return true;
    }
    return false;
}
int Grid::getMineCount(){
    return mineCount;
}

int Grid::getGridOpenCount(){
    return gridOpenCount;
}

void Grid::resetGridOpenCount(){
    gridOpenCount = 0;
}

void Grid::render(){
    if (!isOpen && !isExplode) {
        wcout << L"\u2B1C";
        return;
    } else if (isOpen && mineCount == 0 && !isMine){
        cout << "  ";
        return;
    } else if (isOpen && mineCount > 0){
        cout << " " << mineCount;
        return;
    }
    
    if (isExplode && isMine){
        wcout << L"\U0001F4A5";      
        return;
    } else if (isExplode && !isMine){
        if (mineCount == 0){
            cout << "  ";
            return;
        } else {
            cout << " " << mineCount;
            return;
        }
    }

    if (!isExplode && isMine && isOpen){
        wcout << L"\U0001F4A3";
        return;
    }
    if (!isExplode && !isMine && mineCount == 0 && isOpen){
        cout << "  ";
        return;
    }
    if (!isExplode && !isMine && mineCount != 0 && isOpen){
        cout << " " << mineCount;
        return;
    }
}
int Grid::gridOpenCount = 0;
