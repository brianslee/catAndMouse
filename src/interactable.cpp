#include "interactable.h"
interactable::interactable(std::string img, std::string message,std::string type){
	this->type=type;
	this->load(img);
	this->message=message;
	isLoaded=true;
}

std::string interactable::getType(){
	return type;
}

interactable::~interactable(){

	}


 void interactable::load(std::string filename){
	std::cout<<"Loading "+filename<<std::endl;
	image.loadFromFile(filename);
	tx.loadFromImage(image);
	sprite.setTexture(tx);
}

 void interactable::draw(sf::RenderWindow & renderWindow){
	if(isLoaded)
		renderWindow.draw(sprite);
}

 void interactable::setPosition(float x, float y){
	sprite.setPosition(x,y);
}

 void interactable::setPosition(sf::Vector2f pos){
	sprite.setPosition(pos);
}

 sf::Vector2f interactable::getPos(){
	return sprite.getPosition();
}

 void interactable::inspect(){
	if(isLoaded)
		std::cout<<"Inspect around:" + message<<std::endl;
}

 void interactable::setMessage(std::string m){
	this->message=m;
}

 sf::Sprite& interactable::getSprite(){
	return sprite;
}

 bool interactable::getIsLoaded(){
	return isLoaded;
}

 void interactable::setIsLoaded(bool isLoaded){
	this->isLoaded=isLoaded;
}
//	 float distanceToCharacter(Human a){
//		float x=a.getPos().x-this->getPos().x;
//		float y=a.getPos().y-this->getPos().y;
//		return sqrt(pow(x,2)+pow(y,2));
////		return 0;
//	}


