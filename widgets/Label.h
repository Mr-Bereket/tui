#include <string>

using namespace std;

class Label : public Widget {
public:
    string text;
    Label(int x, int y, string t) 
        : Widget(x, y, t.length(), 1), text(t) {}

    void draw() override {
        if (!visible) return;
        mvprintw(absoluteY(), absoluteX(), "%s", text.c_str());
    }
};
