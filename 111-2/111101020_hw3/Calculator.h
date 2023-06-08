#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

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
    Window* window = new Window(50,30);
    // Call window.run()
    void run();

    // Callback static functions
    static void exitWindow(View* view);
    static void pressSymbolButton(View* view);
    static void pressEqualButton(View* view);
    // Window* window;
    // void setExit();

   private:
    // Evaluate the expression inputed by buttons
    static double evaluate(string expression);
    static bool exit;

    static int precedence(char op){
        if (op == '+'||op == '-') return 1;
        if (op == '*'||op == '/') return 2;
            return 0;
    }

    // Function to perform arithmetic operations.
    static double applyOperator(double a, double b, char op){
        switch(op){
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
        }
        return 0;
    }
};

#endif
