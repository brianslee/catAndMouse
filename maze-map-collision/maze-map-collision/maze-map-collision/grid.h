#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class grid {
private:
	sf::RectangleShape shade = sf::RectangleShape(sf::Vector2f(80.0, 80.0));
	bool isWall;
	//    int type; //preserved for later;
public:
	grid() {
		isWall = true;
		shade.setFillColor(sf::Color::Black);
	}
	void setShade(int num) {
		switch (num)
		{
		case 0:
			shade.setFillColor(sf::Color(0, 0, 0, 255));
			break;
		case 1:
			shade.setFillColor(sf::Color(0, 0, 0, 127));
			break;
		case 2:
			shade.setFillColor(sf::Color(0, 0, 0, 0));
			break;
		default:
			break;
		}
	}
	void setWall(bool b) { isWall = b; }
	bool getWall() { return isWall; }
	sf::RectangleShape& getShade() { return shade; }
};
class bigMap {
private:
	int size = 15;
	grid** Map;
	int isDetected[14][14];
	sf::Sprite background;
public:
	bigMap() {
		Map = new grid*[15];
		for (int i = 0; i < 15; i++)
			Map[i] = new grid[15];
	}
	int getSize() { return size; }
	sf::Drawable& getSprite() { return background; }
	sf::Drawable& getShade(int x, int y) { return Map[x][y].getShade(); }
	bool getWall(int x, int y) {
		//        std::cout << x << ' ' << y << std::endl;
		if (x < 0 || y < 0)return 1;
		if (x >= size || y >= size)return 1;
		return Map[x][y].getWall();
	}
	void load(sf::Image &image) {
		//        background.setTexture(texture);
		//        background.setTextureRect(sf::IntRect(0, 0, 15*80, 15*80));
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 15; j++) {
				isDetected[i][j] = 0;
				Map[i][j].getShade().setPosition(80 * (i - 1) - 2, 80 * (j - 1) - 2);

//				std::cout << int(image.getPixel(i * 80, j * 80).r) << ' ' << int(image.getPixel(i * 80, j * 80).g) << ' ' << int(image.getPixel(i * 80, j * 80).b) << endl;
				if (image.getPixel(i * 80, j * 80) == sf::Color(99, 64, 0, 255))
					Map[i][j].setWall(1);
				else Map[i][j].setWall(0);
				//std::cout << i << ' ' << j << ' ' << Map[i][j].getWall() << std::endl;
				isDetected[i][j] = 0;
				Map[i][j].setShade(isDetected[i][j]);
			}
		}
	}
	void updateShade(sf::Vector2i pos, int sight) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				//                std::cout << i << ' ' << j << " " << isDetected[i][j] << std::endl;
				if (isDetected[i][j] == 2) {
					isDetected[i][j] = 1;
				}
			}
		}
		isDetected[pos.x][pos.y] = 2;
		for (int i = 0; i <= sight; i++) {
			for (int j = 0; j <= sight; j++) {
				if ((pos.x + i) < 0 || (pos.x + i) > 15 || (pos.y + j) < 0 || (pos.y + j) > 15)continue;
				if (isDetected[pos.x + i][pos.y + j] == 2) isDetected[pos.x + i][pos.y + j] = 2;
				else if (((i*i + j*j) <= sight*sight)
					//       && (isDetected[pos.x + i - 1][pos.y + j] == 2 || isDetected[pos.x + i][pos.y + j - 1] == 2)
					//       && !(Map[pos.x + i][pos.y + j - 1].getWall() && Map[pos.x + i - 1][pos.y + j].getWall())
					)
					isDetected[pos.x + i][pos.y + j] = 2;

				if ((pos.x + i) < 0 || (pos.x + i) > 15 || (pos.y - j) < 0 || (pos.y - j) > 15)continue;
				if (isDetected[pos.x + i][pos.y - j] == 2) isDetected[pos.x + i][pos.y - j] = 2;
				else if (((i*i + j*j) <= sight*sight)
					//&& (isDetected[pos.x + i - 1][pos.y - j] == 2 || isDetected[pos.x + i][pos.y - j + 1] == 2)
					//&& !(Map[pos.x + i][pos.y - j + 1].getWall() && Map[pos.x + i - 1][pos.y - j].getWall())
					)
					isDetected[pos.x + i][pos.y + j] = 2;

				if ((pos.x - i) < 0 || (pos.x - i) > 15 || (pos.y + j) < 0 || (pos.y + j) > 15)continue;
				if (isDetected[pos.x - i][pos.y + j] == 2) isDetected[pos.x - i][pos.y + j] = 2;
				else if (((i*i + j*j) <= sight*sight)
					//&& (isDetected[pos.x - i + 1][pos.y + j] == 2 || isDetected[pos.x - i][pos.y + j - 1] == 2)
					//&& !(Map[pos.x - i][pos.y + j - 1].getWall() && Map[pos.x - i + 1][pos.y + j].getWall())
					)
					isDetected[pos.x - i][pos.y + j] = 2;

				if ((pos.x - i) < 0 || (pos.x - i) > 15 || (pos.y - j) < 0 || (pos.y - j) > 15)continue;
				if (isDetected[pos.x - i][pos.y - j] == 2) isDetected[pos.x - i][pos.y - j] = 2;
				else if (((i*i + j*j) <= sight*sight)
					//&& (isDetected[pos.x - i + 1][pos.y - j] == 2 || isDetected[pos.x - i][pos.y - j + 1] == 2)
					//&& !(Map[pos.x - i][pos.y - j + 1].getWall() && Map[pos.x - i][pos.y - j + 1].getWall())
					)
					isDetected[pos.x - i][pos.y - j] = 2;
			}
		}
		for (int i = -sight; i <= sight; i++)
			for (int j = -sight; j <= sight; j++) {
				if ((pos.x + i) < 0 || (pos.x + i) > 15 || (pos.y + j) < 0 || (pos.y + j) > 15)continue;
				Map[pos.x + i][pos.y + j].setShade(isDetected[pos.x + i][pos.y + j]);
			}
	}
};