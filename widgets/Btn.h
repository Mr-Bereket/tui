#include <string>

using namespace std;

class Btn : public Widget
{
public:
	char key;
	string label;

	Btn(int x, int y,string label,char key):
		Widget(x, y, label.length()+3, 1),
		key(key),
		label(label) {}
	
	void draw() override {
		mvprintw(absoluteY(),absoluteX(),"[%c]%s",key,label.c_str());
	}
	void handleInput(int ch) override {
		if(ch == key && onClick) onClick();
	}
};