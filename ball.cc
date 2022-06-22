#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace sf;

class Ball {

    public:

		Ball(int rad, int x, int y, int r, int g, int b);
		CircleShape C;	//must be public so we can draw it	
		void move(float x, float y);
		void update();
	
	private:
};

int main()
{
    Ball ball(50, 100, 30, 250, 0, 0);

	Event event;
    RenderWindow window(VideoMode(800,600), "SFML Test");
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

        ball.update();
        window.clear(Color::Black);
        window.draw(ball.C);
        window.display();
    }
    return 0;

}


Ball::Ball(int rad, int x, int y, int r, int g, int b)
{
    
    C.setRadius(rad);
    C.setFillColor(Color(r,g,b));
    C.setPosition(x,y);
}


void Ball::move(float x, float y)
{
	C.move(x,y);
}

void Ball::update(){
	if(Keyboard::isKeyPressed(Keyboard::Left))
	{
		C.move(-1,0);
	}
	if(Keyboard::isKeyPressed(Keyboard::Right))
	{
		C.move(1,0);
	}
	if(Keyboard::isKeyPressed(Keyboard::Down))
	{
		C.move(0,1);
	}
	if(Keyboard::isKeyPressed(Keyboard::Up))
	{
		C.move(0,-1);
	}
}
