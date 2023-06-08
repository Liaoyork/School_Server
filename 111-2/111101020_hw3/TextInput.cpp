#include "TextInput.h"

#include <bits/stdc++.h>

using namespace std;

TextInput::TextInput(int sizeX, int sizeY, string input) :View(sizeX, sizeY){
    this->input = input;
    selectable = true;
    which = 't';
}

TextInput::~TextInput(){
    
    for (int i = 0 ; i < sizeY; i++){
        delete [] canvas[i];
    }
    delete [] canvas;
    
}

// Getter
string TextInput::getInput(){
    return input;
}

// When the TextInput is selected and the user press the keyboard, onInputKey() will be called
void TextInput::onInputKey(char key){
    if (!isSelected()){
        return;
    }
    if (isSelected()){
       if (key == 127){
           string temp = "";
           for (int i = 0 ; i < (int)input.length() - 1; i++){
               temp += input[i];
           }
           input = temp;
       } else {
           input += key;
       }
    }
    onChangeListener(this);
}

// Render the textInput, the apperance of the textInput is different when selected
char** TextInput::render(){
    int inputlength = (int)input.length();
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
            for (int j = 1; j < inputlength + 1; j++){
                canvas[i][j] = input[j - 1];
            }
            for (int j = inputlength + 1; j < sizeX - 1; j++) {
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

void TextInput::render_point(){
    int inputlength = (int)input.length();
    for (int i = 0; i < sizeY; i++){
        if (i == 0 || i == sizeY - 1){
            for (int j = 0; j < sizeX; j++){
                if (j == 0 || j == sizeX - 1){
                    canvas[i][j] = '+';
                } else {
                    canvas[i][j] = '=';
                }
            }
        } else if (i == sizeY / 2){
            canvas[i][0] = '|';
            for (int j = 1; j < inputlength + 1; j++){
                canvas[i][j] = input[j - 1];
            }
            for (int j = inputlength + 1; j < sizeX - 1; j++) {
                canvas[i][j] = ' ';
            }
            canvas[i][sizeX - 1] = '|';
        } else {
            for (int j = 0; j < sizeX; j++){
                if (j == 0 || j == sizeX - 1){
                    canvas[i][j] = '|';
                } else {
                    canvas[i][j] = '=';
                }
            }
        }
    }
}
