#include "HealthBar.h"
HealthBar::HealthBar(sf::Texture &spr,int hp,int len,int wid,int n){
	spriteSheet.setTexture(spr);
	HP=hp;
	length=len;
	width=wid;
	num=n; 
	updateSprite();
}

	HealthBar::HealthBar(){
			HP=100;
			num=0;}



void HealthBar::updateSprite(){
	spriteSheet.setTextureRect((sf::IntRect(0, ((100-HP)*(num-1)/100)*width, length, width )));
}
void HealthBar::setPos(float x,float y){
	spriteSheet.setPosition(x,y);
}	

 void HealthBar::setHP(int n){
	    	HP=n;
	    	if(n<0)HP=0;
	    	if(num!=0)updateSprite();
		}
		void setPos(float x,float y);

