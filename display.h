float goLine(float fx, float fy, float sx, float sy)
{
   const float deltaX = abs(sx - fx);
   const float deltaY = abs(sy - fy);
   const float signX  = fx < sx ? 0.01 : -0.01;
   const float signY  = fy < sy ? 0.01 : -0.01;

   float error = deltaX - deltaY, error2, S = 0;

   while (map[(int)round(fy)][(int)round(fx)] == ' ' && (fx != sx || fy != sy))
   {
//      mvaddch((int)round(fy), (int)round(fx), '.');
      error2 = error*2;

      if (error2 > -deltaY)
      {
         error -= deltaY;
         fx += signX;
         S += 0.01;
      }
      if (error2 < deltaX)
      {
         error += deltaX;
         fy += signY;
         S += 0.01;
      }
   }

   return S;
}

void drawColumn(unsigned char x, char y, unsigned char h, int ch)
{
   h = y+h;
   for (y; y <= h; y++)
   {
      mvaddch(y, x, ch);
   }
}

void drawRow(unsigned char y, int ch)
{
   unsigned char x = 0;
   for (x; x < stty_width; x++)
   {
      mvaddch(y, x, ch);
   }
}

void drawFloor()
{
   unsigned char i = stty_height/2;
   for (i; i < stty_height; i++)
   {
      drawRow(i, '#' | COLOR_PAIR(19-i+stty_height/2));
   }
}

void drawCeil()
{
   unsigned char i = 0;
   for (i; i < stty_height/2; i++)
   {
      drawRow(i, '`' | COLOR_PAIR(i));
   }
}

void drawMiniMap(void)
{
   unsigned char i = 0;

   for (i; i < MAP_SIZE; i++)
      mvaddstr(i, 0, map[i]);
   mvaddch(hero.y, hero.x, '@');
}

void display(void)
{
   getmaxyx(stdscr, stty_height, stty_width); // ?? оно сильно надо?
   clear();

   float b = hero.b, x2, y2, s = 1, ts, dSize = 0.01, p = 0, delta;
   unsigned char i = 0, height, color = 1;

//   drawMiniMap();

   drawCeil();
   drawFloor();

   for (i; i < stty_width; i++)
   {
      x2 = hero.x + sin(b)*hero.d;
      y2 = hero.y + cos(b)*hero.d;
      delta = abs(stty_width/2-(b-hero.b)/i);
      if (delta <= 0) delta = 1;

      ts = s;
      s = goLine(hero.x, hero.y, x2, y2);

      height = (int)round(stty_height/s);
      if (height < 0) height = 0;
      if (height >= stty_height) height = stty_height;

      color = round(s);
      if (color <= 0) color = 1;
      if (color > 17) color = 17;

      b += dSize;

      if (s == ceil(ts))
      {
         drawColumn(i, stty_height/2-height/2, height, '|' | A_REVERSE | COLOR_PAIR(color));
      }
      else
      {
         drawColumn(i, stty_height/2-height/2, height, ' ' | A_REVERSE | COLOR_PAIR(color));
      }
   }

   mvaddch(stty_height/2, stty_width/2, '+');

   refresh();
}
