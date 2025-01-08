

#include "Board.h"
#include <iostream>
 
 
 
Board::Board(int cols, int rows)
    : m_cols(cols), m_rows(rows), m_need2add(picphoto(5), sf::Vector2f(0.f, 0.f), false)
{
    m_background.loadFromFile("tile.jpg");
    m_robot.loadFromFile("robot.jpg");
    m_guard.loadFromFile("guard.jpg");
    m_rock.loadFromFile("rock.jpg");
    m_trash.loadFromFile("trash.jpg");
    m_Wall.loadFromFile("wall.jpg");

    iniwindow();
    initToolbar();
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
    for (int i = 0; i < 5; i++)
    {
         m_toolbar.push_back(Toolbar(picphoto(i), sf::Vector2f(colLocation(i), 0.f), false));
    }
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
    m_window.clear(sf::Color::Green);
    renderToolbar();
	drow(m_window);
   
    m_window.display();
}

bool  Board::checkAndHandleIfToolbarClicked(sf::Vector2f loc) //add "AndHandle" to the name
{
    std::cout << "in function \n";
    for (int i = 0; i < m_toolbar.size(); i++)// m_toolbar.size()
    {
        if ( m_toolbar[i].handleClick(loc.x, loc.y))
        {
            m_toolbar[i].setIsPressed(true);
            //m_state = m_toolbar[i].getType();

			m_need2add.setTexture(m_toolbar[i].getTexture());
			//wait to next press to get location
            std::cout << "found in toolbar \n";
            return true;
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
                    //add for all the enents
                    addObject(m_need2add.getTexture(), loc);
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
	m_board.push_back(GameObject(pic, getLoc(loc)));
    std::cout << "add \n";
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
		return m_background;

    default:
		return m_background;
    }
}

float Board::colLocation(float index)
{
    return ((m_cols / static_cast<float>(7)) * index);
}
 

 
 



