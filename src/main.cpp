
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
#include "helper.hpp"
//#include "ResourcePath.hpp"
#include <SFML/Audio.hpp>
#include "network.hpp"
#include "attack.hpp"
#include "entity.hpp"
#include "alienattack.hpp"

#include <vector>

    int spriteCounter = 0, spriteNum = 4, spriteLength = 215, spriteWidth = 215;


//setup player sprites
void setupPlayer(Human & player, sf::Texture& texture){
    player.getSprite().setTexture(texture);
    player.getSprite().setTextureRect(sf::IntRect(((spriteCounter) % 2)*spriteLength, (spriteCounter / 2)*spriteWidth, ((spriteCounter) % 2 + 1)*spriteLength, (spriteCounter / 2 + 1)*spriteWidth));
    player.getSprite().setScale(60.0 / (double)(spriteLength), 60.0 / (double)(spriteWidth)); 
    player.getSprite().setOrigin(sf::Vector2f(spriteLength/2, spriteWidth/2));
    player.getSprite().move(40, 40);

}


int main()
{
    
    sf::Clock clock;
    sf::Clock clock2;
    sf::Clock clock3;
    sf::Clock clock4;
    float playerMovementSpeed = 8;
    
    int counterWalking = 0;
    int counter = 0;
    int counter2 = 0;
    int counter3 = 0;
    int counter4 = 0;
    int counter5 = 0;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Maze", sf::Style::Titlebar | sf::Style::Close);
    sf::Texture texture,tx2,marineTexture;
    sf::Image image;
    sf::Sprite spr, spr2;
    sf::View view(sf::FloatRect(0, 0, 800, 800));
    window.setView(view);
    
    Network network;  
    network.setup();

    std::cout << "Loading texture...\n";
    
    if (!image.loadFromFile("img/maze.png")) {
        return EXIT_FAILURE;
    }
    texture.loadFromImage(image);
    
    
    if (!tx2.loadFromFile("img/triangle.png")) {
        return EXIT_FAILURE;
    }
    
    if (!marineTexture.loadFromFile("img/alien.png")) {
        return EXIT_FAILURE;
    }
    spr.setTexture(texture);

    spr.move(0, 0);
    std::cout << "Creating Instances...\n";
    Human player = Human(sf::Vector2i(0,0),7,3);
    
    
    Human player2 = Human(sf::Vector2i(0,0),7,3);
    bigMap maze = bigMap();
    
   
    std::vector<projectile2>::const_iterator iter2;
    std::vector<projectile2> projectileArray2;
    
    // Projectile Object
    class projectile2 projectile2;
    
    
   
    std::cout << "Initializing...\n";
    maze.load(image);
    player.updateCoor();
    player2.updateCoor();
    setupPlayer(player, marineTexture);
    setupPlayer(player2, tx2);    
    
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
        while (window.pollEvent(event))
        {
           
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code)
                {
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
                       // std::cout << player.getCoor().x << ' ' << player.getCoor().y << ' ' << player.getPos().x << ' ' << player.getPos().y << std::endl;
                      //  std::cout << int(player.getPos().x) % 80 << ' ' << int(player.getPos().y) % 80 << std::endl;
                     //   std::cout << maze.getWall(player.getCoor().x, player.getCoor().y) << std::endl;
                        break;
                }
                view.setCenter(getCenter(player.getPos(), image.getSize()));
                window.setView(view);
            }
            spriteCounter = updateSprite(player.getSprite(), window, clock_original, spriteLength, spriteWidth, spriteNum, spriteCounter);
            //window.draw(player.getSprite());
            
            updateRotation(player, view, window);
            
        }
        
        //		maze.updateShade(player.getCoor(), player.getSight());
        
        window.clear();

	if(playerPos != player.getPos()){



	//sending data
	network.sendData(player.getPos());
	
	}




        sf::Time elapsed1 = clock.getElapsedTime();
        sf::Time elapsed2 = clock2.getElapsedTime();
        sf::Time elapsed3 = clock3.getElapsedTime();
        sf::Time elapsed4 = clock4.getElapsedTime();




    //receiving and setting player2 Data
        sf::Vector2f player2Pos = network.receiveData();
       
	if(player2Pos.x != 0)
{

 std::cout <<"Receiving Data: " << player2Pos.x << player2Pos.y << std::endl;
 player2.setPos(player2Pos); 
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
        if (elapsed1.asSeconds() >= 0.1)
        {
            clock.restart();
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                projectile2.rect.setPosition(player.getPos().x + player.rect.getSize().x/2 - projectile2.rect.getSize().x/2,player.getPos().y + player.rect.getSize().y/2 - projectile2.rect.getSize().y/2);
                
                
                projectile2.direction = player.direction;
                updateRotation2(projectile2, view, window);
    
                
                
                projectileArray2.push_back(projectile2);
            }
            
            
        }

        
        
	
        window.draw(spr);
       
        
        
        window.draw(player.getSprite());
        window.draw(player2.getSprite());
        
        
        // Draw Projectiles
        counter = 0;
        for (iter2 = projectileArray2.begin(); iter2 != projectileArray2.end(); iter2++)
        {
            projectileArray2[counter].update(); // Update Projectile
            window.draw(projectileArray2[counter].rect);
            
            counter++;
        }
        player.update();
        player2.update();
        
        window.display();
    }
    
    return 0;
}
