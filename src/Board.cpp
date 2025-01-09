#include "Board.h"
#include <iostream>
 
 
Board::Board(int cols, int rows)
	 :m_cols(cols), m_rows(rows), m_need2add((new Toolbar(picphoto(5), sf::Vector2f(0.f, 0.f)))),
       m_isPressedOnTrash(false), m_isRobotAdded(false)

{
   
    m_robot.loadFromFile("robot.jpg");
    m_guard.loadFromFile("guard.jpg");
    m_rock.loadFromFile("rock.jpg");
    m_trash.loadFromFile("trash.jpg");
    m_Wall.loadFromFile("wall.jpg");
	m_clearPage.loadFromFile("clearPage.jpg");
	m_door.loadFromFile("door.jpg");
	m_save.loadFromFile("save.jpg");

    iniwindow();
    initToolbar();
    loadBoardFromFile();
    
}

#include <fstream>

void Board::saveBoardToFile() const
{
    std::ofstream outFile("Board.txt");
    if (!outFile)
    {
        std::cerr << "Error opening file for writing.\n";
        return;
    }

    for (int y = 0; y < m_rows / 50; ++y)
    {
        for (int x = 0; x < m_cols / 50; ++x)
        {
            bool found = false;
            for (const auto& obj : m_board)
            {
                if (obj.getLoc().x == x * 50 && obj.getLoc().y == y * 50)
                {
                    if (obj.getTextur().getNativeHandle() == m_robot.getNativeHandle())
                        outFile << '/';
                    else if (obj.getTextur().getNativeHandle() == m_guard.getNativeHandle())
                        outFile << '!';
                    else if (obj.getTextur().getNativeHandle() == m_door.getNativeHandle())
                        outFile << 'D';
                    else if (obj.getTextur().getNativeHandle() == m_Wall.getNativeHandle())
                        outFile << '#';
                    else if (obj.getTextur().getNativeHandle() == m_rock.getNativeHandle())
                        outFile << '@';
                    found = true;
                    break;
                }
            }
            if (!found)
                outFile << ' ';
        }
        outFile << '\n';
    }
    outFile.close();
}

void Board::loadBoardFromFile()
{
    std::ifstream inFile("Board.txt");
    if (!inFile)
    {
        std::cerr << "Error opening file for reading.\n";
        return;
    }

    m_board.clear();
	 
    std::string line;
    int y = 0;
    while (std::getline(inFile, line))
    {
        for (int x = 0; x < line.size(); ++x)
        {
            sf::Vector2f loc(x * 50, y * 50);
            switch (line[x])
            {
            case '/':
                addObject(m_robot, loc);
                break;
            case '!':
                addObject(m_guard, loc);
                break;
            case 'D':
                addObject(m_door, loc);
                break;
            case '#':
                addObject(m_Wall, loc);
                break;
            case '@':
                addObject(m_rock, loc);
                break;
            }
        }
        ++y;
    }
    inFile.close();
}




const bool Board::running() const
{
    return  m_window.isOpen();
}

//Craete the window
void Board::iniwindow()
{
    m_videoMode.height = m_rows;;
    m_videoMode.width = m_cols;
    m_window.create(m_videoMode, "My first game", sf::Style::Titlebar | sf::Style::Close);
}

//update the window
void Board::update()
{
    pollEvent();
}
 

void Board::renderToolbar()
{
   
    for (int i = 0; i < m_toolbar.size(); i++)
    {
        m_window.draw(m_toolbar[i].returnSprit());
    }
}

void Board::initToolbar()
{
    for (int i = 0; i < 8; i++)
    {
         m_toolbar.push_back(Toolbar(picphoto(i), sf::Vector2f(colLocation(i), 0.f)));
    }
}

void Board::ClearAndcreatWindow()
{
	m_board.clear();
	m_window.clear(sf::Color::Black);
	m_window.display();
}

sf::Vector2f Board::getLoc(sf::Vector2f loc)
{
	  
    int x = loc.x / 50;
	int y = loc.y / 50;
	x *= 50;
    y *= 50;
	loc.x = x;
	loc.y = y;
    return loc ;
}

void Board::render()
{
    m_window.clear(sf::Color::Black);
    renderToolbar();
	drow(m_window);
   
    m_window.display();
}

bool  Board::checkAndHandleIfToolbarClicked(sf::Vector2f loc) //add "AndHandle" to the name
{
    for (int i = 0; i < m_toolbar.size(); i++)// m_toolbar.size()
    {
        if (m_toolbar[i].handleClick(loc.x, loc.y))
        {
            if (m_toolbar[i].getTexture().getNativeHandle() == m_clearPage.getNativeHandle())
            {
                ClearAndcreatWindow();
                m_isPressedOnTrash = false;
                return  true;
            }
            else if (m_toolbar[i].getTexture().getNativeHandle() == m_save.getNativeHandle())
            {
                saveBoardToFile();
                //save the board
                m_isPressedOnTrash = false;
                return  true;
            }
            else if (m_toolbar[i].getTexture().getNativeHandle() == m_trash.getNativeHandle())
            {
                m_isPressedOnTrash = true;
                //m_need2add->deleteTexture();
                //deleteObject(getLoc(loc));//
                //deleteObject(getLoc(loc));
                return  true;
            }
            else 
            {
                sf::Texture pic = m_toolbar[i].getTexture();
                //sf::Vector2f loc = m_toolbar[i].getLoc();
               
                m_need2add = &m_toolbar[i];
                m_isPressedOnTrash = false;
                return true;
            }
            
        }
        
    }
    
	return false;   
}

void Board::pollEvent()
{
    m_window.waitEvent(ev);
    {

        switch (ev.type)
        {
        case sf::Event::Closed:
            m_window.close();
            break;

        case sf::Event::MouseButtonReleased:
            if (ev.key.code == sf::Mouse::Left)
            {
                auto loc = m_window.mapPixelToCoords(sf::Vector2i(ev.mouseButton.x, ev.mouseButton.y));

                if (!checkAndHandleIfToolbarClicked(loc))
                {

                    if (m_isPressedOnTrash)
                    {
                        
                        deleteObject(getLoc(loc));
                    } 
                    else
                    { 
                        //add for all the enents
                        addObject(m_need2add->getTexture(), loc);
                    } 
                }
            }
            break;
        }
    }
}


void Board::drow(sf::RenderWindow& window)
{

    for (int i = 0; i < m_board.size(); i++)
    {
        m_board[i].draw(window);

    }
}


void Board::addObject(sf::Texture& pic, sf::Vector2f loc)
{
    if (&pic == &m_robot && m_isRobotAdded)
    {
        std::cout << "Robot already added, cannot add another one.\n";
        return;
    }
     
        m_board.push_back(GameObject(pic, getLoc(loc)));
    
	if (&pic == &m_robot)
	{
		m_isRobotAdded = true;
	}
}
 

void Board::deleteObject(sf::Vector2f loc)
{
	for (int i = 0; i < m_board.size(); i++)
	{
		if (m_board[i].getLoc().x == loc.x && m_board[i].getLoc().y == loc.y)
		{
            if (m_board[i].getTextur().getNativeHandle() == m_robot.getNativeHandle())
            {
                m_isRobotAdded = false;
            }
			m_board.erase(m_board.begin() + i);
            break;
		}
	}
}





sf::Texture& Board::picphoto(int a)
{
    switch (a)
    {
    case  0:
        return m_robot;

    case  1:
        return m_guard;

    case  2:
        return m_Wall;

    case  3:
        return  m_trash;

    case  4:
        return m_rock;
	 
	case  5:
		return m_save;
	case  6:
		return m_door;
	case  7:
		return m_clearPage;
    }
}

 

float Board::colLocation(float index)
{
    return ((m_cols / static_cast<float>(8)) * index);
}
 

 
 



