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

    //get the state of the locker's door
    bool getDoorOpen();

    //Open the locker's door
    void open(Human * a);

    //close the locker's door
    void close(Human * a);

    //Overridden getPos method to calculate the correct position for locker sprite(size:648,scaleX:0.35,scaleY:0.28)
    sf::Vector2f getPos();

    void animation();

};

#endif /* Locker_hpp */
