#include "interactable.h"
interactable::interactable(std::string img, std::string message,std::string type){
	this->type=type;
	scaleFactor=1;
	this->load(img);
	this->message=message;
	isLoaded=true;
//	spriteX=0;
//	spriteY=0;

	curGridX=0;
	curGridY=0;

}

interactable::interactable(std::string img, std::string message,std::string type,float scale){
	this->type=type;
	scaleFactor=scale;
	this->load(img);
	this->message=message;
	isLoaded=true;
	curGridX=0;
	curGridY=0;
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
	curGridX=gridX;
	curGridY=gridY;
	rect.left=0;
	rect.top=0;
	for(int i=0;i<gridX;i++)
		rect.left+=spriteX;
	for(int i=0;i<gridY;i++)
		rect.top+=spriteY;
	sprite.setTextureRect(rect);
 }

 void interactable::animation(int startGridX,int endGridX,int startGridY, int endGridY,bool rowFirst,float time){
	 if(curGridX==endGridX&&curGridY==endGridY)
		 return ;
	 if(clock.getElapsedTime().asSeconds()>time){
		 int increment;
		 if(startGridY>endGridY||startGridX>endGridX)
			 increment=-1;
		 else
			 increment=1;
		 if(rowFirst){
			 if(curGridX==endGridX){
				 curGridX=startGridX;
				 if(curGridY==endGridY)
					 curGridY=startGridY;
				 else
					 curGridY+=increment;
			 }else
				 curGridX+=increment;
		 }else{
			 if(curGridY==endGridY){
				 curGridY=startGridY;
				 if(curGridX==endGridX)
					 curGridX=startGridX;
				 else
					 curGridX+=increment;
			 }else
				 curGridY+=increment;
		 }
		 updateSprite(curGridX,curGridY);
		 clock.restart();
	 }
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



