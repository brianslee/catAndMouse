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

    int spriteCounter = 0, spriteNum = 4, spriteLength = 215, spriteWidth = 215;


//setup player sprites
void setupPlayer(Human & player, sf::Texture& texture, int x, int y){
    player.getSprite().setTexture(texture);
    player.getSprite().setTextureRect(sf::IntRect(((spriteCounter) % 2)*spriteLength, (spriteCounter / 2)*spriteWidth, ((spriteCounter) % 2 + 1)*spriteLength, (spriteCounter / 2 + 1)*spriteWidth));
    player.getSprite().setScale(60.0 / (double)(spriteLength), 60.0 / (double)(spriteWidth)); 
    player.getSprite().setOrigin(sf::Vector2f(spriteLength/2, spriteWidth/2));
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

	
    


    sf::RenderWindow window(sf::VideoMode(800, 800), "Maze", sf::Style::Titlebar | sf::Style::Close);
    sf::Texture texture,tx2,marineTexture;
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

    if (!tx2.loadFromFile("img/triangle.png")) {
        return EXIT_FAILURE;
    }
    
    if (!marineTexture.loadFromFile("img/alien.png")) {
        return EXIT_FAILURE;
    }
    spr.setTexture(texture);

    spr.move(0, 0);
    std::cout << "Creating Instances...\n";
    Human player = Human(sf::Vector2i(5,5),7,3);
    
    
    Human player2 = Human(sf::Vector2i(5,9),7,3);
    bigMap maze = bigMap(30);

	//Item
	Item item_test=Item("img/circle.png","Damage Trap");
	Item item_test2=Item("img/circle.png","Sword");
	//Chest ch=Chest("It looks safe");
	chest ch=chest("Spritesheets/Crate1.png","Testing");
	chest ch2=chest("It's a chest");
	ch.setItem(&item_test2);
	ch2.setItem(&item_test);
	damageTrap dt1=damageTrap("Spritesheets/landmine.png","Land Mine: 20 Damage",20);

	std::vector<interactable*> itemsList;
	itemsList.push_back(&item_test2);
	itemsList.push_back(&ch2);
	itemsList.push_back(&item_test);
	itemsList.push_back(&dt1);
	itemsList.push_back(&ch);

	for(unsigned i=0;i<3;i++)
		itemsList[i]->getSprite().setScale(0.6,0.6);
	ch.getSprite().setScale(2,2);
	dt1.getSprite().setScale(2,2);
	ch.setPosition(1000,700);
	ch2.setPosition(300,200);
	item_test.setIsLoaded(false);
	item_test2.setIsLoaded(false);
//	dt1.setPosition(0,0);
	dt1.setIsLoaded(false);
	//Item ends
    
   
    std::vector<projectile2>::const_iterator iter2;
    std::vector<projectile2> projectileArray2;
    
    // Projectile Object
    class projectile2 projectile2;
    
    std::cout << "Initializing...\n";
    maze.load(image);
    setupPlayer(player, alienTexture, 280, 440);
    setupPlayer(player2, tx2, 1720, 2140);   
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
			if(time.asSeconds()>=5.0){
				dt1.setIsDeployed(true);
				std::cout<<"Trap depolyed"<<std::endl;
			}

			if(dt1.getIsLoaded()&&dt1.getIsDeployed()){
				if(player.distanceToInteractable(&dt1)<20){
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
						if(player.getSpeed()==8)
							player.setSpeed(15);
						else
							player.setSpeed(8);
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
                    default:
						std::cout<< "HP: " <<player.hp<<std::endl;
                       // std::cout << player.getCoor().x << ' ' << player.getCoor().y << ' ' << player.getPos().x << ' ' << player.getPos().y << std::endl;
                      //  std::cout << int(player.getPos().x) % 80 << ' ' << int(player.getPos().y) % 80 << std::endl;
                     //   std::cout << maze.getWall(player.getCoor().x, player.getCoor().y) << std::endl;
                        break;
                }//end switch
                view.setCenter(getCenter(player.getPos(), image.getSize()));
                window.setView(view);
            }//end if (keypressed)
            //spriteCounter = updateSprite(player.getSprite(), window, clock_original, spriteLength, spriteWidth, spriteNum, spriteCounter);
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
//                projectileArray2.erase(projectileArray2[counter]);
                break;
            }
            
            counter++;
        }


        // Fires Missle (Space bar)
        if (elapsed1.asSeconds() >= 0.5)
        {
            clock.restart();
            
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                projectile2.rect.setPosition(player.getPos().x ,player.getPos().y);

                projectile2.direction = player.direction;
                projectileArray2.push_back(projectile2);
            }
        }
		
		//Draw All In Game Objects
        window.draw(spr);
		for(unsigned int i=0;i<itemsList.size();i++){
			itemsList[i]->draw(window);
		}
        window.draw(player.getSprite());
        window.draw(player2.getSprite());
        
        for(int i=0;i<maze.getSize();i++){
        	for(int j=0;j<maze.getSize();j++)
	        	window.draw(maze.getShade(i,j));
		}
        
        // Draw Projectiles
        counter = 0;
        for (iter2 = projectileArray2.begin(); iter2 != projectileArray2.end(); iter2++)
        {
            projectileArray2[counter].update(player,view,window); // Update Projectile
            window.draw(projectileArray2[counter].rect);
            
            counter++;
        }
        player.update();
        player2.update();
        
        window.display();
    }
    
    return 0;
}
