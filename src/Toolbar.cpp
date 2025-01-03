#include "Toolbar.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


Toolbar::Toolbar(sf::Texture& texture, sf::Vector2f position)
	:m_pic(texture), m_position(position)
{
}

sf::Sprite Toolbar::returnsprit()
{
    return create();
}


sf::Sprite Toolbar::create()  
{
	auto result = sf::Sprite(m_pic);
	result.setPosition(m_position);
	result.setScale(sf::Vector2f(2.f, 2.0f));
    return result;

	//result.setOrigin(sf::Vector2f(result.getTexture()->getSize() / 2u));
	
}







/*
sf::Sprite MyDraw_07::create() const
{
    auto result = sf::Sprite(m_texture);
    result.setPosition(m_position);
    result.setRotation(m_rotated ? 90.f : 0.f);
    result.setOrigin(sf::Vector2f(result.getTexture()->getSize() / 2u));
    return result;
}
*/





int Toolbar::handleClick(int x, int y)
{

    return 0;
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