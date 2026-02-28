#include <vector>
#include "Layout.h"

using namespace std;

class Box : public Layout
{
public:
	Box(int x,int y, int w , int h) : Layout(x,y,w,h){}

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
    void add(Layout* child){
        this->children.push_back(child);
        child->parent = this;
    }
};