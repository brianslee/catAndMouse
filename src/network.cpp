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

void Network::sendAllData(sf::Vector2f& playerPos, sf::Vector2f& rectPos,
		int& playerRot, sf::Vector2f& projectilePos, int& projectileDir, float& projectileRot,
		InteractableManager* im,bool& update,bool& playerLoaded,int& playerHP){
	sf::Packet packet;
	packet << playerPos.x<< playerPos.y << rectPos.x << rectPos.y << projectilePos.x << projectilePos.y;
	packet << playerRot << projectileDir << projectileRot<<update;
	packet << playerLoaded<<playerHP;
	std::vector<interactable*> iaList=im->getIAList();
	for(int i=0;i<iaList.size();i++){
		bool isLoaded=false,occupied=false,isDeployed=false,activated=false,isOpen=false,isOccupied=false,lockerDoor=false;
		sf::Vector2f pos;
		std::string type=iaList[i]->getType();
		isLoaded=iaList[i]->getIsLoaded();
		if(type=="Item"||type=="DamageTrap"||type=="StickyTrap"){
			Item* it=dynamic_cast<Item*>(iaList[i]);
			occupied=it->getOccupied();
			pos=it->getSpritePos();
			if(type=="DamageTrap"||type=="StickyTrap"){
				trap* tp=dynamic_cast<trap*>(iaList[i]);
				isDeployed=tp->getIsDeployed();
				activated=tp->isActivated();
			}
		}
		if(type=="Table"||type=="Locker"){
			hidingPlace* hp=dynamic_cast<hidingPlace*>(iaList[i]);
			isOccupied=hp->getIsOccupied();
			lockerDoor=hp->getDoorOpen();
		}
		if(type=="Chest"){
			chest* ch=dynamic_cast<chest*>(iaList[i]);
			isOpen=ch->getIsOpen();
		}
		packet<<isLoaded<<pos.x<<pos.y<<occupied<<isDeployed<<activated<<isOpen<<isOccupied<<lockerDoor;
//		std::cout<<"Sent isDeployed: "<<isDeployed<<" Send posX: "<<pos.x<<" Send posY: "<<pos.y<<std::endl;

	}
//	if(packet.getDataSize()>40)
//		std::cout<<packet.getDataSize()<<std::endl;
	if(socket.send(packet, IPAddress, sendPort) != sf::Socket::Done){
        return;
	}
}

void Network::receiveAllData(sf::Vector2f& playerPos, sf::Vector2f& rectPos, int& playerRot,
		sf::Vector2f& projectilePos, int& projectileDir, float& projectileRot,
		InteractableManager* im, bool& player2Loaded, int& player2HP){
	sf::Packet packet;
	bool update;
	if(socket.receive(packet, remoteIP, remotePort) == sf::Socket::Done){
       packet >> playerPos.x>> playerPos.y >>rectPos.x>>rectPos.y>>projectilePos.x >> projectilePos.y;
       packet >> playerRot >> projectileDir >> projectileRot>>update;
       packet >> player2Loaded>>player2HP;

       bool isLoaded,occupied,isDeployed,activated,isOpen,isOccupied,lockerDoor;
       sf::Vector2f pos;
       std::vector<interactable*> iaList=im->getIAList();
       	for(int i=0;i<iaList.size();i++){
       		packet>>isLoaded>>pos.x>>pos.y>>occupied>>isDeployed>>activated>>isOpen>>isOccupied>>lockerDoor;
            if(update){
//				std::cout<<"Received isDeployed: "<<isDeployed<<" Received pos X: "<<pos.x<<" Y: "<<pos.y<<std::endl;
				std::string type=iaList[i]->getType();
				iaList[i]->setIsLoaded(isLoaded);
				if(type=="Item"||type=="DamageTrap"||type=="StickyTrap"){
					Item* it=dynamic_cast<Item*>(iaList[i]);
					it->setOccupied(occupied);
					it->setPosition(pos);
					if(type=="DamageTrap"||type=="StickyTrap"){
						trap* tp=dynamic_cast<trap*>(iaList[i]);
						tp->setIsDeployed(isDeployed);
						tp->setActivated(activated);
					}
				}
				if(type=="Table"||type=="Locker"){
					hidingPlace* hp=dynamic_cast<hidingPlace*>(iaList[i]);
					hp->setIsOccupied(isOccupied);
					hp->setDoorOpen(lockerDoor);
				}
				if(type=="Chest"){
					chest* ch=dynamic_cast<chest*>(iaList[i]);
					ch->setIsOpen(isOpen);
				}
            }//end if should Change
       	}

	}
}


