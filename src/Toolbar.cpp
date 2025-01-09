#include "Toolbar.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

 

Toolbar::Toolbar(sf::Texture& pic)
     :m_pic(pic)
{  
	 
} 

Toolbar::Toolbar(sf::Texture& pic, sf::Vector2f loc )
	:m_pic(pic), m_position(loc) 
{
	 
}


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

bool Toolbar::handleClick(int x, int y)
{
	if (create().getGlobalBounds().contains(x, y))
	{
		return true;
	}
    return false;
}

sf::Vector2f Toolbar::getLoc()
{
	return m_position;
}

void Toolbar::deleteTexture()
{
	m_pic = sf::Texture();
}
 
///////////////////////////////
 

 

