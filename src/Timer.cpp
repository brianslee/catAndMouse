#include "Timer.h"

Timer::Timer(){

}

sf::Time Timer::restart(){
	return clock.restart();
}

float Timer::getTimeAsSeconds(){
	return clock.getElapsedTime().asSeconds();
}
