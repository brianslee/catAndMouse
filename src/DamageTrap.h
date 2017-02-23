#pragma once
#ifndef SRC_DAMAGETRAP_H_
#define SRC_DAMAGETRAP_H_

#pragma once
#include "Trap.h"


class DamageTrap:
		public Trap
{
private:
	int damagePoint;
public:
	explicit DamageTrap(std::string trapImg,std::string message,int damagePoint)
	:Trap(trapImg,message,"DamageTrap"),damagePoint(damagePoint){}

	explicit DamageTrap(std::string trapImg,std::string message,int damagePoint,bool isDepolyed)
	:Trap(trapImg,message,"DamageTrap",isDepolyed),damagePoint(damagePoint){}
	

	~DamageTrap(){}

	int getDamagePoint();

	virtual void activate(Human * a);

};

#endif /* SRC_DAMAGETRAP_H_ */
