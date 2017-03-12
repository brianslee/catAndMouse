#ifndef HPBAR_h
#define HPBAR_h

#include <SFML/Graphics.hpp>

class HealthBar{
	private:
		// Solid HP
		int HP;
		
		// Texture Length
		int length;
		// Texture Width
		int width;
		// Number of textures
		int num;
		
		// SpriteSheet for HP
		sf::Sprite spriteSheet;
	public:
	    // update current sprite with hp
		void updateSprite();
		// default ctor
		HealthBar(int hp=100){
			HP=hp;
			num=0;
		}
		// ctor
		HealthBar(sf::Texture &txr,int hp,int len,int wid,int n);
		// get whole spritesheet
		// in case anyone may use
	    sf::Sprite& getSprite(){return spriteSheet;	}
	    // get solid hp value
		int getHP(){return HP;}
		// set new HP, and update the sprite
	    void setHP(int n){
	    	HP=n;
	    	std::cout<<HP<<std::endl;
	    	if(n<0)HP=0;
	    	if(num!=0)updateSprite();
		}
		void setPos(float x,float y);
		
};
#endif
