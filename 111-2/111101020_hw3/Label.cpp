#include <bits/stdc++.h>

#include "Label.h"
using namespace std;

Label::Label(int sizeX, int sizeY, string output, Alignment alignment) : View(sizeX, sizeY) {
    this->output = output;
    selectable = false;
    this->alignment = alignment;
    which = 'l';
}
Label::~Label(){
    
    for (int i = 0; i < sizeY; i++){
        delete [] canvas[i];
    }
    delete [] canvas;
    
}
void Label::setOutput(string output) {
    this->output = output;
}
void Label::setAlignment(Alignment alignment) {
    this->alignment = alignment;
}

char** Label::render() {
    int textlength = (int)output.length();
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
            switch (alignment){
                case Alignment::CENTER:
                    for (int j = 1; j < leftPadding; j++) {
                        canvas[i][j] = ' ';
                    }
                    for (int j = leftPadding; j < textlength + leftPadding; j++){
                        canvas[i][j] = output[j - leftPadding];
                    }
                    for (int j = leftPadding + textlength; j < sizeX - 1; j++) {
                        canvas[i][j] = ' ';
                    }
                    break;
                case Alignment::RIGHT:
                    for (int j = 1; j < padding - 1; j++) {
                        canvas[i][j] = ' ';
                    }
                    for (int j = padding - 1; j < sizeX - 1; j++){
                        canvas[i][j] = output[j - padding + 1];
                    }
                    break;
                case Alignment::LEFT:
                    for (int j = 1; j < textlength + 1; j++){
                        canvas[i][j] = output[j - 1];
                    }
                    for (int j = textlength + 1; j < sizeX - 1; j++){
                        canvas[i][j] = ' ';
                    }
                    break;
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
