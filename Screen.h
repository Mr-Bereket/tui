#include <vector>
#include <ncurses.h>
#include "widgets/Widget.h"
#include "layouts/Layout.h"

using namespace std;

class Screen : public Layout {
public:
    Layout* activeInput = nullptr;
    Screen(int x=0,int y=0, int w=COLS,int h=LINES):Layout(x,y,w,h){
      initscr();
      noecho();
      curs_set(0);
      keypad(stdscr, TRUE);
    }
    void add(Layout* child){
        children.push_back(child);
        child->parent = this;
    }
    void update() {
        erase(); // clear ncurses buffer
        draw();
        refresh(); // push to physical terminal
    }

    void run() {
        update();
        int ch;
        while( !( (ch = getch()) == 'q' && !activeInput) ) { // 'q' to quit
            if(activeInput){
                    activeInput->handleInput(ch);
                }
            }
            else {
                for (auto child: children) child->handleInput(ch);
            }
            update();
        }
    }
    ~Screen(){
      endwin();
    }
};
