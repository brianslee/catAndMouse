#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)

  #include <windows.h>

  inline void delay( unsigned long ms )
    {
    Sleep( ms );
    }

#else  /* presume POSIX */

  #include <unistd.h>

  inline void delay( unsigned long ms )
    {
    usleep( ms * 1000 );
    }

#endif
#pragma once
#include "Item.h"

//#include "character.h"

class Trap:
		public Item
{
private:
	bool isDepolyed;
public:
	explicit Trap(std::string trapImg,std::string message,std::string trapType)
	:Item(trapImg,message,trapType){
		isDepolyed=false;
	}
	explicit Trap(std::string trapImg,std::string message,std::string trapType,bool depolyed)
	:Item(trapImg,message,trapType){
		isDepolyed=depolyed;
	}
	~Trap(){

	}

	virtual int activate(Human a){
		return 0;
	}

	bool getIsDepolyed(){
		return isDepolyed;
	}

	void setIsDepolyed(bool isDepolyed){
		this->isDepolyed=isDepolyed;
	}

	void placeTrap(Human a){
		this->setPosition(a.getPos());
		this->setIsLoaded(true);

	}

};
