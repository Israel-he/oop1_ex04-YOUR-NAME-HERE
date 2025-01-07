#include "Toolbar.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

Toolbar::Toolbar(sf::Texture& pic, sf::Vector2f loc,enum State type)
	:m_pic(pic), m_position(loc), m_isPressed(false),m_type(type)
{
}

//Toolbar::Toolbar(sf::Texture& texture, sf::Vector2f position)
//	:m_pic(texture), m_position(position), m_isPressed(false)
//{
//}

sf::Sprite Toolbar::returnSprit()
{
    return create();
}


sf::Sprite Toolbar::create()  
{
	auto result = sf::Sprite(m_pic);
	result.setPosition(m_position);
	result.setScale(sf::Vector2f(2.f, 2.0f));
    return result;
	
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





bool Toolbar::handleClick(int x, int y)
{
	std::cout << "fjjjjjj \n";
	if (create().getGlobalBounds().contains(x, y))
	{
		return true;
	}
    return false;
}

void Toolbar::setIsPressed(bool isPressed)
{
	m_isPressed = isPressed;
}

bool Toolbar::getIsPressed()
{
     return m_isPressed; 
}

State Toolbar::getType()
{
	return  m_type;
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