#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <iostream>


class Network {

public:
	Network();
	sf::Vector2f receiveData();
	void setup();
	void sendData(sf::Vector2f movement);


private:

	sf::UdpSocket socket;
	sf::IpAddress remoteIP;
        sf::Packet packet;
        unsigned short remotePort;
	unsigned short sendPort;
        std::string playerSelection;
        std::string IPAddress;

};



