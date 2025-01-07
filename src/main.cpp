#include "Board.h"


int main()
{
    Board board;

    while (board.running())
    {    
        board.render();
        board.update();



    }
}


























//#include "mainAplicion.h"
//int main()
//{
//    mainAplicion m(2, 3);
//    
//}
///*// מחלקת בסיס
//
//
//// מחלקות יורשות
//
//
//
//class Robot : public GameObject {
//public:
//    Robot() : GameObject('R') {} // סמל ייחודי לרובוט
//    void draw(sf::RenderWindow& window, int x, int y) override {
//        // ציור הרובוט
//    }
//};
//
//class Door : public GameObject {
//public:
//    Door() : GameObject('D') {} // סמל ייחודי לדלת
//    void draw(sf::RenderWindow& window, int x, int y) override {
//        // ציור הדלת
//    }
//};
//*/