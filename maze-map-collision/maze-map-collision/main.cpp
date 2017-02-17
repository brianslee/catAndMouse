#include <SFML/Graphics.hpp>
#include <iostream>
#include "helper.h"
#include "networking.h"

int main()
{
	Networking network;
	sf::RenderWindow window(sf::VideoMode(800, 800), "Maze", sf::Style::Titlebar | sf::Style::Close);
	sf::Texture texture, tx2;
	sf::Texture marineTexture,alienTexture;
	sf::Image image;
	sf::Sprite spr;
	sf::View view(sf::FloatRect(0, 0, 800, 800));
	window.setView(view);
	std::cout << "Loading texture...\n";
	if (!image.loadFromFile("img//maze.png")) {
		image.loadFromFile("maze.png");
	}
	texture.loadFromImage(image);
	if (!tx2.loadFromFile("img//triangle.png")) {
		tx2.loadFromFile("triangle.png");
	}
	if (!marineTexture.loadFromFile("img//Space_Marine1_SpriteSheet.png")) {
		marineTexture.loadFromFile("Space_Marine1_SpriteSheet.png");
	}
	if (!alienTexture.loadFromFile("img//Alien_1_Movement2.png")) {
		alienTexture.loadFromFile("Alien_1_Movement2.png");
	}
	spr.setTexture(texture);
	spr.move(0, 0);


	//prompt for IP addresses
	network.Connect();

	//choose player types



	std::cout << "Creating Instances...\n";
	Human player = Human(sf::Vector2i(0,0),10,3);
	Human playerAway = Human(sf::Vector2i(0, 0), 10, 3);
	playerAway.getSprite().setTexture(tx2);
	
	bigMap maze = bigMap();
	
	std::cout << "Initializing...\n";
	maze.load(image);
	player.updateCoor();

//	player.getSprite().setTexture(tx2);
//	player.getSprite().setScale(0.6, 0.6);
//	player.getSprite().setOrigin(sf::Vector2f(40, 40));
//	player.getSprite().move(40, 40);
//	updateSprite(player.getSprite(), marineTexture, window, 215, 215, 4);
	//for (int i = 0; i < 15; i++)
	//    for (int j = 0; j < 15; j++)
	//        std::cout << i << ' ' << j << ' ' << maze.getWall(i, j) << std::endl;
	int spriteCounter = 0, spriteNum = 9, spriteLength = 196, spriteWidth = 118;
	player.getSprite().setTexture(marineTexture);
	player.getSprite().setTextureRect(sf::IntRect(((spriteCounter) % 2)*spriteLength, (spriteCounter / 2)*spriteWidth, ((spriteCounter) % 2 + 1)*spriteLength, (spriteCounter / 2 + 1)*spriteWidth));
	player.getSprite().setScale(78.0 / (double)(spriteLength), 78.0 / (double)(spriteWidth));
	sf::Clock clock;
	player.getSprite().setOrigin(sf::Vector2f(spriteLength/2, spriteWidth/2));
	player.getSprite().move(40, 40);
	while (window.isOpen())
	{


		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code)
				{
				case sf::Keyboard::W:
			//		if (checkAccess(player, 0, maze))
						player.walk(0);
					break;
				case sf::Keyboard::S:
			//		if (checkAccess(player, 1, maze))
						player.walk(1);
					break;
				case sf::Keyboard::A:
			//		if (checkAccess(player, 2, maze))
						player.walk(2);
					break;
				case sf::Keyboard::D:
			//		if (checkAccess(player, 3, maze))
						player.walk(3);
					break;
				default:
					std::cout << player.getCoor().x << ' ' << player.getCoor().y << ' ' << player.getPos().x << ' ' << player.getPos().y << std::endl;
					std::cout << int(player.getPos().x) % 80 << ' ' << int(player.getPos().y) % 80 << endl;
					std::cout << maze.getWall(player.getCoor().x, player.getCoor().y) << endl;

					std::cout << playerAway.getCoor().x << ' ' << playerAway.getCoor().y << ' ' << playerAway.getPos().x << ' ' << playerAway.getPos().y << std::endl;
					std::cout << int(playerAway.getPos().x) % 80 << ' ' << int(playerAway.getPos().y) % 80 << endl;
					std::cout << maze.getWall(playerAway.getCoor().x, playerAway.getCoor().y) << endl;

					break;
				}

				//SENDING DATA
				sf::Vector2f playerPosition = player.getSprite().getPosition();
				network.sendPacket(playerPosition);

				view.setCenter(getCenter(player.getPos(), image.getSize()));
				window.setView(view);


			}
			
			spriteCounter = updateSprite(player.getSprite(), window, clock, spriteLength, spriteWidth, spriteNum, spriteCounter);
			//window.draw(player.getSprite());
			
			updateRotation(player, view, window);

			//Get enemy position
			sf::Vector2f enemyPos = network.receivePacket();
			playerAway.setPos(enemyPos);
			window.draw(playerAway.getSprite());
		}

		//        maze.updateShade(player.getCoor(), player.getSight());

		window.clear(sf::Color::Green);

		//        std::cout << "Drawing Maze...\n";        
		window.draw(spr);

		//        std::cout << "Drawing Shade...\n";
		//for (int i = 0; i < 15; i++)
		//    for (int j = 0; j < 15; j++)
		//        window.draw(maze.getShade(i, j));

		//        std::cout << "Drawing Player...\n";
		window.draw(player.getSprite());
		window.draw(playerAway.getSprite());
		window.display();
	}

	return 0;
}