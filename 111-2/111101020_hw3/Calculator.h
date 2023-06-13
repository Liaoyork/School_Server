#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <sstream>
#include <stack>

#include "Button.h"
#include "Label.h"
#include "Window.h"
using namespace std;

// You can reference hw3-1.cpp to learn how to use the gui library you created
class Calculator {
    // static Window window;
    static Label* display;
    static string expression;

   public:
    // Constructor, setup views
    Calculator();
    static bool pressEqual;
    // Destructor, call View::deleteAllView();
    ~Calculator();
    Window* window = new Window(50, 30);
    // Call window.run()
    void run();

    // Callback static functions
    static void exitWindow(View* view);
    static void pressSymbolButton(View* view);
    static void pressEqualButton(View* view);
    // Window* window;
    // void setExit();

   private:
    // Evaluate the expression inputed by button
    static bool exit;

    static int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    // Function to perform arithmetic operations.
    static double applyOperator(double a, double b, char op) {
        switch (op) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
        }
        return 0;
    }
    // evaluate the expression in recursive way and istringstream
    // comply with the precedence of the operators
    static double evaluate2(string expression) {
        istringstream iss(expression);
        stack<double> values;
        stack<char> operators;
        double value;
        char op;
        while (iss >> value) {
            values.push(value);
            if (iss >> op) {
                while (!operators.empty() && precedence(operators.top()) >= precedence(op)) {
                    double b = values.top();
                    values.pop();
                    double a = values.top();
                    values.pop();
                    char op = operators.top();
                    operators.pop();
                    values.push(applyOperator(a, b, op));
                }
                operators.push(op);
            }
        }
        while (!operators.empty()) {
            double b = values.top();
            values.pop();
            double a = values.top();
            values.pop();
            char op = operators.top();
            operators.pop();
            values.push(applyOperator(a, b, op));
        }
        return values.top();
    }
};

#endif
