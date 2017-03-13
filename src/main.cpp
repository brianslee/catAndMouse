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
/*
Data to be sent:
angle, player position, projectile position, item position

*/


#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "alienattack.h"
#include "attack.h"
#include "chest.h"
#include "damageTrap.h"
#include "entity.h"
#include "helper.h"
#include "network.h"
#include "locker.h"
#include "Table.h"
#include "Audio.h"


	int projectilesMovementSpeed=10;
	
	// Should not be at here
	// Should be in some seperate class
    int aSpriteCounter = 0, aSpriteNum = 4, aSpriteLength = 215, aSpriteWidth = 215;
    int mSpriteCounter = 0, mSpriteNum = 9, mSpriteLength = 216, mSpriteWidth = 216;


//setup player sprites

void setupPlayer(Human & player, sf::Texture& texture, int x, int y, int spriteLength, int spriteWidth)
{
    player.getSprite().setTexture(texture);
    player.getSprite().setTextureRect(sf::IntRect(0, 0, spriteLength, spriteWidth));
    player.getSprite().setScale(78.0 / (double)(spriteLength), 78.0 / (double)(spriteWidth));
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
	
	// clock for marine and alien animation; 
	// replace clock_original
	sf::Clock alienClock,marineClock;
	
    float playerMovementSpeed = 8;
    
    int counterWalking = 0;
    int counter = 0;
    int counter2 = 0;
    int counter3 = 0;
    int counter4 = 0;
    int counter5 = 0;
	// Data to be sent
	float projectileAngle;
	sf::Vector2f playerPosition, projectilePosition;
	int projectileDirection;


// Data to send; s = sent, b = bullet, p = player
float sbRot;
sf::Vector2f spPos, sbPos;
int spRot, sbDir;	

//Data to receive
//Player: rpPos, rpRot
//Projectile: rbPos, rbRot, rbDir
float rbRot;
sf::Vector2f rpPos, rbPos;
int rpRot, rbDir;   

//Save previous movement
sf::Vector2f oldMove;


    sf::RenderWindow window(sf::VideoMode(800, 800), "Cat And Mouse", sf::Style::Titlebar | sf::Style::Close);
    sf::Texture texture,tx2,marineTexture,alienTexture,hpBarTexture;

    sf::Image image;
    sf::Sprite spr, spr2;
    sf::View view(sf::FloatRect(0, 0, 800, 800));
    window.setView(view);
    

	//Starts up network, prompts user for IP address and player choice.
    Network network;  
    network.setup();

	//Start up audio, play background music.
    Audio audio;
    audio.playBackground();

    std::cout << "Loading texture...\n";
    
    if (!image.loadFromFile("img/firstmap.png")) {
        return EXIT_FAILURE;
    }

    if (!texture.loadFromFile("img/mapspr.png")){
    	return EXIT_FAILURE;
	}
    
    if (!alienTexture.loadFromFile("Spritesheets/Alien_1_Movement2-1.png")) {
        return EXIT_FAILURE;
    }
    if (!marineTexture.loadFromFile("Spritesheets/Space_Marine1-2.png")) {
        return EXIT_FAILURE;
    }
    if (!hpBarTexture.loadFromFile("Spritesheets/Health_Bar.png")) {
        return EXIT_FAILURE;
    }
    spr.setTexture(texture);

    spr.move(0, 0);
    std::cout << "Creating Instances...\n";
    Human player = Human(sf::Vector2i(5,5),playerMovementSpeed,3);
    Human player2 = Human(sf::Vector2i(5,9),playerMovementSpeed,3);

    bigMap maze = bigMap(30);

	//Interactable
	Item item_test=Item("img/circle.png","Testing");
	Item rifle=Item("Spritesheets/rifle1.png","Rifle",2.f);
	chest ch=chest(&rifle);
	chest ch2=chest();
	chest ch3=chest(&item_test);

	damageTrap dt1=damageTrap(20);
	damageTrap dt2=damageTrap(20);
	ch2.setItem(&dt2);

	locker lo1=locker(1);
	Table ta1=Table(2);

	std::vector<interactable*> itemsList;

	itemsList.push_back(&lo1);
	itemsList.push_back(&ta1);
	itemsList.push_back(&ch);
	itemsList.push_back(&ch2);
	itemsList.push_back(&ch3);
	itemsList.push_back(&item_test);
	itemsList.push_back(&rifle);

	itemsList.push_back(&dt1);
	itemsList.push_back(&dt2);

	lo1.setPosition(320,1050);
	ta1.setPosition(1485,590);
//	ta1.setPosition(1717,1985);
	ch.setPosition(1000,1000);
	ch2.setPosition(300,200);
	ch3.setPosition(400,2000);
	//Item ends
    
   
    std::vector<projectile2>::const_iterator iter, iter2;
    std::vector<projectile2> myBullets, enemyBullets;
    std::vector<float>bulletAngles;
    // Projectile Object
    class projectile2 myBullet, enemyBullet;
    float bulletAngle;

    std::cout << "Initializing...\n";
    maze.load(image);
    if(network.isMarine()){
		setupPlayer(player, marineTexture, 280, 440, mSpriteLength, mSpriteWidth);
		setupPlayer(player2, alienTexture, 1720, 2140, aSpriteLength, aSpriteWidth);

		audio.playMarineIntro();

    }else{
    	setupPlayer(player, alienTexture, 1720, 2140, aSpriteLength, aSpriteWidth);
    	setupPlayer(player2, marineTexture, 280, 440, mSpriteLength, mSpriteWidth);
   
	audio.playAlienIntro();
 }
    player.updateCoor();
    player2.updateCoor(); 
    
    player.setHP(HealthBar(hpBarTexture,100,200,200,40));
    player.getHPBar()->setPos(getCenter(player.getPos(), image.getSize()).x+200,getCenter(player.getPos(), image.getSize()).y+200);
    	
	// Fix the viewpoint bug
	view.setCenter(getCenter(player.getPos(), image.getSize()));
    window.setView(view);
    
    sf::Vector2f oldMovement = player.getPos();

    while (window.isOpen())
    {
        //		std::cout << "Drawing...\n";

	//sf::Vector2f playerPos = player.getPos();
	sf::Event event;
	sf::Time time=clock.getElapsedTime();
	
		
        while (window.pollEvent(event))
        {
			//Trap
			if(dt1.getIsLoaded()&&dt1.getIsDeployed()){
				if(player.distanceToInteractable(&dt1)<25){
					dt1.activate(&player);
				}
			}
           
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code)
                {
					case sf::Keyboard::Num1:
						dt1.placeTrap(player);
						//send over the network that the trap is placed	
							
	
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
						std::cout<< "HP: " <<player.getHP()<<std::endl;
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
				player.getHPBar()->setPos(getCenter(player.getPos(), image.getSize()).x+200,getCenter(player.getPos(), image.getSize()).y+200);

  				view.setCenter(getCenter(player.getPos(), image.getSize()));
                window.setView(view);
            }//end if (keypressed)
            if(network.isMarine()){
            	aSpriteCounter = updateSprite(player2.getSprite(), window, alienClock, aSpriteLength, aSpriteWidth, aSpriteNum, aSpriteCounter);
            	mSpriteCounter = updateSprite(player.getSprite(), window, marineClock, mSpriteLength, mSpriteWidth, mSpriteNum, mSpriteCounter);
            }
			else{
            	aSpriteCounter = updateSprite(player.getSprite(), window, alienClock, aSpriteLength, aSpriteWidth, aSpriteNum, aSpriteCounter);
            	mSpriteCounter = updateSprite(player2.getSprite(), window, marineClock, mSpriteLength, mSpriteWidth, mSpriteNum, mSpriteCounter);
            }

            updateRotation(player, view, window);
            
			window.draw(player.getHPBar()->getSprite());
        }
        
        maze.updateShade(player.getCoor(), player.getSight());
        
        window.clear();




if(oldMove != player.getPos())
{
	if(network.isMarine())
		audio.playMarineWalk();
	else
		audio.playAlienWalk();	

}
oldMove = player.getPos();
	



	//getting player position and rotation

		float playerDirection = player.getSprite().getRotation();		
		spPos = player.getPos();
		spRot = playerDirection;


    sf::Time elapsed1 = clock.getElapsedTime();

	//if(playerPos != player.getPos()||packetSendClock.getElapsedTime().asMilliseconds()>150){

/*
	//sending data
		float sendRotation = player.getSprite().getRotation();
		network.sendData(player.getPos(), sendRotation);
		packetSendClock.restart();
  */
	//}
//	else std::cout<<packetSendClock.getElapsedTime().asMilliseconds()<<std::endl;

    sf::Time elapsed2 = clock2.getElapsedTime();
    sf::Time elapsed3 = clock3.getElapsedTime();
    sf::Time elapsed4 = clock4.getElapsedTime();

 //receiving and setting player2 Data
		//sf::Vector2f player2Pos = network.receiveData();

	sf::Vector2f player2Pos;
	int player2Dir;
	
if(packetSendClock.getElapsedTime().asMilliseconds()>200){


	network.sendAllData(spPos, spRot, sbPos, sbDir, sbRot);
	packetSendClock.restart();
}

	//reset attack positions after send
	sbPos = sf::Vector2f(0,0);
        sbDir = 0;
        sbRot = 0.0;



      network.receiveAllData(rpPos, rpRot, rbPos, rbDir, rbRot);

	//set new received positions
      player2Pos = rpPos;
      player2Dir = rpRot;


	player2.getSprite().setRotation(player2Dir);
	if(player2Pos.x != 0){ 
		if(player2Pos.x != oldMovement.x || player2Pos.y != oldMovement.y){
			if(maze.getDetect(int(player2Pos.x)/80,int(player2Pos.y)/80)==2)
				player2.setPos(player2Pos);
			else
				player2.setPos(sf::Vector2f(2400,2400));
	  }
		oldMovement = player2Pos;
	}

   if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
   {
              //  if(network.isMarine()){
                //only do projectile attack if is Marine
		  myBullet.rect.setPosition(player.getPos().x,player.getPos().y);
      myBullet.direction = player.direction;
      myBullets.push_back(myBullet);
		  bulletAngle = myBullet.getAngle(player,view,window);
      // store bullet values to be sent
      sbPos = myBullet.rect.getPosition();
      sbDir = myBullet.direction;
      sbRot = bulletAngle;


	if(network.isMarine())
		audio.playMarineAttack();
	else
		audio.playAlienAttack();



    }



	/* from master
                projectile2.direction = player.direction;
                projectileArray2.push_back(projectile2);
				angle = projectile2.getAngle(player,view,window);
				network.sendAttack(player.getPos(), projectile2.direction, angle);
				}
			}
       }

        if(player2Pos.x != 0){
			if(player2Pos.x != oldMovement.x || player2Pos.y != oldMovement.y){

       // std::cout <<"Receiving Data: " << playerPosition.x <<' '<< playerPosition.y << std::endl;
				if(maze.getDetect(int(player2Pos.x)/80,int(player2Pos.y)/80)==2)
					player2.setPos(player2Pos);
				else
					player2.setPos(sf::Vector2f(2400,2400));
			}
			oldMovement = player2Pos;
		}
*/

//Receive attacking info

       // if(!network.isMarine())
        //{

   sf::Vector2f attackPos = sf::Vector2f(0,0);
	 int direction;
	 float angle;
        

		//values for the bullets
	attackPos = rbPos;
	direction = rbDir;
	angle = rbRot;

	if(attackPos.x != 0){
		enemyBullet.rect.setPosition(attackPos.x, attackPos.y);
		enemyBullet.direction = direction;	
		enemyBullets.push_back(enemyBullet);
		bulletAngles.push_back(angle);
	}
       


        //}
/*
        // Bullet hit Enemy
        counter = 0;
        for (iter = projectileArray2.begin(); iter != projectileArray.end(); iter++)
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
       
*/

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

/*

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

*/

		
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
	    window.draw(player.getHPBar()->getSprite());

 
  //Draw my projectiles
 	int counter = 0;
 	for (iter = myBullets.begin(); iter != myBullets.end(); iter++)
  {
		myBullets[counter].update(player,view,window); // Update Projectile     

    //       window.draw(myBullets[counter].rect);

	//check if bullet hit enemy

		if (myBullets[counter].rect.getGlobalBounds().intersects(player2.rect.getGlobalBounds()))
 		 {
			myBullets[counter].destroy = true;
			std::cout <<"Player hit" << std::endl; 
         //       player2.hp -= projectileArray2[counter].attackDamage;
           /*    
	    if (player2.hp <= 0)
                {
                    player2.alive = false;
                }  
	  */
		}
		window.draw(myBullets[counter].rect);
		counter++;
	} 

	//Draw enemy projectiles
	counter = 0;	
	for (iter2 = enemyBullets.begin(); iter2 != enemyBullets.end(); iter2++)	
	{
		float angle = bulletAngles[counter];
		enemyBullets[counter].rect.move(cos((3.14159/180)*angle)* projectilesMovementSpeed, sin((3.14159/180)*angle)*projectilesMovementSpeed);
		window.draw(enemyBullets[counter].rect);
		counter++;
	}
        player.update();
        player2.update();
        window.display();
    }
    
    return 0;
}
