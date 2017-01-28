#include <SFML/Graphics.hpp>
#include <iostream>
#include "helper.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Maze", sf::Style::Titlebar | sf::Style::Close);
	sf::Texture texture,tx2;
	sf::Image image;
	sf::Sprite spr;
	sf::View view;
	
	std::cout << "Loading texture...\n";
	image.loadFromFile("maze.png");
	texture.loadFromImage(image);
	tx2.loadFromFile("Triangle.png");
	spr.setTexture(texture);
	spr.move(0, 0);
	std::cout << "Creating Instances...\n";
	Character::Human player=Character::Human();
	bigMap maze=bigMap();
	std::cout << player.getSprite().getPosition().x << std::endl;

	std::cout << "Initializing...\n";
	maze.load(image);
	player.updateCoor();
	player.getSprite().setTexture(tx2);
	player.getSprite().setScale(0.6, 0.6);

	//for (int i = 0; i < 15; i++)
	//	for (int j = 0; j < 15; j++)
	//		std::cout << i << ' ' << j << ' ' << maze.getWall(i, j) << std::endl;
	while (window.isOpen())
	{
//		std::cout << "Drawing...\n";
		sf::Event event;
		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code)
				{
				case sf::Keyboard::W:
					if (checkAccess(player, 0, maze))
						player.walk(0);
					break;
				case sf::Keyboard::S:
					if (checkAccess(player, 1, maze))
						player.walk(1);
					break;
				case sf::Keyboard::A:
					if (checkAccess(player, 2, maze))
						player.walk(2);
					break;
				case sf::Keyboard::D:
					if (checkAccess(player, 3, maze))
						player.walk(3);
					break;
				default:
					std::cout << player.getCoor().x << ' ' << player.getCoor().y << ' ' << player.getPos().x << ' ' << player.getPos().y << std::endl;
					std::cout << int(player.getPos().x) % 80 << ' ' << int(player.getPos().y) % 80 << endl;
					break;
				}
				view.setCenter(player.getPos());
			}
			window.draw(player.getSprite());
					
				
			
		}

//		maze.updateShade(player.getCoor(), player.getSight());

		window.clear(sf::Color::Green);

//		std::cout << "Drawing Maze...\n";		
		window.draw(spr);

//		std::cout << "Drawing Shade...\n";
		//for (int i = 0; i < 15; i++)
		//	for (int j = 0; j < 15; j++)
		//		window.draw(maze.getShade(i, j));

//		std::cout << "Drawing Player...\n";
		window.draw(player.getSprite());
		window.display();
		int i = 0;
	//	while (i < 500000000) { i++; }
	}

	return 0;
}