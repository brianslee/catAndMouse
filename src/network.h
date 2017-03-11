#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <iostream>


class Network {

public:
	
	//Empty constructor
	Network();
	//Sets up the connection for IP and hardcodes port as 45000 and 45001.
	void setup();
	
	//Only receives data for player movement (for now)
	//Receives a vector2f object, which is the x and y position of the other player 
	sf::Vector2f receiveData();
	
	//Similarly only sends data for player movement (for now).
	//Sends a vector2f object, which is the x and y position of the player 
	void sendData(sf::Vector2f movement);

	std::string getPlayerSelection();

private:
	
	sf::UdpSocket socket;
	sf::IpAddress remoteIP;
    sf::Packet packet;
	unsigned short remotePort;
	unsigned short sendPort;
    std::string playerSelection;
    std::string IPAddress;

};



