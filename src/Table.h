#include "hidingPlace.h"
#include "character.h"

class Table:public hidingPlace
{
private:
	const int dis=43;
public:
	//Constructor
	explicit Table(int visibility);
	explicit Table(std::string img, std::string message, float scale, int visibility);

	//To hide under table
	void hide(Character* a);

	//Overridden getPos method to calculate the correct position for table sprite(size:648,scaleX:0.35,scaleY:0.4)
	sf::Vector2f getPos();

};


