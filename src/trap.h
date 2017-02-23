#pragma once
#ifndef SRC_TRAP_H_
#define SRC_TRAP_H_

#include "character.h"
#include "item.h"

class trap:
		public Item
{
private:
	bool isDepolyed;
public:
	explicit trap(std::string trapImg,std::string message,std::string trapType)
	:Item(trapImg,message,trapType),isDepolyed(false){}

	explicit trap(std::string trapImg,std::string message,std::string trapType,bool depolyed)
	:Item(trapImg,message,trapType),isDepolyed(depolyed){}
		
	~trap(){}

	virtual void activate(Human * a);

	bool getIsDepolyed();

	void setIsDepolyed(bool isDepolyed);

	void placeTrap(Human a);

};



#endif /* SRC_TRAP_H_ */
