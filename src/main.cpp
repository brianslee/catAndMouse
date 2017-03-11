//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <SFML/Audio.hpp>
#include <vector>

#include "alienattack.h"
#include "attack.h"
#include "chest.h"
#include "damageTrap.h"
#include "entity.h"
#include "helper.h"
#include "network.h"
#include "locker.h"

    int spriteCounter = 0, spriteNum = 4, spriteLength = 215, spriteWidth = 215;
    int mSpriteCounter = 0, mSpriteNum = 9, mSpriteLength = 216, mSpriteWidth = 216;


//setup player sprites
void setupPlayer(Human & player, sf::Texture& texture, int x, int y){
    player.getSprite().setTexture(texture);
    player.getSprite().setTextureRect(sf::IntRect(((spriteCounter) % 2)*spriteLength, (spriteCounter / 2)*spriteWidth,
                                        ((spriteCounter) % 2 + 1)*spriteLength, (spriteCounter / 2 + 1)*spriteWidth));
    player.getSprite().setScale(78.0 / (double)(spriteLength), 78.0 / (double)(spriteWidth)); 
    player.getSprite().setOrigin(sf::Vector2f(spriteLength/2, spriteWidth/2));
    player.getSprite().move(x,y);
}

void setupMarine(Human & player, sf::Texture& texture, int x, int y)
{
    player.getSprite().setTexture(texture);
    player.getSprite().setTextureRect(sf::IntRect(0, 0, mSpriteLength, mSpriteWidth));
    player.getSprite().setScale(78.0 / (double)(mSpriteLength), 78.0 / (double)(mSpriteWidth)); 
    player.getSprite().setOrigin(sf::Vector2f(mSpriteLength/2, mSpriteWidth/2));
    player.getSprite().move(x,y);
}


int main()
{
    
    sf::Clock clock;
    sf::Clock clock2;
    sf::Clock clock3;
    sf::Clock clock4;
	sf::Clock packetSendClock;
    float playerMovementSpeed = 8;
    
    int counterWalking = 0;
    int counter = 0;
    int counter2 = 0;
    int counter3 = 0;
    int counter4 = 0;
    int counter5 = 0;

    sf::RenderWindow window(sf::VideoMode(800, 800), "Cat And Mouse", sf::Style::Titlebar | sf::Style::Close);
    sf::Texture texture,tx2,marineTexture,alienTexture;
    sf::Image image;
    sf::Sprite spr, spr2;
    sf::View view(sf::FloatRect(0, 0, 800, 800));
    window.setView(view);
    
    Network network;  
    network.setup();

    std::cout << "Loading texture...\n";
    
    if (!image.loadFromFile("img/firstmap.png")) {
        return EXIT_FAILURE;
    }

    if (!texture.loadFromFile("img/mapspr.png")){
    	return EXIT_FAILURE;
	}

    
    if (!alienTexture.loadFromFile("img/alien.png")) {
        return EXIT_FAILURE;
    }
    if (!marineTexture.loadFromFile("Spritesheets/Space_Marine1-2.png")) {
        return EXIT_FAILURE;
    }
    spr.setTexture(texture);

    spr.move(0, 0);
    std::cout << "Creating Instances...\n";
    Human player = Human(sf::Vector2i(5,5),9,3);
    Human player2 = Human(sf::Vector2i(5,9),9,3);

    bigMap maze = bigMap(30);

	//Item
	Item item_test=Item("img/circle.png","Testing");
	Item rifle=Item("Spritesheets/rifle1.png","Rifle",2.f);
	chest ch=chest(&rifle);
	chest ch2=chest();
	chest ch3=chest(&item_test);

	damageTrap dt1=damageTrap(20);
	damageTrap dt2=damageTrap(20);
	ch2.setItem(&dt2);

	locker lo1=locker(1);

	std::vector<interactable*> itemsList;

	itemsList.push_back(&lo1);
	itemsList.push_back(&ch);
	itemsList.push_back(&ch2);
	itemsList.push_back(&ch3);
	itemsList.push_back(&item_test);
	itemsList.push_back(&rifle);

	itemsList.push_back(&dt1);
	itemsList.push_back(&dt2);

	lo1.setPosition(320,1050);
	ch.setPosition(1000,1000);
	ch2.setPosition(300,200);
	ch3.setPosition(400,2000);

	//Item ends
    

    std::vector<projectile2>::const_iterator iter2;
    std::vector<projectile2> projectileArray2;
    
    // Projectile Object
    class projectile2 projectile2;
    
    std::cout << "Initializing...\n";
    maze.load(image);
    if(network.getPlayerSelection()=="m"){
		setupMarine(player, marineTexture, 280, 440);
		setupPlayer(player2, alienTexture, 1720, 2140);
    }else{
    	setupPlayer(player, alienTexture, 1720, 2140);
    	setupMarine(player2, alienTexture, 280, 440);
    }
    player.updateCoor();

    //player2.updateCoor();
    //setupMarine(player, marineTexture);
    //setupPlayer(player, alienTexture);
    //setupPlayer(player2, tx2);    
    //player2.updateCoor();
    player2.updateCoor(); 
    
    //	player.getSprite().setTexture(tx2);
    //	player.getSprite().setScale(0.6, 0.6);
    //	player.getSprite().setOrigin(sf::Vector2f(40, 40));
    //	player.getSprite().move(40, 40);
    //	updateSprite(player.getSprite(), marineTexture, window, 215, 215, 4);
    //for (int i = 0; i < 15; i++)
    //    for (int j = 0; j < 15; j++)
    //        std::cout << i << ' ' << j << ' ' << maze.getWall(i, j) << std::endl;
 
  
    sf::Clock clock_original;


    while (window.isOpen())
    {
        //		std::cout << "Drawing...\n";
       
	sf::Vector2f playerPos = player.getPos();

    
	 sf::Event event;
	sf::Time time=clock.getElapsedTime();
	
		
        while (window.pollEvent(event))
        {
			//Trap
			if(dt1.getIsLoaded()&&dt1.getIsDeployed()){
				if(player.distanceToInteractable(&dt1)<25){
					dt1.activate(&player);
					//player.hp=player.hp-dt1.getDamagePoint;
//					itemsList.pop_back();
				}
			}
           
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code)
                {
					case sf::Keyboard::Num1:
						dt1.placeTrap(player);
						
						break;
					case sf::Keyboard::E:
						player.react(itemsList);
						break;
					case sf::Keyboard::LShift:
						if(player.getSpeed()==9)
							player.setSpeed(15);
						else
							player.setSpeed(9);
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
              //For Debug
                    case sf::Keyboard::H:
						std::cout<< "HP: " <<player.hp<<std::endl;
						break;
                    case sf::Keyboard::J:
                    	//distance to all the interactable on map
                    	for(int i=0;i<itemsList.size();i++){
                    		int distance=player.distanceToInteractable(itemsList[i]);
                    		std::cout<<itemsList[i]->getType()<<" "<<distance<<std::endl;
                    	}
                    	std::cout<<"\n"<<std::endl;
                    	break;
                    case sf::Keyboard::P:
                    	//check if the interactable is loaded
                    	for(int i=0; i<itemsList.size();i++){
                    		std::cout<<itemsList[i]->getType()<<" "<<itemsList[i]->getIsLoaded()<<std::endl;
                    	}
                    	break;
                 //End for debug

                    default:
                        break;
                }//end switch
                view.setCenter(getCenter(player.getPos(), image.getSize()));
                window.setView(view);
            }//end if (keypressed)
            if(network.getPlayerSelection()=="m"){
            	spriteCounter = updateSprite(player2.getSprite(), window, clock_original, spriteLength, spriteWidth, spriteNum, spriteCounter);
            	mSpriteCounter = updateMarineSprite(player.getSprite(), window, clock_original, mSpriteLength, mSpriteWidth, mSpriteNum, mSpriteCounter);
            }else{
            	spriteCounter = updateSprite(player.getSprite(), window, clock_original, spriteLength, spriteWidth, spriteNum, spriteCounter);
            	mSpriteCounter = updateMarineSprite(player2.getSprite(), window, clock_original, mSpriteLength, mSpriteWidth, mSpriteNum, mSpriteCounter);
            }

            //window.draw(player.getSprite());
            
            updateRotation(player, view, window);
            
        }
        
        maze.updateShade(player.getCoor(), player.getSight());
        
        window.clear();
	if(playerPos != player.getPos()||packetSendClock.getElapsedTime().asMilliseconds()>150){


	//sending data
		network.sendData(player.getPos());
		packetSendClock.restart();
	}
//	else std::cout<<packetSendClock.getElapsedTime().asMilliseconds()<<std::endl;
	sf::Time elapsed1 = clock.getElapsedTime();
    sf::Time elapsed2 = clock2.getElapsedTime();
    sf::Time elapsed3 = clock3.getElapsedTime();
    sf::Time elapsed4 = clock4.getElapsedTime();

    //receiving and setting player2 Data
        sf::Vector2f player2Pos = network.receiveData();
       
	if(player2Pos.x != 0){
        std::cout <<"Receiving Data: " << player2Pos.x <<' '<< player2Pos.y << std::endl;
        if(maze.getDetect(int(player2Pos.x)/80,int(player2Pos.y)/80)==2)
 	        player2.setPos(player2Pos); 
 	    else player2.setPos(sf::Vector2f(2400,2400));
   }
        
        
        // Projectile Collides with Enemy
        counter = 0;
        for (iter2 = projectileArray2.begin(); iter2 != projectileArray2.end(); iter2++)
        {
            counter2 = 0;
            
            if (projectileArray2[counter].rect.getGlobalBounds().intersects(player2.rect.getGlobalBounds()))
            {
                projectileArray2[counter].destroy = true;
                
                player2.hp -= projectileArray2[counter].attackDamage;
                if (player2.hp <= 0)
                {
                    player2.alive = false;
                }
            }
            counter2++;
            counter++;
        }
       


      /*  // Delete Dead Enemy
        counter = 0;
        
        if (player2.alive == false)
        {
            cout << "Player win" << endl;
            return 0;
        }
        
        counter++;
        */
      // Delete Projectile
        counter = 0;
 	
        for (iter2 = projectileArray2.begin(); iter2 != projectileArray2.end(); iter2++)
        {
            if (projectileArray2[counter].destroy == true)
            {
                projectileArray2.erase(projectileArray2.begin() + counter);
                break;
            }
            
            counter++;
        }


       // Fires Missle (left click)
            
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if (elapsed1.asSeconds() >= 0.8)
                {
                    clock.restart();
                projectile2.rect.setPosition(player.getPos().x ,player.getPos().y);

                //projectile2.direction = player.direction;
                projectileArray2.push_back(projectile2);
            }
        }
		
		
		//Draw All In Game Objects
        window.draw(spr);
		for(unsigned int i=0;i<itemsList.size();i++){
			itemsList[i]->draw(window);
		}
		if(player.isIsLoaded())
			window.draw(player.getSprite());
        if(player2.isIsLoaded())
        	window.draw(player2.getSprite());
        
        for(int i=0;i<maze.getSize();i++){
        	for(int j=0;j<maze.getSize();j++)
	        	window.draw(maze.getShade(i,j));
		}
        
        // Draw Projectiles
        counter = 0;
        for (iter2 = projectileArray2.begin(); iter2 != projectileArray2.end(); iter2++)
        {
             window.draw(projectileArray2[counter].rect);
            projectileArray2[counter].update(player,view,window); // Update Projectile
           
            
            counter++;
        }
        player.update();
        player2.update();
        
        window.display();
    }
    
    return 0;
}
