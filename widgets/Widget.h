#ifndef WIDGET_H
#define WIDGET_H

#include <ncurses.h>

class Widget
{
public:
	int x,y,width,height;
	bool focused = false;
  bool visible = true;
	Widget(int x, int y, int w, int h) : x(x),y(y),width(w),height(h) {}

	//for every widget
	virtual void draw() = 0;
	virtual void handleInput(int ch){}

	virtual ~Widget(){}	
};

#endif
