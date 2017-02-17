#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <string>


#define TILE_SIZE 40.f

using namespace std;

class Networking {

	sf::UdpSocket socket;
	sf::IpAddress remoteIP;
	sf::Packet packet;
	unsigned short remotePort;
	unsigned short sendPort;
	sf::String msg = "CONNECTED";
	std::string consoleInput;
	std::string IPAddress;

	


public: 

	Networking() {

	}
	
	void Connect() {
		cout << "Enter IP address: ";
		cin >> IPAddress;

		cout << "Enter 'marine' or 'alien: ";
		cin >> consoleInput;
		

		if (consoleInput == "marine")
		{

			socket.bind(45000);
			sendPort = 45001;

		}
		else
		{
			socket.bind(45001);
			sendPort = 45000;


		}

		socket.setBlocking(false);

	}
	

	void sendPacket(sf::Vector2f position)
	{
		//check if change in value, if so send our position 
		
			sf::Packet packet;
			packet << position.x << position.y;

			
			if (socket.send(packet, IPAddress, sendPort) == sf::Socket::Done)
			{
				std::cout << "Sending"<<endl;
				return;
			}
	}


	sf::Vector2f receivePacket()
	{
		sf::Vector2f pos;
		if (socket.receive(packet, remoteIP, remotePort) == sf::Socket::Done)
		{
			packet >> pos.x >> pos.y;
			std::cout << pos.x << " " << pos.y<<endl; 
		}

		return pos;
	}


	



	//establish connection using tcp listener



	//set up the window
	
	


	//create the player objects

	//while (window.isOpen())
	//{
	//	sf::Vector2i moveDir;
	//	sf::Event event;

	//	while (window.pollEvent(event))
	//	{
	//		//check for different events from the window
	//		//in this case, key presses to control our character

	//		switch (event.type)
	//		{
	//		case sf::Event::KeyPressed:
	//			if (event.key.code == sf::Keyboard::W)
	//				moveDir.y += -1;
	//			else if (event.key.code == sf::Keyboard::A)
	//				moveDir.x += -1;
	//			else if (event.key.code == sf::Keyboard::S)
	//				moveDir.y += 1;
	//			else if (event.key.code == sf::Keyboard::D)
	//				moveDir.x += 1;
	//			break;

	//		case sf::Event::Closed:
	//			window.close();
	//			break;

	//		}
	//	}


		// receiving data and updating enemy's position



		


	
};


