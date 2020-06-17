#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <ncurses.h>
#include <stdbool.h>

#include "hero.h"
#include "map.h"
#include "init.h"
#include "display.h"
#include "keyboard.h"
#include "logic.h"

void main()
{
   init();

   for (;;)
   {
      keyboard();
      logic();
      display();
   }
}
