#ifndef WIDGET_H
#define WIDGET_H

#include <ncurses.h>
#include <functional>

using namespace std;

class Widget
{
public:
	int x,y,w,h;
	
	bool active = false;
	bool focused = false;
    bool visible = true;
    function<void()> onClick;
    Widget* parent = nullptr;

	Widget(int x, int y, int w, int h){
		this->x=x;
		this->y=y;
		this->w=w;
		this->h=h;
	}

	int absoluteX(){
		return (parent ? parent->absoluteX()+x : x);
	}
	int absoluteY(){
		return (parent ? parent->absoluteY()+y : y);
	}
	//for every widget
	virtual void draw() = 0;
	virtual void handleInput(int ch){}

	virtual ~Widget(){}	
};

#endif
