

#include "Menu.hpp"
#include "ResourcePath.hpp"
#include <SFML/Audio.hpp>

Menu::Menu(float width, float height)
{
    if (!font.loadFromFile(resourcePath() + "GoodDog.otf")) {
        return EXIT_FAILURE;
    }
    
    menu[0].setFont(font);
    menu[0].setString("1 Player");
    menu[0].setCharacterSize(90);
    menu[0].setFillColor(sf::Color::Cyan);
    menu[0].setPosition(width/2.6, height/4);
    
    menu[1].setFont(font);
    menu[1].setString("2 Player");
    menu[1].setCharacterSize(70);
    menu[1].setFillColor(sf::Color::Yellow);
    menu[1].setPosition(width/2.6, height/4*1.7 );
    
    menu[2].setFont(font);
    menu[2].setString("Setting");
    menu[2].setCharacterSize(70);
    menu[2].setFillColor(sf::Color::Blue);
    menu[2].setPosition(width/2.6, height/4 * 2.4);
    
    menu[3].setFont(font);
    menu[3].setString("Exit");
    menu[3].setCharacterSize(70);
    menu[3].setFillColor(sf::Color::Red);
    menu[3].setPosition(width/2.6, height/4 * 3.1);
    
    
    title.setFont(font);
    title.setString("Catch Me!!!");
    title.setCharacterSize(100);
    title.setFillColor(sf::Color::White);
    title.setPosition(width/3.6, 0.1);
    

    
    
}



Menu::~Menu()
{
    
}

void Menu::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < Number; i++)
    {
        window.draw(menu[i]);
    }
    window.draw(title);
}


void Menu::MoveUp()
{
    if(selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setCharacterSize(70);
        selectedItemIndex--;
        menu[selectedItemIndex].setCharacterSize(90);
    }
}


void Menu::MoveDown()
{
    if(selectedItemIndex + 1 < Number-1)
    {
        menu[selectedItemIndex].setCharacterSize(70);
        selectedItemIndex++;
        menu[selectedItemIndex].setCharacterSize(90);
    }
}

void Menu::background(){
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "cute_image.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);
}















