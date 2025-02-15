#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class GameObject {
private:
    
    sf::Vector2f m_position; // ����� �������� ���� (x, y)
	sf::Texture& m_texture;

 
public:
    GameObject(sf::Texture& pic, sf::Vector2f pos);

    GameObject(const GameObject& other); // Copy constructor
    GameObject& operator=(const GameObject& other);
    sf::Texture& getTextur() const { return m_texture; }
	sf::Vector2f getLoc() const { return m_position; }
    void draw(sf::RenderWindow& window );
    sf::Sprite create();

    sf::Vector2f getPosition() const { return m_position; }
   // void setPosition(const sf::Vector2f& pos) { m_position = pos; }
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
//   // virtual void draw(sf::RenderWindow& window, int x, int y)=0 ; // ������� ��������� �����
//    char getSymbol() const;
//
//protected:
//    char m_symbol;
//}; 