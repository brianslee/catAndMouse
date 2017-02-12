
#pragma once

class Interactable
{
public:
	explicit Interactable(std::string img, std::string message,std::string name){
		this->name=name;
		this->load(img);
		this->message=message;
		isLoaded=true;
	}
	virtual ~Interactable(){

	}

	virtual std::string getName(){
		return name;
	}

	virtual void load(std::string filename){
		std::cout<<"Loading "+filename<<std::endl;
		image.loadFromFile(filename);
		tx.loadFromImage(image);
		sprite.setTexture(tx);
	}
	virtual void draw(sf::RenderWindow & renderWindow){
		if(isLoaded)
			renderWindow.draw(sprite);
	}
	virtual void setPosition(float x, float y){
		sprite.setPosition(x,y);
	}
	virtual sf::Vector2f getPos(){
		return sprite.getPosition();
	}
	virtual void inspect(){
		if(isLoaded)
			std::cout<<"Inspect around:" + message<<std::endl;
	}
	virtual void setMessage(std::string m){
		this->message=m;
	}
	virtual sf::Sprite& getSprite(){
		return sprite;
	}
	virtual bool getIsLoaded(){
		return isLoaded;
	}
	virtual void setIsLoaded(bool isLoaded){
		this->isLoaded=isLoaded;
	}
//	virtual float distanceToCharacter(Human a){
//		float x=a.getPos().x-this->getPos().x;
//		float y=a.getPos().y-this->getPos().y;
//		return sqrt(pow(x,2)+pow(y,2));
////		return 0;
//	}

private:
	bool isLoaded;
	std::string message;
	sf::Sprite  sprite;
	sf::Image image;
	sf::Texture tx;
	std::string name;

};
