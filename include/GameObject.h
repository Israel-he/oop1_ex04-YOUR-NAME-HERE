#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class GameObject {
protected:
    char type; // סוג האובייקט (קיר, רובוט וכו')
    sf::Vector2f m_position; // מיקום האובייקט בלוח (x, y)
	sf::Texture& m_texture;


public:
    GameObject(sf::Texture& pic, sf::Vector2f pos);
    

    virtual void draw(sf::RenderWindow& window );
    sf::Sprite& create();
	 
    char getType() const { return type; }
    sf::Vector2f getPosition() const { return m_position; }
    void setPosition(const sf::Vector2f& pos) { m_position = pos; }
};















































//
//class GameObject
//{
//public:
//
//
//     GameObject(char symbol, const sf::Texture& texture);
//
//     virtual void draw(sf::RenderWindow& window, int x, int y);
//     char getSymbol() const;
//	 void setPosition(int x, int y);
//
//private:
//    char symbol;
//    sf::Sprint sprint;
//};

//class GameObject {
//public:
//    GameObject(char symbol);
//    virtual ~GameObject();
//
//   // virtual void draw(sf::RenderWindow& window, int x, int y)=0 ; // פונקציה וירטואלית טהורה
//    char getSymbol() const;
//
//protected:
//    char m_symbol;
//}; 