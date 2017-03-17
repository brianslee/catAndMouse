#pragma once
#ifndef SRC_TRAP_H_
#define SRC_TRAP_H_

#include "character.h"
#include "item.h"

class trap:
		public Item
{
protected:
	bool isDeployed; // if the trap is deployed on the map
	bool activated;
public:
	//C
	explicit trap(std::string trapImg,std::string message,std::string trapType)
	:Item(trapImg,message,trapType),isDeployed(false),activated(false){}

	explicit trap(std::string trapImg,std::string message,std::string trapType,float scale)
		:Item(trapImg,message,trapType,scale),isDeployed(false),activated(false){}

	explicit trap(std::string trapImg,std::string message,std::string trapType,bool depolyed)
	:Item(trapImg,message,trapType),isDeployed(depolyed),activated(false){}

	explicit trap(std::string trapImg,std::string message,std::string trapType, float scale ,bool depolyed)
		:Item(trapImg,message,trapType,scale),isDeployed(depolyed),activated(false){}
		
	~trap(){}

	virtual void afterActivated();

	bool getIsDeployed(); // return if the trap is deployed to the map

	void setIsDeployed(bool isDeployed); // set the trap to be deployed

	void placeTrap(Character * a,sf::View& view, sf::RenderWindow& window); // deployed the trap on the map

	void animation();
};



#endif /* SRC_TRAP_H_ */
