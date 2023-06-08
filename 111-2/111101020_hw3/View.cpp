#include "View.h"

#include <bits/stdc++.h>

using namespace std;

View::View(int sizeX, int sizeY) {
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    selectable = true;

    canvas = new char* [sizeY];
    for (int i = 0; i < sizeY; i++){
        canvas[i] = new char [sizeX];
    }
}
View::~View(){
    /*
    for (int i = 0 ; i < sizeY; i++){
        delete [] canvas[i];
    }
    delete [] canvas;
    */
}
int View::getSizeX() {
    return sizeX;
}
int View::getSizeY() {
    return sizeY;
}
bool View::isSelectable() {
    return selectable;
}

bool View::isSelected() {
    return true;        
}

void View::setPos(int posX, int posY) {
    this->posX = posX;
    this->posY = posY;
}
void View::setWindow(Window* window) {
}
int View::getPosX() { return posX; }
int View::getPosY() { return posY; }


void View::setOnClickListener(void (*listener) (View*)){
    onClickListener = listener; 
}
void View::setOnChangeListener(void (*listener)(View*)){
    onChangeListener = listener;
}

// Handler: when the view is clicked, call on click listener
void View::onClick(){

}

// Handler: when the view is changed, call on change listener
void View::onChange(){

}

// Handler: When user input to the view
void View::onInputKey(char key){

}

// Return rendered view canvas

// Call window render()
void View::rerenderWindow(){

}

void View::deleteAllView(){

}
