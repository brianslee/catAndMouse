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
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <vector>
#include "alienattack.h"
#include "attack.h"
#include "entity.h"
#include "helper.h"
#include "network.h"
#include "Audio.h"
#include "Timer.h"
#include "InteractableManager.h"
#include "Marine.h"
#include "Alien.h"



	int projectilesMovementSpeed=30;
	
	// Should not be at here
	// Should be in some seperate class
	//REFACTOR - PLACED INTO ALIEN AND MARINE CLASSES
	/*
    int aSpriteCounter = 0, aSpriteNum = 4, aSpriteLength = 215, aSpriteWidth = 215;
    int mSpriteCounter = 0, mSpriteNum = 9, mSpriteLength = 216, mSpriteWidth = 216;
    */

//END REFACTOR

//setup player sprites
//REFACTOR - PLACED INTO CHARACTER CLASS
    /*
void setupPlayer(Character & player, sf::Texture& texture, int x, int y, int spriteLength, int spriteWidth)
{
    player.getSprite().setTexture(texture);
    player.getSprite().setTextureRect(sf::IntRect(0, 0, spriteLength, spriteWidth));
    player.getSprite().setScale(78.0 / (double)(spriteLength), 78.0 / (double)(spriteWidth));
    player.getSprite().setOrigin(sf::Vector2f(spriteLength/2, spriteWidth/2));
 	player.rect.move(x,y);
    player.getSprite().move(x,y);
}
*/
//END REFACTOR
int main()
{
    Timer mainGameTimer;
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
	sf::Vector2f spPos, sbPos,rectPos;
	int spRot, sbDir;

	//Data to receive
	//Player: rpPos, rpRot
	//Projectile: rbPos, rbRot, rbDir
	float rbRot;
	sf::Vector2f rpPos, rbPos;
	int rpRot, rbDir;
	short interactableTypeChanged;//0=nothing,1=interactable,2=chest,3=trap,4=hidingPlace

	//Save previous movement
	sf::Vector2f oldMove;

	//Starts up network, prompts user for IP address and player choice.
    Network network;
    network.setup();

    sf::RenderWindow window(sf::VideoMode(800, 800), "Cat And Mouse", sf::Style::Titlebar | sf::Style::Close);
    sf::Texture texture,tx2,hpBarTexture;
    //REFACTOR - REMOVE BELOW
    /*
    sf::Texture marineTexture,alienTexture;
    */

    sf::Image image;
    sf::Sprite spr, spr2;
    sf::View view(sf::FloatRect(0, 0, 800, 800));
    window.setView(view);
    window.setFramerateLimit(60);



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
    
    //REFACTOR - REMOVE THESE TWO, MADE WHEN MARINE AND ALIENS ARE MADE
    /*
    if (!alienTexture.loadFromFile("Spritesheets/Alien_1_Movement2-1.png")) {
        return EXIT_FAILURE;
    }
    if (!marineTexture.loadFromFile("Spritesheets/Space_Marine1-2.png")) {
        return EXIT_FAILURE;
    }
    */
    //END REFACTOR
    if (!hpBarTexture.loadFromFile("Spritesheets/Health_Bar.png")) {
        return EXIT_FAILURE;
    }
    spr.setTexture(texture);

    spr.move(0, 0);
    //REFACTOR CODE - REMOVE INSTANCES BELOW
    /*
    std::cout << "Creating Instances...\n";
    Character player = Character(sf::Vector2i(5,5),playerMovementSpeed,3);
    Character player2 = Character(sf::Vector2i(5,9),playerMovementSpeed,3);
    */
    //END REFACTOR

    bigMap maze = bigMap(30);

	//Interactable
    bool shouldSend=false;
    bool shouldSend2=false;
//    short shouldSendOrReceive=0;//0=nothing,1=send,2=receive
    InteractableManager * manager=new InteractableManager();

	Item * rifle=new Item("Spritesheets/rifle1.png","Rifle",2.f); manager->add(rifle);

	damageTrap * dt1=new damageTrap(20); manager->add(dt1);
	damageTrap * dt2=new damageTrap(20); manager->add(dt2);
	stickyTrap * st1=new stickyTrap(3); manager->add(st1);

	chest * ch=new chest(rifle); manager->add(ch); 	ch->setPosition(1000,1000);
	chest * ch2=new chest(dt2); manager->add(ch2); 	ch2->setPosition(300,200);
	chest * ch3=new chest(st1); manager->add(ch3); 	ch3->setPosition(400,2000);

	locker * lo1=new locker(1); manager->add(lo1); 	lo1->setPosition(320,1050);
	Table * ta1=new Table(2); manager->add(ta1); 	ta1->setPosition(1485,590);

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
    	//REFACTOR CODE - DELETE CODE BELOW, REPLACE WITH INSTANTIATION
    	/*
		setupPlayer(player, marineTexture, 280, 440, mSpriteLength, mSpriteWidth);
		setupPlayer(player2, alienTexture, 1720, 2140, aSpriteLength, aSpriteWidth);
*/
		Marine player(sf::Vector2i(5,5),playerMovementSpeed,3);
    	Alien player2(sf::Vector2i(5,9),playerMovementSpeed,3);
    	//END REFACTOR CODE

		audio.playMarineIntro();

    }else{
    	//REFACTOR CODE - DELETE CODE BELOW, REPLACE WITH INSTANTIATION
    	/*
    	setupPlayer(player, alienTexture, 1720, 2140, aSpriteLength, aSpriteWidth);
    	setupPlayer(player2, marineTexture, 280, 440, mSpriteLength, mSpriteWidth);
*/
    	Alien player(sf::Vector2i(5,5),playerMovementSpeed,3);
    	Marine player2(sf::Vector2i(5,9),playerMovementSpeed,3);
    	//END REFACTOR CODE
   
	audio.playAlienIntro();
 }
    player.updateCoor();
    player2.updateCoor(); 
    
    player.setHPBar(HealthBar(hpBarTexture,100,200,200,40));
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

        while (window.pollEvent(event))
        {

			if(oldMove != player.getPos())
			{
				if(network.isMarine())
					audio.playMarineWalk();
				else
					audio.playAlienWalk();
			}
			oldMove = player.getPos();

			//Trap
			shouldSend2=manager->trapsDetection(&player,mainGameTimer.getTimeAsSeconds());
			//end Trap
           
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
            	std::string reactedType;
                switch (event.key.code)
                {

					case sf::Keyboard::E:
						reactedType=player.react(manager->getIAList());
						shouldSend=true;
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
					case sf::Keyboard::Num1:
						dt1->placeTrap(&player,view,window);
						shouldSend=true;
						//send over the network that the trap is placed
						break;
					case sf::Keyboard::Num2:
						st1->placeTrap(&player,view,window);
						shouldSend=true;
						break;
					case sf::Keyboard::LShift:
						if(player.getSpeed()==player.getOriginalSpeed())
							player.setSpeed(15);
						else
							player.setSpeedToOriginal();
						break;
                    case sf::Keyboard::H:
						std::cout<< "HP: " <<player.getHP()<<std::endl;
						std::cout<<"Time:" <<mainGameTimer.getTimeAsSeconds()<<std::endl;
						std::cout<<"Angle:"<<player.getAngle(view,window)<<std::endl;

						break;
                    case sf::Keyboard::J:
                    	//distance to all the interactable on map
                    	for(int i=0;i<manager->getIAList().size();i++){
                    		int distance=player.distanceToInteractable(manager->getIAList()[i]);
                    		std::cout<<manager->getIAList()[i]->getType()<<" "<<distance<<std::endl;
                    	}
                    	std::cout<<"\n"<<std::endl;
                    	break;
                    case sf::Keyboard::O:
                    	player.setPos(sf::Vector2f(1700,2100)); //teleport to alien location
                    	break;
                    case sf::Keyboard::P:
                    	player.setPos(sf::Vector2f(250,400)); //teleport to marine location
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
            	player2.getSpriteCounter() = player2.updateSprite(window, alienClock, player2.getSpriteLength(), player2.getSpriteWidth(), player2.getSpriteNum(), player2.getSpriteCounter());
            	player.getSpriteCounter() = player.updateSprite(window, marineClock, player.getSpriteLength(), player.getSpriteWidth(), player.getSpriteNum(), player.getSpriteCounter());
            }
			else{
            	player.getSpriteCounter() = player.updateSprite(window, alienClock, player.getSpriteLength(), player.getSpriteWidth(), player.getSpriteNum(), player.getSpriteCounter());
            	player2.getSpriteCounter() = player2.updateSprite(window, marineClock, player2.getSpriteLength(), player2.getSpriteWidth(), player2.getSpriteNum(), player2.getSpriteCounter());
            }



			updateRotation(player, view, window);

            
			window.draw(player.getHPBar()->getSprite());
        }//end while event

		manager->startAnimation();

        maze.updateShade(player.getCoor(), player.getSight());
        
        window.clear();


	//getting player position and rotation

		float playerDirection = player.getSprite().getRotation();		
		spPos = player.getPos();
		rectPos = player.rect.getPosition();
		spRot = playerDirection;


		sf::Time elapsed1 = clock.getElapsedTime();
		sf::Time elapsed2 = clock2.getElapsedTime();
		sf::Time elapsed3 = clock3.getElapsedTime();
		sf::Time elapsed4 = clock4.getElapsedTime();

 //receiving and setting player2 Data
		//sf::Vector2f player2Pos = network.receiveData();

		sf::Vector2f player2Pos;
		int player2Dir;

		shouldSend=shouldSend||shouldSend2;
		if(packetSendClock.getElapsedTime().asMilliseconds()>20){
			network.sendAllData(spPos, rectPos, spRot, sbPos, sbDir, sbRot,manager,shouldSend);
			shouldSend=false;
			packetSendClock.restart();
		}

	//reset attack positions after send
		sbPos = sf::Vector2f(0,0);
        sbDir = 0;
        sbRot = 0.0;

        network.receiveAllData(rpPos,rectPos, rpRot, rbPos, rbDir, rbRot,manager);

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

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&&player.isCanAttack())
		{
			if (elapsed1.asSeconds() >= 0.5)
			{
                clock.restart();
              //  if(network.isMarine()){
                //only do projectile attack if is Marine
			  myBullet.rect.setPosition(player.getPos().x,player.getPos().y);
			  myBullet.direction = player.direction;
			  bulletAngle = myBullet.getPlayerAngle(&player,view,window);
			  myBullets.push_back(myBullet);

			}
      // store bullet values to be sent
			  sbPos = myBullet.rect.getPosition();
			  sbDir = myBullet.direction;
			  sbRot = bulletAngle;

				if(network.isMarine())
					audio.playMarineAttack();
				else
					audio.playAlienAttack();
		}//end if button is pressed

//To delete mybullets if it destroyed

        counter = 0;
        for (iter = myBullets.begin(); iter != myBullets.end(); iter++)
        {
            if (myBullets[counter].destroy == true)
            {
                myBullets.erase(myBullets.begin() + counter);
                break;
            }
            
            counter++;
        }


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
        	if (elapsed2.asSeconds() >= 0.8)
        	{
                clock2.restart();
                enemyBullet.rect.setPosition(attackPos.x, attackPos.y);
                enemyBullet.direction = direction;
                enemyBullets.push_back(enemyBullet);
                bulletAngles.push_back(angle);
        	}
        }

//To delete mybullets if it destroyed

        counter = 0;
        for (iter2 = enemyBullets.begin(); iter2 != enemyBullets.end(); iter2++)
        {
            if (enemyBullets[counter].destroy == true)
            {
                enemyBullets.erase(myBullets.begin() + counter);
                break;
            }
            
            counter++;
        }


       
  // Delete Dead Enemy
        counter = 0;
        
        if (player.alive == false)
        {
            std::cout << "You Lose" << std::endl;
            return 0;
        }
        
        counter++;
        

        counter = 0;
        
        if (player2.alive == false)
        {
            std::cout << "You win" <<std::endl;
            return 0;
        }
        
        counter2++;

		
		//Draw All In Game Objects
		window.draw(spr);
		manager->drawAll(window);
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
			myBullets[counter].updateProjectile2(); // Update Projectile

			   window.draw(myBullets[counter].rect);

		//check if bullet hit enemy

			if (myBullets[counter].rect.getGlobalBounds().intersects(player2.rect.getGlobalBounds()))
			 {
				myBullets[counter].destroy = true;
				std::cout <<"Player hit" << std::endl;
				player2.setHP(player2.getHP()-myBullets[counter].attackDamage);

				if (player2.getHP()<= 0)
					player2.alive = false;

			}
			window.draw(myBullets[counter].rect);
			counter++;
		}

	//Draw enemy projectiles
		counter3 = 0;

		for (iter2 = enemyBullets.begin(); iter2 != enemyBullets.end(); iter2++)
		{
			float angle = bulletAngles[counter3];
			enemyBullets[counter3].rect.move(cos((3.14159/180)*angle)* projectilesMovementSpeed, sin((3.14159/180)*angle)*projectilesMovementSpeed);

			window.draw(enemyBullets[counter3].rect);

			if (enemyBullets[counter3].rect.getGlobalBounds().intersects(player.rect.getGlobalBounds()))
			{
				enemyBullets[counter3].destroy = true;
				std::cout <<"enemy hit" << std::endl;
				player.setHP(player.getHP()-enemyBullets[counter3].attackDamage);

				if (player.getHP() <= 0)
					player.alive = false;
			}
			window.draw(enemyBullets[counter3].rect);
			counter3++;
		}

        player.update();
        player2.update();
        window.display();
    }// End while(window.isOpen)
    
    return 0;
}
