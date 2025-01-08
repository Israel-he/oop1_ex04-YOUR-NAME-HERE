#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Toolbar
{
public:

	 
	Toolbar(sf::Texture& pic);
	Toolbar(sf::Texture& pic,sf::Vector2f loc, bool mode= false);
	sf::Sprite returnSprit();
	sf::Sprite create();
	bool handleClick(int x, int y);
	void setIsPressed(bool isPressed);
	void setTexture(sf::Texture& pic) { m_pic = pic; }
	bool getIsPressed();
	sf::Texture& getTexture() { return m_pic; };//const
	//State getType();
	//void draw(sf::RenderWindow& window);

private:

	sf::Texture& m_pic;
	sf::Vector2f m_position;
	bool m_isPressed; 
	
	
	
};
