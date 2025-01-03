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
	sf::Sprite returnsprit();
	sf::Sprite create();
	int handleClick(int x, int y);

 
	

	//void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape enemy;
	sf::Vector2f m_position;

	sf::Texture& m_pic;
	 
};
