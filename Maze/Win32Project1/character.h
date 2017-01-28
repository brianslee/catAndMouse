#include <SFML/Graphics.hpp>
#include <utility>

using namespace std;

namespace Character {
	class Human {
	private:
		sf::Vector2i position;
		sf::Sprite sprite;
		int speed;
		int sight;
	public:
		Human(sf::Vector2i initPos = sf::Vector2i(0, 0), int v = 3, int s = 3) {
			position = initPos;
			speed = v;
			sight = s;
		}
		sf::Sprite& getSprite() { return sprite; }
		sf::Vector2i getCoor() { return position; }
		int getSpeed() { return speed; }
		int getSight() { return sight; }
		sf::Vector2f getPos() { return sprite.getPosition(); }
		void setCoor(sf::Vector2i coor) { position = coor; sprite.setPosition(80 * coor.x + 40, 80 * coor.y + 40); }
		void setSpeed(int v) { speed = v; }
		void setSight(int s) { sight = s; }
		void updateCoor() { position = sf::Vector2i(int((sprite.getPosition().x) / 80.0), int((sprite.getPosition().y) / 80.0)); }
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
	};
}