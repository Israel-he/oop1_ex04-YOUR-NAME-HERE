#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Toolbar
{
public:

	Toolbar(sf::Texture& texture);
	Toolbar(sf::Texture& pic,sf::Vector2f loc,enum State type);
	void putinloc(sf::Vector2f&);
	sf::Sprite returnSprit();
	sf::Sprite create();
	bool handleClick(int x, int y);
	void setIsPressed(bool isPressed);
	void setTexture(sf::Texture& pic) { m_pic = pic; }
	bool getIsPressed();
	sf::Texture& getTexture() { return m_pic; };//const
	State getType();
	//void draw(sf::RenderWindow& window);

private:
	bool m_isPressed;
	 
	sf::Vector2f m_position;

	sf::Texture& m_pic;
	State m_type;
};
