#include "network.hpp"

Network::Network(){}



void Network::setup(){

         
	std:: cout <<"Enter IP address of your opponent: ";
	std::cin >> IPAddress;
       //  IPAddress = "172.16.57.133";
		
        std::cout << "Enter 'm' for Marine or 'a' for Alien: ";
        std::cin >> playerSelection;

//Set the networking ports for each character 
//Also set the forwarding port

        if (playerSelection == "m")
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



sf::Vector2f Network::receiveData(){

 sf::Vector2f pos;
        if(socket.receive(packet, remoteIP, remotePort) == sf::Socket::Done){

        packet >> pos.x >> pos.y;
}

return pos;

}


void Network::sendData(sf::Vector2f movement){

        sf::Packet packet;

        packet << movement.x << movement.y;

        if(socket.send(packet, IPAddress, sendPort) != sf::Socket::Done){

        return;
}



}


















