#include <vector>
#include <ncurses.h>

class Widget
{
public:
	int x,y,width,height;
	bool focused = false;
	Widget(int x, int y, int w, int h) : x(x),y(y),width(w),height(h) {}

	//for every widget
	virtual void draw() = 0
	virtual void handleInput(int ch) = 0;

	virtual ~Widget(){}	
};