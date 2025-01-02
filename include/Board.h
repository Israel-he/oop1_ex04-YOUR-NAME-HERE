#include "GameObject.h"
#include <vector>
#include <string>

#include "Toolbar.h"
class Board
{
public:
	Board(int cols = 600, int  rows = 800);

	const bool running() const;
	void iniwindow();
	//void creatTool(sf::Vector2f n);
	void adding_tool();
	//void initTextures();
	void update();
	void render();
	void renderToolbar();
	void initToolbar();
	void pollEvent();
	sf::Texture& picphoto(int index);
	 
private:

	//Window
	sf::RenderWindow m_window;
	//size of board
	sf::VideoMode m_videoMode;
	
	sf::Texture m_robot;
	sf::Texture m_guard;
	sf::Texture m_Wall;
	sf::Texture m_trash;
	sf::Texture m_rock;

	sf::Sprite sprite;
	Toolbar m_tool;
	std::vector<Toolbar>m_toolbar;
	 
	sf::Event ev;
	sf::Vector2f n;
	int m_rows;
	int m_cols; 














	/*std::vector<std::unique_ptr<GameObject>> objects;
	std::vector < std::vector<GameObject*>> grid;*/

	/*void placeObject(GameObject* obj, int x, int y);
	void removeObject(int x, int y);
	GameObject* getObjectAt(int x, int y);
	//טעינה ושמירה

	void loadFromFile(const std::string& Filename);
	void saveToFile(const std::string& Filename);


	void draw(sf::RenderWindow& window);
*/
};