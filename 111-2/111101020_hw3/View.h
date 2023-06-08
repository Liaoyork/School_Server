#ifndef _VIEW_H_
#define _VIEW_H_

#include <vector>

using namespace std;

class Window;

class View {
    static vector<View*> views;

   protected:
    int posX;
    int posY;
    int sizeX;
    int sizeY;

    bool selectable;

    char** canvas;

    Window* window = nullptr;

    void (*onClickListener)(View*) = nullptr;
    void (*onChangeListener)(View*) = nullptr;


   public:
    // Consturctor, remember to allocate canvas 
    View(int sizeX, int sizeY);
    // Destructor, remember to deallocate canvas 
    virtual ~View() = 0;


    // Getters
    int getSizeX();
    int getSizeY();
    bool isSelectable();
    char which;
    // Return if window->selectedView is same as self
    bool isSelected();

    // Callback function pointers setters
    void setOnClickListener(void (*listener)(View*));
    void setOnChangeListener(void (*listener)(View*));

    // Delete all created View in views, call at the end of main()
    static void deleteAllView();


   protected:
    // Setters
    void setPos(int posX, int posY);
    void setWindow(Window* window);
    int getPosX();
    int getPosY();

    // Handler: when the view is clicked, call on click listener
    virtual void onClick();
    
    // Handler: when the view is changed, call on change listener
    virtual void onChange();
    
    // Handler: When user input to the view
    virtual void onInputKey(char key);

    // Return rendered view canvas
    virtual char** render() = 0;

    // Call window render()
    void rerenderWindow();
    virtual void render_point() = 0;
   public:
    friend class Window;
};

#endif
