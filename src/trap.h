#pragma once
#ifndef SRC_TRAP_H_
#define SRC_TRAP_H_

#include "character.h"
#include "item.h"

class trap:
		public Item
{
private:
	bool isDeployed; // if the trap is deployed on the map

public:
	//C
	explicit trap(std::string trapImg,std::string message,std::string trapType)
	:Item(trapImg,message,trapType),isDeployed(false){}

	explicit trap(std::string trapImg,std::string message,std::string trapType,float scale)
		:Item(trapImg,message,trapType,scale),isDeployed(false){}

	explicit trap(std::string trapImg,std::string message,std::string trapType,bool depolyed)
	:Item(trapImg,message,trapType),isDeployed(depolyed){}

	explicit trap(std::string trapImg,std::string message,std::string trapType, float scale ,bool depolyed)
		:Item(trapImg,message,trapType,scale),isDeployed(depolyed){}
		
	~trap(){}

	virtual void activate(Human * a); // Make the traps activate, do damage to player, then set it disappear

	bool getIsDeployed(); // return if the trap is deployed to the map

	void setIsDeployed(bool isDeployed); // set the trap to be deployed

	void placeTrap(Human * a,sf::View& view, sf::RenderWindow& window); // deployed the trap on the map

	void animation();
};



#endif /* SRC_TRAP_H_ */
