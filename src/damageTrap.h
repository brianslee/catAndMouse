#pragma once
#ifndef SRC_DAMAGETRAP_H_
#define SRC_DAMAGETRAP_H_

#pragma once
#include "trap.h"


class damageTrap:
		public trap
{
private:
	int damagePoint;
public:
	explicit damageTrap(std::string trapImg,std::string message,int damagePoint)
	:trap(trapImg,message,"DamageTrap"),damagePoint(damagePoint){}

	explicit damageTrap(std::string trapImg,std::string message,int damagePoint,bool isDepolyed)
	:trap(trapImg,message,"DamageTrap",isDepolyed),damagePoint(damagePoint){}
	

	~damageTrap(){}

	int getDamagePoint();

	virtual void activate(Human * a);

};

#endif /* SRC_DAMAGETRAP_H_ */
