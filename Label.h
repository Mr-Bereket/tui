#include "Widget.h"
#include <string>

using namespace std;

class Label : public Widget {
private:
    std::string text;

public:
    Label(int x, int y, string t) 
        : Widget(x, y, t.length(), 1), text(t) {}

    void draw() override {
        if (!visible) return;
        mvprintw(y, x, "%s", text.c_str());
    }
};
