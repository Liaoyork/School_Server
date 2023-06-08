#include "Window.h"

#include <termios.h>
//#include <windows.h>

#include <cmath>
#include <cstdlib>
#include <iostream>

#include "View.h"

using namespace std;

// You don't have to modify
void Window::run() {
    struct termios ter;
    tcgetattr(0, &ter);
    ter.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &ter);

    render();
    while (!exit) {
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
                onArrowKeyPress(arrowKey);
            }
        } else if (key == 10) {
            onEnterPress();
        } else {
            onNormalKeyPress(key);
        }
        render();
    }
}

Window::Window(int sizeX, int sizeY) {
    this->sizeY = sizeY;
    this->sizeX = sizeX;
    canvas = new char*[sizeY + 2];
    for (int i = 0; i < sizeY + 2; i++) {
        canvas[i] = new char[sizeX + 2];
    }
    for (int i = 0; i < sizeY + 2; i++) {
        if (i == 0 || i == sizeY + 1) {
            for (int j = 0; j < sizeX + 2; j++) {
                if (j == 0 || j == sizeX + 1) {
                    canvas[i][j] = '+';
                } else {
                    canvas[i][j] = '-';
                }
            }
        } else {
            for (int j = 0; j < sizeX + 2; j++) {
                if (j == 0 || j == sizeX + 1) {
                    canvas[i][j] = '|';
                } else {
                    canvas[i][j] = ' ';
                }
            }
        }
    }
}

// Destructor, remember to deallocate canvas
Window::~Window() {
    for (int i = 0; i < sizeY + 2; i++) {
        delete[] canvas[i];
    }
    delete[] canvas;
    for (int i = 0; i < (int)views.size(); i++) {
        delete views[i];
    }
}

// Add a new view to the window in provided position
void Window::addView(View* view, int posX, int posY) {
    view->setPos(posX, posY);
    views.push_back(view);
    view->render();
}

// Set exit to true
void Window::setExit() {
    exit = true;
}

// Return selectedView
View* Window::getSelectedView() {
    return selectedView;
}

// Render the window, call "system("clear");" first
void Window::render() {
    system("clear");
    for (auto p : views) {
        if (selectedView == p) {
            p->render();
            p->render_point();
        } else {
            p->render();
        }
        for (int i = p->posY + 1; i < p->posY + p->sizeY + 1; i++) {
            for (int j = p->posX; j < p->posX + p->sizeX; j++) {
                canvas[i][j] = p->canvas[i - p->posY - 1][j - p->posX];
            }
        }
    }
    for (int i = 0; i < sizeY + 2; i++) {
        for (int j = 0; j < sizeX + 2; j++) {
            cout << canvas[i][j];
        }
        cout << "\n";
    }
}

// Will be called when arrow key is pressed
// If selectedView == nullptr, set the first selectable view in the vector views to selectedView
// Else set selectedView to the nearest selectable view of the current selectedView in the given direction
void Window::onArrowKeyPress(ArrowKey key) {
    if (selectedView == nullptr) {
        for (auto p : views) {
            if (p->isSelectable()) {
                selectedView = p;
                return;
            }
        }
    }
    int temp = 10000;
    View* min = nullptr;
    if (key == ArrowKey::UP) {
        for (auto p : views) {
            if (p == selectedView) continue;
            if (!p->isSelectable()) continue;
            if (p->posY < selectedView->posY && abs(p->posY - selectedView->posY) < temp) {
                temp = abs(p->posY - selectedView->posY);
                min = p;
            }
        }
        temp = 10000;
        for (auto p : views) {
            if (p == selectedView) continue;
            if (!p->isSelectable()) continue;
            if (p->posX == selectedView->posX && p->posY < selectedView->posY && abs(p->posY - selectedView->posY) < temp) {
                temp = abs(p->posY - selectedView->posY);
                min = p;
            }
        }
    } else if (key == ArrowKey::DOWN) {
        for (auto p : views) {
            if (p == selectedView) continue;
            if (!p->isSelectable()) continue;
            if (p->posY > selectedView->posY && abs(p->posY - selectedView->posY) < temp) {
                temp = abs(p->posY - selectedView->posY);
                min = p;
            }
        }
        temp = 10000;
        for (auto p : views) {
            if (p == selectedView) continue;
            if (!p->isSelectable()) continue;
            if (p->posX == selectedView->posX && p->posY > selectedView->posY && abs(p->posY - selectedView->posY) < temp) {
                temp = abs(p->posY - selectedView->posY);
                min = p;
            }
        }
    } else if (key == ArrowKey::LEFT) {
        for (auto p : views) {
            if (p == selectedView) continue;
            if (!p->isSelectable()) continue;
            if (p->posX < selectedView->posX && abs(p->posX - selectedView->posX) < temp) {
                temp = abs(p->posX - selectedView->posX);
                min = p;
            }
        }
        temp = 10000;
        for (auto p : views) {
            if (p == selectedView) continue;
            if (!p->isSelectable()) continue;
            if (p->posY == selectedView->posY && p->posX < selectedView->posX && abs(p->posX - selectedView->posX) < temp) {
                temp = abs(p->posX - selectedView->posX);
                min = p;
            }
        }
    } else if (key == ArrowKey::RIGHT) {
        for (auto p : views) {
            if (p == selectedView) continue;
            if (!p->isSelectable()) continue;
            if (p->posX > selectedView->posX && abs(p->posX - selectedView->posX) < temp) {
                temp = abs(p->posX - selectedView->posX);
                min = p;
            }
        }
        temp = 10000;
        for (auto p : views) {
            if (p == selectedView) continue;
            if (!p->isSelectable()) continue;
            if (p->posY == selectedView->posY && p->posX > selectedView->posX && abs(p->posX - selectedView->posX) < temp) {
                temp = abs(p->posX - selectedView->posX);
                min = p;
            }
        }
    }
    if (min != nullptr) selectedView = min;
}

// Will be called when normal key is pressed (alphabet, symbols, backspace)
// Call onInputKey() of the selected view
void Window::onNormalKeyPress(char key) {
    if (selectedView->which != 't') {
        return;
    } else {
        selectedView->onInputKey(key);
    }
}

// Will be called when Enter key is pressed
// Call onClick() of the selected view
void Window::onEnterPress() {
    selectedView->onClick();
}

void Window::selectView(View* view) {
}

void printAlignedText(string& text, Alignment alignment, int width) {
    int textWidth = static_cast<int>(text.length());
    int padding = width - textWidth;
    if (padding <= 0) {
        cout << text;
    } else {
        switch (alignment) {
            case Alignment::LEFT:
                cout << text;
                for (int i = 0; i < padding; ++i) {
                    cout << ' ';
                }
                break;
            case Alignment::RIGHT:
                for (int i = 0; i < padding; ++i) {
                    std::cout << ' ';
                }
                cout << text;
                break;
            case Alignment::CENTER:
                int leftPadding = padding / 2;
                int rightPadding = padding - leftPadding;
                for (int i = 0; i < leftPadding; ++i) {
                    cout << ' ';
                }
                std::cout << text;
                for (int i = 0; i < rightPadding; ++i) {
                    cout << ' ';
                }
                break;
        }
    }
}
