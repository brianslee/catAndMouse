#include <SFML/System.hpp>
class Timer
{
private:
	sf::Clock clock;
    
public:
    //Constructor
    Timer();

    //Get the time passed and restart the timer;
   	sf::Time restart();
    
    //Get the time passed.
   	float getTimeAsSeconds();
};
