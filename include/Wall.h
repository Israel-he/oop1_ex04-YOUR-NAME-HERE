


class Wall : public GameObject {
public:
	sf::Texture texture;
    Wall(sf::Vector2f pos) : GameObject(texture, pos) {}
   
	
	void draw(sf::RenderWindow& window) override {
		sf::Sprite sprite = create();
		window.draw(sprite);
	}
    
};

/*
void draw(sf::RenderWindow& window)   {
		sf::Sprite sprite;
		sprite.setTexture(texture);
		window.draw(sprite);
	}*/



















//class Wall : public GameObject 
//{
//public:
//    Wall()::GameObject('#'); // סמל ייחודי לקיר
//    void draw(sf::RenderWindow& window, int x, int y) override 
//        // ציור הקיר
//    
//};