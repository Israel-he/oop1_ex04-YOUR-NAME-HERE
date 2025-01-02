#include "GameObject.h" 


class Wall : public GameObject {
public:
    Wall(sf::Vector2f pos) : GameObject('#', pos) {}

    void draw(sf::RenderWindow& window) const override {
        sf::RectangleShape rect(sf::Vector2f(50.f, 50.f));
        rect.setPosition(position);
        rect.setFillColor(sf::Color::Blue);
        window.draw(rect);
    }
};





















//class Wall : public GameObject 
//{
//public:
//    Wall()::GameObject('#'); // סמל ייחודי לקיר
//    void draw(sf::RenderWindow& window, int x, int y) override 
//        // ציור הקיר
//    
//};