#include "network.h"

Network::Network(){}



void Network::setup(){

         
	std:: cout <<"Enter IP address of your opponent: ";
	std::cin >> IPAddress;

		
        std::cout << "Enter 'm' for Marine or 'a' for Alien: ";
        std::cin >> playerSelection;

//Set the networking ports for each character 
//Also set the forwarding port

        if (playerSelection == "m")
        {

                socket.bind(45000);
                sendPort = 45001;
		marine = true;
		

        }
        else
        {
                socket.bind(45001);
                sendPort = 45000;
		marine = false;


        }



        socket.setBlocking(false);

}



//Send everything and set to data

void Network::sendAllData(sf::Vector2f& playerPos, sf::Vector2f& rectPos, int& playerRot, sf::Vector2f& projectilePos, int& projectileDir, float& projectileRot){
	sf::Packet packet;
	packet << playerPos.x << playerPos.y << rectPos.x << rectPos.y << projectilePos.x << projectilePos.y << playerRot << projectileDir << projectileRot;
	if(socket.send(packet, IPAddress, sendPort) != sf::Socket::Done){
        return;
	}
}

void Network::receiveAllData(sf::Vector2f& playerPos, sf::Vector2f& rectPos, int& playerRot, sf::Vector2f& projectilePos, int& projectileDir, float& projectileRot){
	sf::Packet packet;
	if(socket.receive(packet, remoteIP, remotePort) == sf::Socket::Done){
        packet >> playerPos.x >> playerPos.y >>rectPos.x>>rectPos.y>> projectilePos.x >> projectilePos.y >> playerRot >> projectileDir >> projectileRot;
	}
}

void Network::sendIATypeChanged(short iaTypeChanged){
	sf::Packet packet;
	packet<<iaTypeChanged;
//	if(socket.send(packet))
}

void Network::receiveIATypeChanged(short iaTypeChanged){
	sf::Packet packet;
	if(socket.receive(packet,remoteIP,remotePort)==sf::Socket::Done){
		packet>>iaTypeChanged;
	}
	std::cout<<"Type changed "<<iaTypeChanged<<std::endl;
}


