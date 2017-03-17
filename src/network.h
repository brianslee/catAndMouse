#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <iostream>


class Network {

public:
	
	//Empty constructor
	Network();
	//Sets up the connection for IP and hardcodes port as 45000 and 45001.
	void setup();
	
	//Show if main character is marine
	bool isMarine(){return marine;}

	//Send all data
	void sendAllData(sf::Vector2f& playerPos, sf::Vector2f& rectPos,int& playerRot, sf::Vector2f& projectilePos, int& projectileDir, float& projectileRot);
	
	//receive all data

	void receiveAllData(sf::Vector2f& playerPos,sf::Vector2f& rectPos, int& playerRot, sf::Vector2f& projectilePos, int& projectileDir, float& projectileRot);



private:
	
	sf::UdpSocket socket;

	sf::IpAddress remoteIP; 

	
    //sf::Packet packet;
	unsigned short remotePort;
	unsigned short sendPort;
    std::string playerSelection;
    std::string IPAddress;
	bool marine;
	sf::Vector2f playerPos, projectilePos;
	float angle;
	int direction;


};



