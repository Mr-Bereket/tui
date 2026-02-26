#include <vector>

using namespace std;

class Box : public Widget
{
public:
	vector<Widget*> children;


	Box(int x,int y, int w , int h) : Widget(x,y,w,h){}

	void draw() override {
		if (!visible) return;
		// Draw top and bottom
        for (int i = 0; i < w; i++) {
            mvaddch(y, x + i, ACS_HLINE);         // Top
            mvaddch(y + h - 1, x + i, ACS_HLINE); // Bottom
        }

        // Draw sides
        for (int i = 0; i < h; i++) {
            mvaddch(y + i, x, ACS_VLINE);         // Left
            mvaddch(y + i, x + w - 1, ACS_VLINE); // Right
        }

        // Draw corners
        mvaddch(y, x, ACS_ULCORNER);
        mvaddch(y, x + w - 1, ACS_URCORNER);
        mvaddch(y + h - 1, x, ACS_LLCORNER);
        mvaddch(y + h - 1, x + w - 1, ACS_LRCORNER);

        for (auto* child : children)
        {
        	child->draw();
        }
	}
	void add(Widget* w){
		children.push_back(w);
		w->parent = this;
	}

    void handleInput(int ch) override {
        if(onClick) onClick();
        for(auto* child:children){
            child->handleInput(ch);
        }
    }
};