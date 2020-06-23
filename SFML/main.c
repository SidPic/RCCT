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

   for (;;)
   {
      keyboard();
      logic();
      display();
   }
   return 0;
}
