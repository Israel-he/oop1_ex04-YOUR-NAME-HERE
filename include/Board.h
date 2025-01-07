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

	




	
	void addObject(sf::Texture& ,sf::Vector2f);
	sf::Texture* picphoto(enum State);
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
	State m_state;
	//Toolbar m_empty;
	//
//	 Toolbar& m_need2add;//change to tollbar
	// ���� ��-����� ���������� ����
	std::vector<GameObject> m_board;

	//Sprites
	sf::Sprite sprite;

	 
	std::vector<Toolbar>m_toolbar;
	 
	sf::Event ev;

	sf::Vector2f m_position;
	 
	//size of window;
	int m_rows;
	int m_cols; 




	enum  State
	{
		robot = 0,
		guard = 1,
		Wall = 2,
		trash = 3,
		rock = 4,

		Erase = 5
	};









	/*std::vector<std::unique_ptr<GameObject>> objects;
	std::vector < std::vector<GameObject*>> grid;*/

	/*void placeObject(GameObject* obj, int x, int y);
	void removeObject(int x, int y);
	GameObject* getObjectAt(int x, int y);
	//����� ������

	void loadFromFile(const std::string& Filename);
	void saveToFile(const std::string& Filename);


	void draw(sf::RenderWindow& window);
*/
};