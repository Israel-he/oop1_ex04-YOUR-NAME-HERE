#include "GameObject.h"
#include <vector>
#include <string>

#include "Toolbar.h"
class Board
{
public:
	Board(int cols = 800, int  rows = 800);

	const bool running() const;

    //Build the window
	void iniwindow();

	//draw the toolbar in side the window
    //void  drawToolbar();

	//Update the window
	void update();
	 
	void pollEvent();

	//Render the window
	void render();

	//void creatTool(sf::Vector2f n);
	//void adding_tool();
	//void initTextures();
	
	void createToolbar();
	void renderToolbar();
	void initToolbar();
	
	sf::Texture* picphoto(float index);
	float colLocation(float index);
private:

	//Window
	sf::RenderWindow m_window;
	//size of board
	sf::VideoMode m_videoMode;
	 
	//Textures
	sf::Texture m_robot;
	sf::Texture m_guard;
	sf::Texture m_Wall;
	sf::Texture m_trash;
	sf::Texture m_rock;

	//Sprites
	sf::Sprite sprite;

	 
	std::vector<Toolbar>m_toolbar;
	 
	sf::Event ev;

	sf::Vector2f m_position;
	 
	//size of window;
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