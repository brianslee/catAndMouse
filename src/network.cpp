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



void Network::receiveData(sf::Vector2f& playerPos, float& rotation){


	sf::Packet packet;
 	
        if(socket.receive(packet, remoteIP, remotePort) == sf::Socket::Done){

        packet >> playerPos.x >> playerPos.y >> rotation;

	packet.clear();
}
}


void Network::sendData(sf::Vector2f movement, float rotation){

        sf::Packet packet;

        packet << movement.x << movement.y << rotation;

        if(socket.send(packet, IPAddress, sendPort) != sf::Socket::Done){

        return;
}
}

bool Network::isAttack() {

	return attacked;

}

void Network::sendAttack(sf::Vector2f projectilePos, int direction, float angle)
{
	sf::Packet packet;

	packet << projectilePos.x << projectilePos.y << direction << angle;

	if(socket.send(packet, IPAddress, sendPort) != sf::Socket::Done){
        return;
}

}


//Send everything and set to data

void Network::sendAllData(sf::Vector2f& playerPos, int& playerRot, sf::Vector2f& projectilePos, int& projectileDir, float& projectileRot){
sf::Packet packet;

        packet << playerPos.x << playerPos.y << projectilePos.x << projectilePos.y << playerRot << projectileDir << projectileRot;

	if(socket.send(packet, IPAddress, sendPort) != sf::Socket::Done){
        return;
}


}

void Network::receiveAllData(sf::Vector2f& playerPos, int& playerRot, sf::Vector2f& projectilePos, int& projectileDir, float& projectileRot){


	sf::Packet packet;

         if(socket.receive(packet, remoteIP, remotePort) == sf::Socket::Done){

        packet >> playerPos.x >> playerPos.y >> projectilePos.x >> projectilePos.y >> playerRot >> projectileDir >> projectileRot;

        }


}



void Network::receiveAttack(sf::Vector2f& projectilePos, int& direction, float &angle)
{

	sf::Packet packet;	

	 if(socket.receive(packet, remoteIP, remotePort) == sf::Socket::Done){

	packet >> projectilePos.x >> projectilePos.y >> direction >> angle;
		packet.clear();
	}

}
















