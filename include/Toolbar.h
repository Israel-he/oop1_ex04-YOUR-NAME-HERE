#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Toolbar
{
public:

	 
	Toolbar(sf::Texture& pic,sf::Vector2f loc);
	void putinloc(sf::Vector2f&);
	sf::Sprite returnSprit();
	sf::Sprite create();
	bool handleClick(int x, int y);
	void setIsPressed(bool isPressed);
	bool getIsPressed();
	sf::Texture& getTexture() { return m_pic; };//const
	
	//void draw(sf::RenderWindow& window);

private:
	bool m_isPressed;
	sf::RectangleShape enemy;
	sf::Vector2f m_position;

	sf::Texture& m_pic;
	 
};
