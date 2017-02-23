/*
	explicit DamageTrap::DamageTrap(std::string trapImg,std::string message,int damagePoint)
	:Trap(trapImg,message,"DamageTrap"){
		this->damagePoint=damagePoint;
	}
	explicit DamageTrap(std::string trapImg,std::string message,int damagePoint,bool isDepolyed)
	:Trap(trapImg,message,"DamageTrap",isDepolyed){
		this->damagePoint=damagePoint;
	}

	~DamageTrap(){

	}
*/

#include "DamageTrap.h"

	int DamageTrap::getDamagePoint(){
		return damagePoint;
	}

	void DamageTrap::activate(Human * a){
		this->setIsDepolyed(false);
		this->setIsLoaded(false);
		a->hp=a->hp-damagePoint;
		std::cout<<"Activited, player HP:"<<a->hp<<std::endl;
		
		



	}


