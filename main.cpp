#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

int main ()
{
  ConvexShape convex;
  convex.setPointCount(5);
  convex.setFillColor(Color::Green);
  RenderWindow win(VideoMode(1600, 800), "fuck you");

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
            convex.setPoint(0, sf::Vector2f(0.f, 0.f));
            convex.setPoint(1, sf::Vector2f(150.f, 10.f));
            convex.setPoint(2, sf::Vector2f(120.f, 90.f));
            convex.setPoint(3, sf::Vector2f(30.f, 100.f));
            convex.setPoint(4, sf::Vector2f(0.f, 50.f));
          }
          std::cout << "key:" << ev.key.code << std::endl;

        }
    }
    win.clear(Color::White);
    win.draw(convex);
    win.display();
  }

  
}
