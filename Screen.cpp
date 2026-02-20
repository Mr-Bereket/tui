#include <vector>

class Screen {
private:
    vector<Widget*> widgets;
public:
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