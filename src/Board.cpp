#include "Board.h"
 

#include <iostream>
 
const int N = 50;
 
Board::Board(int cols, int rows)
    : m_cols(cols), m_rows(rows)
{
    m_robot.loadFromFile("robot.png");
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
        m_window.draw(m_toolbar[i].returnSprit());
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
	drow(m_window);
    //m_window.draw(sprite);
    
    
    m_window.display();
}


bool  Board::checkIfToolbarClicked(sf::Vector2f loc)
{
    std::cout << "in function \n";
    for (int i = 0; i < m_toolbar.size(); i++)// m_toolbar.size()
    {
        if ( m_toolbar[i].handleClick(loc.x, loc.y))
        {
            m_toolbar[i].setIsPressed(true);
			return true;
			m_need2add = m_toolbar[i].getTexture();
            std::cout << "found in toolbar \n";
        }
    }
	return false;   
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

        case sf::Event::MouseButtonReleased:
            if (ev.key.code == sf::Mouse::Left)
            {
                auto loc = m_window.mapPixelToCoords(sf::Vector2i(ev.mouseButton.x, ev.mouseButton.y));
                if (checkIfToolbarClicked(loc))
                {

                    while (m_window.pollEvent(ev))
                    {
                        if (ev.type == sf::Event::Closed)
                        {
                            m_window.close();
                            return;
                        }
                        else if (ev.type == sf::Event::MouseButtonReleased)
                        {
                            loc = m_window.mapPixelToCoords(sf::Vector2i(ev.mouseButton.x, ev.mouseButton.y));


                            if (!checkIfToolbarClicked(loc))
                            {
                                addObject(m_need2add, loc);

                            }
                            else if (checkIfToolbarClicked(loc))
                                return;
                        }
                    }

                    break;
                }
            }

            break;



        }  
    }  
}

 

void Board::addObject(sf::Texture& pic, sf::Vector2f loc)
{
	m_board.push_back(GameObject(pic, loc));
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
void Board::drow(sf::RenderWindow& window)
{
	for (int i = 0; i < m_board.size(); i++)
	{
		m_board[i].draw(window);
	}
}
//
//void initBoard(int rows, int cols) {
//   
//}



/*oid initBoard(int rows, int cols) {
   
    m_board.resize(rows, std::vector<std::unique_ptr<GameObject>>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if ((i + j) % 2 == 0) {
                m_board[i][j] = std::make_unique<wall>(sf::Vector2f(j * 800, i * 800));
            }
            else {
                m_board[i][j] = std::make_unique<Robot>(sf::Vector2f(j * 800, i * 800));
            }
        }
    }
}*/


//
//void Board::initBoard()
//{
//    m_board.resize(m_rows / 800, std::vector<GameObject>(m_cols / 800));
//
//    for (int i = 0; i < m_board.size(); ++i)
//    {
//        for (int j = 0; j < m_board[i].size(); ++j)
//        {
//            if ((i == 0 || i == m_board.size() - 1) || (j == 0 || j == m_board[i].size() - 1))
//               // m_board.push_back(GameObject('#',sf::Vector2f(colLocation(i), 0.f)));
//               // m_board[i][j] = GameObject('#', i,j); // גבולות הלוח
//           // else
//              //  m_board[i][j] = GameObject(' ', i,j); // שטחים ריקים
//        }
//    }
//}
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
