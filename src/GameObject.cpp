#include "GameObject.h"
 
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
 
    
 

 

GameObject::GameObject(sf::Texture& pic, sf::Vector2f pos)
	:m_position(pos), m_texture(pic)
{
}

void GameObject::draw(sf::RenderWindow& window)
{
    window.draw(create());
}

sf::Sprite& GameObject::create()
{

    auto result = sf::Sprite(m_texture);
    result.setPosition(m_position);
    result.setScale(sf::Vector2f(2.f, 2.0f));
    return result;

    
}
 
    
  
 



 


 



// 
// 
//
//
////constractors
//GameObject::GameObject(char symbol)
//	:m_symbol(symbol)
//{
//}
//
//GameObject::~GameObject()
//{
//}
//
//char GameObject::getSymbol() const
//{
//	return  m_symbol;
//}


