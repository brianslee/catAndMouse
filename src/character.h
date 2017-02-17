#include <SFML/Graphics.hpp>
#include <utility>
#include <vector>
#include <cmath>
#include <typeinfo>
#include "Interactable.h"
#include "Chest.h"


class Human {
	private:
		sf::Vector2i position;
		sf::Sprite sprite;
		int speed;
		int sight;
		int hp;
	public:
		Human(sf::Vector2i initPos = sf::Vector2i(0, 0), int v = 3, int s = 3) {
			position = initPos;
			speed = v;
			sight = s;
			hp=100;
		}
		sf::Sprite& getSprite() { return sprite; }
		sf::Vector2i getCoor() { return position; }
		int getSpeed() { return speed; }
		int getSight() { return sight; }
		int getHp(){ return hp;}
		void setHp(int h){hp=h;}
		sf::Vector2f getPos() { return sprite.getPosition(); }
		void setCoor(sf::Vector2i coor) {
			position = coor;
			sprite.setPosition(80 * coor.x + 40, 80 * coor.y + 40);
		}
		void setSpeed(int v) { speed = v; }
		void setSight(int s) { sight = s; }
		void updateCoor() {
			position = sf::Vector2i(int((sprite.getPosition().x) / 80.0), int((sprite.getPosition().y) / 80.0));
		}
		void walk(int dir) {
			//map up/down/left/right to 0/1/2/3
			updateCoor();
			switch (dir)
			{
			case 0:
				sprite.move(0.0, (float(speed)*(-1)));
				break;
			case 1:
				sprite.move(0.0, (float(speed)*(1)));
				break;
			case 2:
				sprite.move(float(speed)*(-1), 0.0);
				break;
			case 3:
				sprite.move(float(speed)*(1), 0.0);
				break;
			default:
				break;
			}
			updateCoor();
		}

		int distanceToInteractable(Interactable* item){
				int x=item->getPos().x-this->getPos().x;
				int y=item->getPos().y-this->getPos().y;
				return sqrt(pow(x,2)+pow(y,2));
			}

		void inspect(std::vector<Interactable*> itemsList){
			for(unsigned int i=0;i<itemsList.size();i++){
				if(distanceToInteractable(itemsList[i])<80){
					itemsList[i]->inspect();
				}
			}
		}

		void react(std::vector<Interactable*> itemsList){
			for(unsigned int i=0;i<itemsList.size();i++){
				if(distanceToInteractable(itemsList[i])<80){
					bool itemLoaded=itemsList[i]->getIsLoaded();
					std::string type=itemsList[i]->getType();
					if(type=="Chest"){
						Chest* ch=dynamic_cast<Chest*>(itemsList[i]);
						if(!ch->getIsOpen()){
							std::cout<<"type==Chest\n";
//							(dynamic_cast <Chest*> (itemsList[i]))->open();
							ch->open();
							break;
						}
					}
					if(itemLoaded&&(type=="Item"||type=="DamageTrap")){
						std::cout<<"type==Item\n";
						//get Item
						if(itemsList[i]->getIsLoaded())
							itemsList[i]->setIsLoaded(false);
						break;
					}

				}
			}
		}



	};

