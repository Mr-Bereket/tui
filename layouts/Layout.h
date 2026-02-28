#ifndef LAYOUT_H
#define LAYOUT_H

#include <vector>

using namespace std;

class Layout
{
public:
	//values
	Layout* parent = nullptr;
	Layout* activeChild = nullptr;
	vector<Layout*> children;
	bool visible = true;
	bool active = false;
	int x,y,w,h;

	Layout(int x,int y,int w,int h){
		this->x=x;
		this->y=y;
		this->w=w;
		this->h=h;
	}

	// where am i?
	int absoluteX(){
		return (parent ? parent->absoluteX()+x : x);
	}
	int absoluteY(){
		return (parent ? parent->absoluteY()+y : y);
	}

	void active(bool activate = true){
		active = activate;
		if(!activate) activeChild = nullptr;
		parent->active(activate);
	}

	//render
	virtual void draw(){
		for(auto* child:children){
			child->draw();
		}
	}
	virtual void handleInput(int ch){
		if(active){
			activeChild->handleInput(ch);
		}else{
		for(auto* child:children){
			child->handleInput(ch);
		}}
	}
	virtual ~Layout(){}
	
};

#endif