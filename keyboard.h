void keyboard(void)
{
   const float x_angle = sin(hero.b+0.01*center_x);
   const float y_angle = cos(hero.b+0.01*center_x);

   switch(getch())
   {
      case KEY_LEFT : hero.b -= hero.r; break;
      case KEY_RIGHT: hero.b += hero.r; break;

      case KEY_UP   : hero.x += hero.v*x_angle;
                      hero.y += hero.v*y_angle;
      break;
      case KEY_DOWN : hero.x += -hero.v*x_angle;
                      hero.y += -hero.v*y_angle;
      break;
      case '\x1b': end();
   }
}
