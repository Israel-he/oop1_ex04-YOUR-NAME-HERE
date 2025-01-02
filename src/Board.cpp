#include "Board.h"
#include <iostream>
 
Board::Board(int cols, int  rows)
	: m_cols(cols),m_rows(rows) 
{
    std::cout << "no!!";
    m_robot.loadFromFile("robot.png");
    m_guard.loadFromFile("guard.png");
    m_rock.loadFromFile("rock.PNG");
    m_trash.loadFromFile("trash.png");
    m_Wall.loadFromFile("Wall.PNG");
    sprite.setTexture(m_robot);
   
    sprite.setPosition(1.f, 1.f);
    
    iniwindow();
  
}
 
const bool Board::running() const
{
    
    return  m_window.isOpen();
     
}


void Board::iniwindow()
{
    m_videoMode.height = m_rows;;
    m_videoMode.width = m_cols;

    m_window.create(m_videoMode, "My first game", sf::Style::Titlebar | sf::Style::Close);

    
    // m_window.setFramerateLimit(60);
}

//void Board::creatTool(sf::Vector2f n)
//{
//      
//    m_toolbar.push_back(Toolbar(n));
//}

void Board::adding_tool()
{
    //for (int i = 1; i < 7; i++)
    //{
    //    int r = (m_rows / 6) * i;
    //   r= (float)(m_rows / 6)* i;
    //    sf::Vector2f num;
    //    num.x = 0.f;
    //    num.y = r;
    //    //to put it in order on the top of the window
    //     creatTool(num);
    //}
}

void Board::update()
{
   
    pollEvent();
   
    //adding_tool();
}

void Board::renderToolbar()
{
    for (int i = 0; i < m_toolbar.size(); i++)
    {
        m_window.draw(m_toolbar[i].returnsprit());
    }
}

void Board::initToolbar()
{

    sf::Vector2f locaition;
    locaition.x = 0.f;
    locaition.y = 0.f;
    for (int i = 0; i < 6; i++)
    {
        Toolbar m_tool(picphoto(i));
       
        m_tool.putinloc(locaition);
        m_toolbar.push_back(m_tool);
        locaition.x += 20.f;
    }
    sf::Texture pictuar;
    
   
}

void Board::render()
{
    m_window.clear(sf::Color::Green);
    //renderToolbar();
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

sf::Texture& Board::picphoto(int index)
{
    // TODO: insert return statement here
}

sf::Texture& Board::picphoto(int index)
{
    switch (index)
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
}

 


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
