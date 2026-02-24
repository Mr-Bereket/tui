#include <string>
using namespace std;

class TextInput : public Widget
{
public:
	string value="";

	TextInput(int x, int y, int w) : Widget(x,y,w,1){}
	void draw() override {
		int ax = absoluteX();
		int ay = absoluteY();

		mvhline(ay,ax,'_',w);
		mvprintw(ay,ax,"%s",value.c_str());
	}
	void handleInput(int ch) override {
		if(!active) return;

		//take inputs untill full
		if(ch >= 32 && ch <= 126 && value.length() <= (w-1) ) {
			value += (char)ch;
		}
		//delete or backspace
		else if(ch == KEY_BACKSPACE || ch == 127 || ch == 8){
			if(!value.empty()) value.pop_back();
		}
	}
};