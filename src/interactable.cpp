#include "interactable.h"
interactable::interactable(std::string img, std::string message,std::string type){
	this->type=type;
	scaleFactor=1;
	this->load(img);
	this->message=message;
	isLoaded=true;
	spriteX=0;
	spriteY=0;

}

interactable::interactable(std::string img, std::string message,std::string type,float scale){
	this->type=type;
	scaleFactor=scale;
	this->load(img);
	this->message=message;
	isLoaded=true;
	spriteX=0;
	spriteY=0;

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
	sprite.setScale(scaleFactor,scaleFactor);
}

 void interactable::setRect(int left, int top, int width, int height){
 	spriteX=width;
 	spriteY=height;
 	sf::IntRect intRect(left,top,width,height);
 	rect=intRect;
 	sprite.setTextureRect(rect);
 }

 void interactable::draw(sf::RenderWindow & renderWindow){
	if(isLoaded)
		renderWindow.draw(sprite);
}

 void interactable::updateSprite(int gridX,int gridY){
	if(gridX==0)
		 rect.left=0;
	if(gridY==0)
		 rect.top=0;
	for(int i=0;i<gridX;i++)
		rect.left+=spriteX;
	for(int i=0;i<gridY;i++)
		rect.top+=spriteY;
	sprite.setTextureRect(rect);
 }

 void interactable::setPosition(float x, float y){
	sprite.setPosition(x,y);
}

 void interactable::setPosition(sf::Vector2f pos){
	sprite.setPosition(pos);
}

 sf::Vector2f interactable::getPos(){
	 //get the center point of the sprite.
	sf::Vector2f vect(sprite.getPosition().x+this->spriteX*scaleFactor/2,
			sprite.getPosition().y+this->spriteY*scaleFactor/2);
	return vect;
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


