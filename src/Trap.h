#pragma once
#ifndef SRC_TRAP_H_
#define SRC_TRAP_H_

#include "Item.h"

#include "character.h"

class Trap:
		public Item
{
private:
	bool isDepolyed;
public:
	explicit Trap(std::string trapImg,std::string message,std::string trapType)
	:Item(trapImg,message,trapType),isDepolyed(false){}

	explicit Trap(std::string trapImg,std::string message,std::string trapType,bool depolyed)
	:Item(trapImg,message,trapType),isDepolyed(depolyed){}
		
	~Trap(){}

	virtual void activate(Human * a);

	bool getIsDepolyed();

	void setIsDepolyed(bool isDepolyed);

	void placeTrap(Human a);

};



#endif /* SRC_TRAP_H_ */
