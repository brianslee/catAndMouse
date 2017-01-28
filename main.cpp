
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

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Menu.hpp"
#include <iostream>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Catch Me");
    
    Menu m(window.getSize().x, window.getSize().y);
    
    
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
        return EXIT_FAILURE;
    }
    
    // Play the music
    music.play();
    
    m.background();
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "cute_image.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);
    
    

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            switch (event.type) {
                    
              case sf::Event::KeyPressed:
                    
                switch (event.key.code)
                {
                    case sf::Keyboard::Up:
                        m.MoveUp();
                        break;
                    case sf::Keyboard::Down:
                        m.MoveDown();
                        break;
                    }
                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
        
            }
        }

        // Clear screen
        window.clear();

        window.draw(sprite);
        m.draw(window);
    
        

       
        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
