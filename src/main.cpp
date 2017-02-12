#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "helper.h"
#include "Chest.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Maze", sf::Style::Titlebar | sf::Style::Close);
	sf::Texture texture, tx2;
	sf::Image image;
	sf::Sprite spr;
	sf::View view(sf::FloatRect(0, 0, 800, 800));

	Item item_test=Item("img/circle.png","Damage Trap","Item");
	Item item_test2=Item("img/circle.png","Sword","Item");
	Chest ch=Chest("It looks safe");
	Chest ch2=Chest("It's a chest");
	ch.setItem(&item_test2);
	ch2.setItem(&item_test);
	std::vector<Interactable*> itemsList;

	itemsList.push_back(&ch);
	itemsList.push_back(&item_test2);
	itemsList.push_back(&ch2);
	itemsList.push_back(&item_test);

	for(unsigned i=0;i<itemsList.size();i++)
		itemsList[i]->getSprite().setScale(0.6,0.6);

	ch.setPosition(1000,300);
	ch2.setPosition(300,200);
	item_test.setIsLoaded(false);
	item_test2.setIsLoaded(false);

	window.setView(view);
	std::cout << "Loading texture...\n";
	image.loadFromFile("img//maze.png");
	texture.loadFromImage(image);
	tx2.loadFromFile("img//triangle.png");
	spr.setTexture(texture);
	spr.move(0, 0);



	std::cout << "Creating Instances...\n";
	Human player = Human();
	bigMap maze = bigMap();
	std::cout << player.getSprite().getPosition().x << std::endl;

	std::cout << "Initializing...\n";
	maze.load(image);
	player.updateCoor();
	player.getSprite().setTexture(tx2);
	player.getSprite().setScale(0.6, 0.6);

	//for (int i = 0; i < 15; i++)
	//    for (int j = 0; j < 15; j++)
	//        std::cout << i << ' ' << j << ' ' << maze.getWall(i, j) << std::endl;
	while (window.isOpen())
	{
		//        std::cout << "Drawing...\n";
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code)
				{
				case sf::Keyboard::F:
					player.inspect(itemsList);
					break;
				case sf::Keyboard::E:
					player.react(itemsList);
					break;
				case sf::Keyboard::LShift:
					if(player.getSpeed()==3)
						player.setSpeed(10);
					else
						player.setSpeed(3);
					break;
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
					std::cout << int(player.getPos().x) % 80 << ' ' << int(player.getPos().y) % 80 << std::endl;
					std::cout << maze.getWall(player.getCoor().x, player.getCoor().y) << std::endl;

					break;
				}
				view.setCenter(getCenter(player.getPos(), image.getSize()));
				window.setView(view);
			}
			window.draw(player.getSprite());



		}

		//        maze.updateShade(player.getCoor(), player.getSight());

		window.clear(sf::Color::Green);

		//        std::cout << "Drawing Maze...\n";

		window.draw(spr);

		for(unsigned int i=0;i<itemsList.size();i++){
			itemsList[i]->draw(window);
		}

		//        std::cout << "Drawing Shade...\n";
		//for (int i = 0; i < 15; i++)
		//    for (int j = 0; j < 15; j++)
		//        window.draw(maze.getShade(i, j));

		//        std::cout << "Drawing Player...\n";

		window.draw(player.getSprite());
		window.display();
//		int i = 0;
		//    while (i < 500000000) { i++; }
	}

	return 0;
}
