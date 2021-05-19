#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace sf;

int main ()
{
  int points = 5;
  bool display = true;
  ConvexShape convex;
  convex.setPointCount(points);
  convex.setFillColor(Color::Green);
  RenderWindow win(VideoMode(1600, 800), "fuck you");
  int x;
  int y;


  while (win.isOpen())
  {
    Event ev;
    while(win.pollEvent(ev))
    {
        switch (ev.type)
        {
        case Event::Closed :
          win.close();
          break;

        case Event::KeyPressed:
          if (Keyboard::isKeyPressed(Keyboard::A))
          {
            display = true;
            convex.setPoint(0, sf::Vector2f(0.f, 0.f));
            convex.setPoint(1, sf::Vector2f(150.f, 10.f));
            convex.setPoint(2, sf::Vector2f(120.f, 90.f));
            convex.setPoint(3, sf::Vector2f(30.f, 100.f));
            convex.setPoint(4, sf::Vector2f(0.f, 50.f));
          }
          if (ev.key.code == Keyboard::B)
          {
            display = false;
          }
          // if (Keyboard::isKeyPressed(Keyboard::B))
          // {

          // }
          
          std::cout << "key:" << ev.key.code << std::endl;
        case Event::MouseButtonPressed:
          Vector2i pos = Mouse::getPosition(win);
          x = pos.x;
          y = pos.y;

          if (Mouse::isButtonPressed(Mouse::Left))
          {
            
              std::cout << "x:" << x << "y:" << y << std::endl;
          }


        }
    }
    win.clear(Color::White);
    if (display)
    {
      win.draw(convex);
    }
    
    
    win.display();
  }

  
}
