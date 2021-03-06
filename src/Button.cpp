#include "Button.h"
#include "screen.h"
#include <stdio.h>


Button::Button(int v1,int v2,int v3,int v4,string s):view(v1,v2,v3,v4)
{
	text = s;
	focusable = 1;
}
string Button::GetText(){
	return text;
}
void Button::SetText(string s){
	text = s;
}
int Button::OnDraw(){
	int ret = 0;
	int x,y;

	screen::fill_roundrect(x1,y1,x2,y2,5,BUTTON_RECT_CLR);
	screen::draw_roundrect(x1,y1,x2,y2,5,BUTTON_BORDER_CLR);
	
	x = x1+(x2-x1-text.length()*CHAR_WIDTH)/2;
	y = y1+(y2-y1-CHAR_HEIGHT)/2;
	screen::draw_string(x,y,GetText(),BUTTON_BORDER_CLR);
	return ret;
}
void Button::SetFunc(int (*click)(void *),void *t){
	func = click;
	data = t;
}
int Button::OnClick(){
	if(!screen::posinrect(x1,y1,x2,y2))
		return 0;
	else{
		if(func !=NULL)
			return func(data);
		else
			return 0;
	}
}
int Button::OnKeyPress(int value){return 0;}
int Button::OnFocus(){return 0;}
int Button::OnLostFocus(){return 0;}
Button::~Button()
{
}

