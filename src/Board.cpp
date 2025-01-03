#include "Board.h"
#include <iostream>
 
Board::Board(int cols, int  rows)
	: m_cols(cols), m_rows(rows) 
{
   
    m_robot.loadFromFile("robot.png");
	//sprite.setTexture(m_robot);
    
    m_guard.loadFromFile("guard.png");
    m_rock.loadFromFile("rock.PNG");
    m_trash.loadFromFile("trash.png");
    m_Wall.loadFromFile("Wall.PNG");
     
   
     
    
    iniwindow();
    initToolbar();
	/*createToolbar();*/
	
   
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
	 
    // m_window.setFramerateLimit(60);
}

//update the window
void Board::update()
{
    pollEvent();
}

//void Board::createToolbar()
//{
//    initToolbar();
//	
//}

void Board::renderToolbar()
{
    for (int i = 0; i < m_toolbar.size(); i++)
    {
        m_window.draw(m_toolbar[i].returnsprit());
    }
}

void Board::initToolbar()
{
    for (float i = 0; i < 5; i++)
    {
        m_toolbar.push_back(Toolbar( *picphoto(i), sf::Vector2f(colLocation(i), 0.f)));
       // m_window.draw(m_toolbar[i].returnsprit());
    }
}

void Board::render()
{
    m_window.clear(sf::Color::Green);

    renderToolbar();
    
    m_window.draw(sprite);
    
    
    m_window.display();
}




void Board::pollEvent()
{
    while (m_window.pollEvent(ev))
    {
        switch (ev.type)
        {
        case sf::Event::Closed:
            m_window.close();
            break;

   /*     case sf::Event::MouseButtonReleased:
            if (ev.key.code == sf::Mouse::Right)
                m_window.draw(sprite);
            break;*/




        }
    }
}

 

sf::Texture* Board::picphoto(float index)
{
    switch ((int)index)
    {
    case  0:
        return &m_robot;

    case  1:
        return &m_guard;

    case  2:
        return &m_Wall;

    case  3:
        return  &m_trash;

    case  4:
        return &m_rock;

    default:
        return nullptr;
    }
}

float Board::colLocation(float index)
{
    return ((m_cols / static_cast<float>(6)) * index);
}

//


/////////////////////////////////////////
//void Board::placeObject(GameObject* obj, int x, int y)
//{
//}
//
//void Board::removeObject(int x, int y)
//{
//}
//
//GameObject* Board::getObjectAt(int x, int y)
//{
//	return nullptr;
//}
//
//void Board::loadFromFile(const std::string& Filename)
//{
//}
//
//void Board::saveToFile(const std::string& Filename)
//{
//}
//
//void Board::draw(sf::RenderWindow& window)
//{
//}

//void Board::drawToolbar()
//{
//	for (int i = 0; i < m_toolbar.size(); i++)
//	{
//		m_toolbar[i].returnsprit().setPosition(i * 20.f, 0.f);
//		
//	}
//}