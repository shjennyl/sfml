#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cstdlib>

using namespace sf;

class Roid {
    public:

		Roid(const RenderWindow& W, int rad, int x, int y, int r, int g, int b);
		void move(float x, float y);
		void update();
		Sprite sprite; //must be public so we can draw it	
	
	private:
		RenderWindow* W;
		Vector2f pos;		   
		float rad;
		float winwidth; //assigned in ctor method below
		float winheight ;
		Texture texture; //static so we don't have a texture for each instance
};

class Ship {
    public:

		Ship(const RenderWindow& W, int rad, int x, int y, int r, int g, int b);
		void move(float x, float y);
		void update();
		Sprite sprite; //must be public so we can draw it	
	
	private:
		RenderWindow* W;
		Vector2f pos;		   
		float rad;
		float winwidth; //assigned in ctor method below
		float winheight ;
		Texture texture; //static so we don't have a texture for each instance
};


int main()
{
	Event event;
    RenderWindow window(VideoMode(800,600), "SFML Test");
    Roid roid(window, 50, 100, 30, 250, 0, 0);
    Ship ship(window, 50,100,30,250,0,0);
    
    srand(static_cast<unsigned>(time(0)));
    int x, y;
    x = rand()%10+5;
    y = rand()%10+5;

    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case Event::Closed:
                window.close();
                break;

                default:
                break;
            }

        }

        roid.move(x,y);
        
        roid.update();
        ship.update();
        
		window.setFramerateLimit(60);
        window.clear(Color::White);
        
        window.draw(roid.sprite);
        window.draw(ship.sprite);
        
        window.display();
    }
    return 0;
}


Roid::Roid(const RenderWindow& W, int rad, int x, int y, int r, int g, int b)
{
	winheight= W.getSize().y;
	winwidth= W.getSize().x;
    texture.loadFromFile("meteor3.png");
    Vector2u v= texture.getSize();
    float xs= 100./v.x; //make sprite 100 pixels wide and high
    float ys= 100./v.y;
    std::cout<<xs<<std::endl;
    sprite.setTexture(texture);
    sprite.setOrigin(v.x/2,v.y/2); 
    // must setOrigin to center *before* scaling 
    sprite.setScale(xs,ys);
	sprite.setPosition(x,y);
    
    
}


void Roid::move(float x, float y)
{
	sprite.move(x,y);
}

void Roid::update(){
	
	pos = sprite.getPosition();
	float rad = 50.;
		
	if ( pos.x - rad > winwidth) //beyond right side
    {   
        pos.x = 0;
    }   
    if ( pos.y - rad > winheight) //beyond bottom
    {   
        pos.y = 0;
    }   
    
    if( pos.x + rad < 0) //beyond left side
    {   
        pos.x = winwidth;
    }   
    if( pos.y + rad < 0) //beyond top
    {   
        pos.y = winheight;
    }   
	sprite.setPosition(pos.x, pos.y);
	sprite.rotate(4);
}

Ship::Ship(const RenderWindow& W, int rad, int x, int y, int r, int g, int b)
{
	winheight= W.getSize().y;
	winwidth= W.getSize().x;
    texture.loadFromFile("ship.png");
    Vector2u v= texture.getSize();
    float xs= 100./v.x; //make sprite 100 pixels wide and high
    float ys= 100./v.y;
    std::cout<<xs<<std::endl;
    sprite.setTexture(texture);
    sprite.setOrigin(v.x/2,v.y/2); 
    // must setOrigin to center *before* scaling 
    sprite.setScale(xs,ys);
	sprite.setPosition(x,y);
    
    
}


void Ship::move(float x, float y)
{
	sprite.move(x,y);
}

void Ship::update(){
	
	if(Keyboard::isKeyPressed(Keyboard::Left))
	{
		sprite.move(-10,0.);
	}
	if(Keyboard::isKeyPressed(Keyboard::Right))
	{
		sprite.move(10,0);
	}
	if(Keyboard::isKeyPressed(Keyboard::Down))
	{
		sprite.move(0,10);
	}
	if(Keyboard::isKeyPressed(Keyboard::Up))
	{
		sprite.move(0,-10);
	}
	
	pos = sprite.getPosition();
	float rad = 50.;
		
	if ( pos.x - rad > winwidth) //beyond right side
    {   
        pos.x = 0;
    }   
    if ( pos.y - rad > winheight) //beyond bottom
    {   
        pos.y = 0;
    }   
    
    if( pos.x + rad < 0) //beyond left side
    {   
        pos.x = winwidth;
    }   
    if( pos.y + rad < 0) //beyond top
    {   
        pos.y = winheight;
    }   
	sprite.setPosition(pos.x, pos.y);
}
