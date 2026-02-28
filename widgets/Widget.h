#ifndef WIDGET_H
#define WIDGET_H

#include <functional>
#include "../layouts/Layout.h"

using namespace std;

class Widget : public Layout
{
public:	
	bool focused = false;
    function<void()> onClick;

	Widget(int x, int y, int w, int h) : Layout(x,y,w,h){}
	//for every widget
	virtual void draw() = 0;
	virtual void handleInput(int ch){}

	virtual ~Widget(){}	
};

#endif
