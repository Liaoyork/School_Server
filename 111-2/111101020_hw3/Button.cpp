#include "Button.h"

#include <bits/stdc++.h>

using namespace std;

Button::Button(int sizeX, int sizeY, string text = "") : View(sizeX, sizeY) {
    this->text = text;
    selectable = true;
    which = 'b';
}
Button::~Button(){
    
    for (int i = 0 ; i < sizeY; i++){
        delete [] canvas[i];
    }
    delete [] canvas;
    
}

string Button::getText() { return text; }

char** Button::render() {
    int textlength = (int)text.length();
    int padding = this->getSizeX() - textlength;
    int leftPadding = padding / 2;
    for (int i = 0; i < sizeY; i++){
        if (i == 0 || i == sizeY - 1){
            for (int j = 0; j < sizeX; j++){
                if (j == 0 || j == sizeX - 1){
                    canvas[i][j] = '+';
                } else {
                    canvas[i][j] = '-';
                }
            }
        } else if (i == sizeY / 2){
            canvas[i][0] = '|';
            for (int j = 1; j < leftPadding; j++) {
                canvas[i][j] = ' ';
            }
            for (int j = leftPadding; j < textlength + leftPadding; j++){
                canvas[i][j] = text[j - leftPadding];
            }
            for (int j = leftPadding + textlength; j < sizeX; j++) {
                canvas[i][j] = ' ';
            }
            canvas[i][sizeX - 1] = '|';
        } else {
            for (int j = 0; j < sizeX; j++){
                if (j == 0 || j == sizeX - 1){
                    canvas[i][j] = '|';
                } else {
                    canvas[i][j] = ' ';
                }
            }
        }
    }
    return View::canvas;
}

void Button::onClick(){
    onClickListener(this);
}

void Button::onChange(){

}

void Button::render_point(){
    int textlength = (int)text.length();
    int padding = this->getSizeX() - textlength;
    int leftPadding = padding / 2;
    for (int i = 0; i < sizeY; i++){
        if (i == 0 || i == sizeY - 1){
            for (int j = 0; j < sizeX; j++){
                if (j == 0 || j == sizeX - 1){
                    canvas[i][j] = '+';
                } else {
                    canvas[i][j] = '-';
                }
            }
        } else if (i == sizeY / 2){
            canvas[i][0] = '|';
            for (int j = 1; j < leftPadding; j++) {
                canvas[i][j] = '#';
            }
            for (int j = leftPadding; j < textlength + leftPadding; j++){
                canvas[i][j] = text[j - leftPadding];
            }
            for (int j = leftPadding + textlength; j < sizeX; j++) {
                canvas[i][j] = '#';
            }
            canvas[i][sizeX - 1] = '|';
        } else {
            for (int j = 0; j < sizeX; j++){
                if (j == 0 || j == sizeX - 1){
                    canvas[i][j] = '|';
                } else {
                    canvas[i][j] = '#';
                }
            }
        }
    }

}
