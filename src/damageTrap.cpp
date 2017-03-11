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

#include "damageTrap.h"

	int damageTrap::getDamagePoint(){
		return damagePoint;
	}

	void damageTrap::activate(Human * a){
		this->setIsDeployed(false);
		this->setIsLoaded(false);
		a->hp=a->hp-damagePoint;
//		std::cout<<"Damage Point:"<<damagePoint<<std::endl;
		std::cout<<"Activited, player HP:"<<a->hp<<std::endl;
		
		



	}


