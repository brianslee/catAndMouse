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
	void receiveData(sf::Vector2f& playerPos, float& rotation);
	
	//Similarly only sends data for player movement (for now).
	//Sends a vector2f object, which is the x and y position of the player 
	void sendData(sf::Vector2f movement, float rotation);

	//Sending attack information
	void sendAttack(sf::Vector2f projectilePos, int direction, float angle);


	//Check if the other player attacked
	bool isAttack();

	//Show if main character is marine
	bool isMarine(){return marine;}

	//Receiving attack information
	void receiveAttack(sf::Vector2f& projectilePos, int & direction, float& angle); 
	
	//Send all data
	void sendAllData(sf::Vector2f& playerPos, sf::Vector2f& projectilePos, int& direction, float& angle);
	
	//receive all data
	void receiveAllData(sf::Vector2f& playerPos, sf::Vector2f& projectilePos, int& direction, float &angle);

	std::string getPlayerSelection();

private:
	
	sf::UdpSocket socket;
	sf::IpAddress remoteIP;
    sf::Packet packet;
	unsigned short remotePort;
	unsigned short sendPort;
    std::string playerSelection;
    std::string IPAddress;
	bool attacked, marine;
	sf::Vector2f playerPos, projectilePos;
	float angle;
	int direction;


};



