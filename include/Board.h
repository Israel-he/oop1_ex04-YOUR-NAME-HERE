#include "GameObject.h"
#include <vector>
#include <string>
#include "Toolbar.h"


class Board
{
public:
	//Constructor
	Board(int cols = 800, int  rows = 800);//

	const bool running() const;

    //Build the window
	void iniwindow();

 

	//Update the window
	void update();
	 
	void pollEvent();
	bool checkIfToolbarClicked(sf::Vector2f loc);
	//Render the window
	void render();

	//Render the toolbar
	void renderToolbar();
	void initToolbar();
	
	void addObject(sf::Texture& ,sf::Vector2f);
	sf::Texture* picphoto(float index);
	float colLocation(float index);
	void drow(sf::RenderWindow& window);
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

	sf::Texture m_need2add;
	// טבלה חד-ממדית לאובייקטים בלוח
	std::vector<GameObject> m_board;

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