#include "Toolbar.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

Toolbar::Toolbar(sf::Texture pic)
    :m_pic(pic)
{
}

int Toolbar::handleClick(int x, int y)
{

    return 0;
}



void Toolbar::putinloc(sf::Vector2f& loc)
{
    m_sprite.setTexture(m_pic);
    m_sprite.setPosition(loc);
}

sf::Sprite& Toolbar::returnsprit()
{
    return m_sprite;
}


//Toolbar Toolbar::create(sf::Vector2f& place, sf::Texture& pic)
//{
//    m_sprit.setTexture(pic);
//    m_sprit.setPosition(place);
//    return Toolbar();
//}

//
//void  Toolbar::initEnemy()
//{
//     enemy.setPosition(m_position);
//     enemy.setSize(sf::Vector2f(100.f, 100.f));
//     enemy.setFillColor(sf::Color::Cyan);
//     enemy.setOutlineColor(sf::Color::Blue);
//     enemy.setOutlineThickness(5.f);
//
//    //שינוי הגודל של (enemy)
//    //enemy.setScale(sf::Vector2f(0.5f, 0.5f));
//    //enemy.setPosition(sf::Mouse::getPosition(*this->window).x, sf::Mouse::getPosition(*this->window).y);
//
//}