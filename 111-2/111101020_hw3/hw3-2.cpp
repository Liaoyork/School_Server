#include <iostream>

#include "Button.h"
#include "Calculator.h"
#include "Label.h"
#include "Window.h"

using namespace std;
Calculator calculator;
Button* numButtons0 = new Button(9, 5, "0");
Button* numButtons1 = new Button(9, 5, "1");
Button* numButtons2 = new Button(9, 5, "2");
Button* numButtons3 = new Button(9, 5, "3");
Button* numButtons4 = new Button(9, 5, "4");
Button* numButtons5 = new Button(9, 5, "5");
Button* numButtons6 = new Button(9, 5, "6");
Button* numButtons7 = new Button(9, 5, "7");
Button* numButtons8 = new Button(9, 5, "8");
Button* numButtons9 = new Button(9, 5, "9");

Button* exitButton = new Button(19, 3, "Exit");
Button* dotButton = new Button(9, 5, ".");
Button* addButton = new Button(9, 5, "+");
Button* subButton = new Button(9, 5, "-");
Button* mulButton = new Button(9, 5, "*");
Button* divButton = new Button(9, 5, "/");
Button* eqButton = new Button(9, 5, "=");
Label* dispLable = new Label(41, 5, "", Alignment::RIGHT);
Label* Calculator::display = dispLable;
int main() {
    // number button
    numButtons0->setOnClickListener(Calculator::pressSymbolButton);
    numButtons1->setOnClickListener(Calculator::pressSymbolButton);
    numButtons2->setOnClickListener(Calculator::pressSymbolButton);
    numButtons3->setOnClickListener(Calculator::pressSymbolButton);
    numButtons4->setOnClickListener(Calculator::pressSymbolButton);
    numButtons5->setOnClickListener(Calculator::pressSymbolButton);
    numButtons6->setOnClickListener(Calculator::pressSymbolButton);
    numButtons7->setOnClickListener(Calculator::pressSymbolButton);
    numButtons8->setOnClickListener(Calculator::pressSymbolButton);
    numButtons9->setOnClickListener(Calculator::pressSymbolButton);
    calculator.window->addView(numButtons0, 6, 21);
    calculator.window->addView(numButtons1, 6, 16);
    calculator.window->addView(numButtons2, 16, 16);
    calculator.window->addView(numButtons3, 26, 16);
    calculator.window->addView(numButtons4, 6, 11);
    calculator.window->addView(numButtons5, 16, 11);
    calculator.window->addView(numButtons6, 26, 11);
    calculator.window->addView(numButtons7, 6, 6);
    calculator.window->addView(numButtons8, 16, 6);
    calculator.window->addView(numButtons9, 26, 6);

    // operator
    exitButton->setOnClickListener(Calculator::exitWindow);
    dotButton->setOnClickListener(Calculator::pressSymbolButton);
    addButton->setOnClickListener(Calculator::pressSymbolButton);
    subButton->setOnClickListener(Calculator::pressSymbolButton);
    mulButton->setOnClickListener(Calculator::pressSymbolButton);
    divButton->setOnClickListener(Calculator::pressSymbolButton);
    eqButton->setOnClickListener(Calculator::pressEqualButton);

    calculator.window->addView(exitButton, 16, 26);
    calculator.window->addView(dotButton, 16, 21);
    calculator.window->addView(addButton, 36, 16);
    calculator.window->addView(subButton, 36, 21);
    calculator.window->addView(mulButton, 36, 11);
    calculator.window->addView(divButton, 36, 6);
    calculator.window->addView(eqButton, 26, 21);
    calculator.window->addView(dispLable, 5, 1);
    calculator.run();
}
