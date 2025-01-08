
#include "GameObject.h"
#include <vector>
#include <string>
#include "Toolbar.h"


class Board
{
public:
	//Constructor
	Board(int cols = 800, int  rows = 800);

	const bool running() const;

	//Build the window
	void iniwindow();



	//Update the window
	void update();

	void pollEvent();
	bool checkAndHandleIfToolbarClicked(sf::Vector2f loc);
	//Render the window
	void render();

	//Render the toolbar
	void renderToolbar();
	void initToolbar();

	sf::Vector2f  getLoc(sf::Vector2f loc);
	void addObject(sf::Texture&, sf::Vector2f);
	sf::Texture& picphoto(int i);

	//sf::Texture* picphoto(enum State a);
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
	sf::Texture m_background;
	

	//sf::Texture m_empty;
	std::vector<Toolbar>m_toolbar;
	
	Toolbar* m_need2add; // the object that need to be added to the board
	

	 // טבלה חד-ממדית לאובייקטים בלוח
	std::vector<GameObject> m_board;

	//Sprites
	sf::Sprite sprite;


	

	sf::Event ev;

	sf::Vector2f m_position;

	//size of window;
	int m_rows;
	int m_cols;

};








