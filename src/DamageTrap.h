#pragma once
#include "Trap.h"

class DamageTrap:
		public Trap
{
private:
	int damagePoint;
public:
	explicit DamageTrap(std::string trapImg,std::string message,int damagePoint)
	:Trap(trapImg,message,"DamageTrap"){
		this->damagePoint=damagePoint;
	}
	explicit DamageTrap(std::string trapImg,std::string message,int damagePoint,bool isDepolyed)
	:Trap(trapImg,message,"DamageTrap",isDepolyed){
		this->damagePoint=damagePoint;
	}

	~DamageTrap(){

	}

	int getDamagePoint(){
		return damagePoint;
	}

	virtual int activate(Human a){
		this->setIsDepolyed(false);
		this->setIsLoaded(false);
		return a.getHp()-damagePoint;



	}

};
