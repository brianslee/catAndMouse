#ifndef Locker_hpp
#define Locker_hpp

#include "hidingPlace.h"
#include "character.h"

class locker:
		public hidingPlace
{
private:
    bool doorOpen; //open or closed
    const int dis=31;
public:
    //Constructor
    explicit locker(std::string img, std::string message,float scale, int visibility);
    
    explicit locker(int visibility);

    bool getDoorOpen();

    void open(Human * a);

    void close(Human * a);

    sf::Vector2f getPos();

};

#endif /* Locker_hpp */
