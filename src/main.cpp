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
///*// ����� ����
//
//
//// ������ ������
//
//
//
//class Robot : public GameObject {
//public:
//    Robot() : GameObject('R') {} // ��� ������ ������
//    void draw(sf::RenderWindow& window, int x, int y) override {
//        // ���� ������
//    }
//};
//
//class Door : public GameObject {
//public:
//    Door() : GameObject('D') {} // ��� ������ ����
//    void draw(sf::RenderWindow& window, int x, int y) override {
//        // ���� ����
//    }
//};
//*/