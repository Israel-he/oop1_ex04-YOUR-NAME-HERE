#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Toolbar
{
public:

	 
	Toolbar(sf::Texture& pic);
	Toolbar(sf::Texture& pic,sf::Vector2f loc);
	sf::Sprite returnSprit();
	sf::Sprite create();
	bool handleClick(int x, int y);
	void setLoc(sf::Vector2f loc) { m_position = loc; }
	sf::Vector2f getLoc();
	void setTexture(sf::Texture& pic) { m_pic = pic; }
	sf::Texture& getTexture() const{ return m_pic; };//const
	void deleteTexture();
	 

private:

	sf::Texture& m_pic;
	sf::Vector2f m_position;	
};
