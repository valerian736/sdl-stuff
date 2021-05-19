#include <SFML/Window.hpp>
using namespace sf;

int main ()
{
  Window win(VideoMode(800, 600), "fuck you");

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

      

    }
  }
  
}