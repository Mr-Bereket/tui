#include <vector>
#include <ncurses.h>
#include "Widget.h"

using namespace std;

class Screen {
private:
    vector<Widget*> widgets;
public:
    Widget* activeInput = nullptr;
    Screen(){
      initscr();
      noecho();
      curs_set(0);
      keypad(stdscr, TRUE);
    }
    ~Screen(){
      endwin();
    }

    void add(Widget* w) { widgets.push_back(w); }

    void update() {
        erase(); // clear ncurses buffer
        for (auto w : widgets) w->draw();
        refresh(); // push to physical terminal
    }

    void run() {
        update();
        int ch;
        while( !( (ch = getch()) == 'q' && !activeInput) ) { // 'q' to quit
            if(activeInput){
                if(ch == 27){
                    activeInput->active=false;
                    this->activeInput = nullptr;
                }else{
                    activeInput->handleInput(ch);
                }
            }
            else {
                for (auto w : widgets) w->handleInput(ch);
            }
            update();
        }
    }
};
