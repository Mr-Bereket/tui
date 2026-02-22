#include <vector>
#include <ncurses.h>
#include "Widget.h"
#include "Label.h"

using namespace std;

class Screen {
private:
    vector<Widget*> widgets;
public:
    Screen(){
      initscr();
      noecho();
      curs_set(0);
      keypad(stdscr, TRUE);
    }
    ~Screen(){
      endwin();
    }

    void addWidget(Widget* w) { widgets.push_back(w); }

    void update() {
        erase(); // clear ncurses buffer
        for (auto w : widgets) w->draw();
        refresh(); // push to physical terminal
    }

    void run() {
        int ch;
        while((ch = getch()) != 'q') { // 'q' to quit
            for (auto w : widgets) w->handleInput(ch);
            update();
        }
    }
};
