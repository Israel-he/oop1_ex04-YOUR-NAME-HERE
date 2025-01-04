#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class GameObject {
protected:
    char type; // סוג האובייקט (קיר, רובוט וכו')
    sf::Vector2f position; // מיקום האובייקט בלוח (x, y)

public:
    GameObject(char t, sf::Vector2f pos) : type(t), position(pos) {}
    virtual ~GameObject() = default;

    virtual void draw(sf::RenderWindow& window ) const=0;

    char getType() const { return type; }
    sf::Vector2f getPosition() const { return position; }
    void setPosition(const sf::Vector2f& pos) { position = pos; }
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