#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace sf;

int main ()
{
  int i = 0;
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

          }
          if (ev.key.code == Keyboard::B)
          {
            display = false;
          }
          // if (Keyboard::isKeyPressed(Keyboard::N))
          // {
          //   for (int i = 0; i < points; i++)
          //   {
          //     if (Mouse::isButtonPressed(Mouse::Left))
          //     {     
          //         convex.setPoint(i, Vector2f(x, y));
          //     }           
          //   }
            
          // }
          
          std::cout << "key:" << ev.key.code << std::endl;

        case Event::MouseButtonPressed:
          Vector2i pos = Mouse::getPosition(win);
          x = pos.x;
          y = pos.y;
          i++;
          if (i > points) {i = 0;}
          if (Mouse::isButtonPressed(Mouse::Left))
          {
            
            convex.setPoint(i, Vector2f(x, y));
                    
          }
            
          std::cout << "x:" << x << "y:" << y << std::endl;
          


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
