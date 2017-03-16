

#ifndef stickyTrap_hpp
#define stickyTrap_hpp

#include "trap.h"

class stickyTrap:
	public trap
{
    
private:
    float duration;//duration of the trap
    float activatedTime;// When the trap was activated
public:
    //Constructor
    explicit stickyTrap(float duration)
    	:trap("Spritesheets/gravMine.png","Grav Mine: hold 3sec","StickyTrap",2.f),duration(duration),activatedTime(-1){}
    explicit stickyTrap(float duration,bool isDepolyed)
    	:trap("Spritesheets/gravMine.png","Grav Mine: hold 3sec","StickyTrap",2.f,isDepolyed),duration(duration),activatedTime(-1){}

    float getDuration();

	float getActivatedTime();

	void setActivatedTime(float activatedTime) ;

	void activate(Character* a, float currentTime);


};

#endif /* stickyTrap_hpp */
