#include "Calculator.h"
#include <termios.h>
#include <bits/stdc++.h>
using namespace std;

Calculator::Calculator() {
    exit = false;
}
bool Calculator::pressEqual = false;
bool Calculator::exit = false;
string Calculator::expression = "";
void Calculator::exitWindow(View* view) {
    Calculator::exit = true;
}
void Calculator::pressSymbolButton(View* view) {
    if (pressEqual) {
        display->setOutput("");
        expression = "";
        pressEqual = false;
    }
    expression += dynamic_cast<Button*>(view)->getText();
    display->setOutput(expression);
    display->render();
}

void Calculator::pressEqualButton(View* view) {
    pressEqual = true;
    dynamic_cast<Label*>(display)->setOutput(to_string(Calculator::evaluate(expression)));
}

double Calculator::evaluate(string expression) {
    stack<double> values;
    stack<char> operators;

    for (size_t i = 0; i < expression.length(); ++i) {
        char ch = expression[i];
        if (isdigit(ch) || ch == '.' || ch == '-') {
            string numStr;
            numStr += ch;
            while (i + 1 < expression.length() && (isdigit(expression[i + 1]) || expression[i + 1] == '.' || expression[i + 1] == '-')) {
                if (expression[i + 1] == '-'){
                    while(i + 1 < expression.length() && (isdigit(expression[i + 1]) || expression[i + 1] == '.')){
                        numStr += expression[i + 1];
                        ++i;
                    }
                    operators.push('+');
                    goto cha;
                }
                numStr += expression[i + 1];
                ++i;
            }
        cha:
            double value = stod(numStr);
            values.push(value);
        } else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                double b = values.top();
                values.pop();
                double a = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                double result = applyOperator(a, b, op);
                values.push(result);
            }
            operators.push(ch);
        }
    }

    while (!operators.empty()) {
        double b = values.top();
        values.pop();
        double a = values.top();
        values.pop();
        char op = operators.top();
        operators.pop();
        double result = applyOperator(a, b, op);
        values.push(result);
    }

    return values.top();
}


void Calculator::run() {
    struct termios ter;
    tcgetattr(0, &ter);
    ter.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &ter);

    window->render();
    while (!Calculator::exit) {
        char key;
        key = cin.get();
        if (key == 27) {
            key = cin.get();
            if (key == 91) {
                key = cin.get();
                ArrowKey arrowKey;
                if (key == 65) {
                    arrowKey = ArrowKey::UP;
                } else if (key == 66) {
                    arrowKey = ArrowKey::DOWN;
                } else if (key == 67) {
                    arrowKey = ArrowKey::RIGHT;
                } else if (key == 68) {
                    arrowKey = ArrowKey::LEFT;
                }
                window->onArrowKeyPress(arrowKey);
            }
        } else if (key == 10) {
            window->onEnterPress();
        }
        window->render();
    }
}

Calculator::~Calculator(){
    delete window;
}
