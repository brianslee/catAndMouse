#pragma once
#ifndef SRC_DAMAGETRAP_H_
#define SRC_DAMAGETRAP_H_

#pragma once
#include "trap.h"


class damageTrap:
		public trap
{
private:
	int damagePoint; //The damage point that deal to the player
public:
	//Constructor
	explicit damageTrap(int damagePoint)
		:trap("Spritesheets/landmine.png","Land Mine: 20 Damage","DamageTrap",2.f),damagePoint(damagePoint){}

	explicit damageTrap(int damagePoint,bool isDepolyed)
		:trap("Spritesheets/landmine.png","Land Mine: 20 Damage","DamageTrap",2.0,isDepolyed),damagePoint(damagePoint){}

	explicit damageTrap(std::string trapImg,std::string message,int damagePoint,bool isDepolyed)
	:trap(trapImg,message,"DamageTrap",isDepolyed),damagePoint(damagePoint){}
	
	explicit damageTrap(std::string trapImg,std::string message,float scale,int damagePoint)
		:trap(trapImg,message,"DamageTrap",scale),damagePoint(damagePoint){}

	explicit damageTrap(std::string trapImg,std::string message,float scale,int damagePoint,bool isDepolyed)
		:trap(trapImg,message,"DamageTrap",scale,isDepolyed),damagePoint(damagePoint){}


	~damageTrap(){}

	int getDamagePoint(); //Return the damage point of the trap

	 void activate(Human * a); // Make the traps activate, do damage to player, then set it disappear

};

#endif /* SRC_DAMAGETRAP_H_ */
