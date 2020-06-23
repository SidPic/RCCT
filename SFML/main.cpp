#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <SFML/Graphics.hpp>
#include <stdbool.h>

#include "map.h"
#include "hero.h"
#include "init.h"
#include "display.h"
#include "keyboard.h"
#include "logic.h"

int main()
{
   init();

   while (window.isOpen())
   {
      gameTime = gameTimer.getElapsedTime().asMicroseconds()/8000;
      gameTimer.restart();
      while (window.pollEvent(event))
      {
         if (event.type == sf::Event::Closed) window.close();
      }
      keyboard();
      logic();
      display();
   }
   return 0;
}
