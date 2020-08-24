static int Ch;
unsigned char center_x, center_y;

float goLine(float fx, float fy, float sx, float sy)
{
   const float deltaX = abs(sx - fx);
   const float deltaY = abs(sy - fy);
   const float signX  = fx < sx ? 0.01 : -0.01;
   const float signY  = fy < sy ? 0.01 : -0.01;

   float error = deltaX - deltaY, error2, S = 0;

   while ((map[(int)round(fy)][(int)round(fx)] == ' ' ||
           map[(int)round(fy)][(int)round(fx)] == '.')&& (fx != sx || fy != sy))
   {
      viewMap[(int)round(fy)][(int)round(fx)] = map[(int)round(fy)][(int)round(fx)];
      viewMap[(int)round(fy)][(int)round(fx)] = '.';
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

   viewMap[(int)round(fy)][(int)round(fx)] = map[(int)round(fy)][(int)round(fx)];
   if (map[(int)round(fy)][(int)round(fx)] == 'f')
      Ch = ' ' | A_REVERSE | COLOR_PAIR(50);

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

void drawFloor(void)
{
   unsigned char i = center_y;
   for (i; i < stty_height; i++)
   {
      drawRow(i, '#' | COLOR_PAIR(19-i+center_y));
   }
}

void drawCeil(void)
{
   unsigned char i = 0;
   for (i; i < center_y; i++)
   {
      drawRow(i, '`' | COLOR_PAIR(i));
   }
}

void drawMiniMap(void)
{
   for (short i = hero.y-5; i <= hero.y+5; i++)
   for (short j = hero.x-10; j <= hero.x+10; j++)
   {
      if (i >= 0 && i < MAP_SIZE && j >= 0 && j < MAP_SIZE && viewMap[i][j] != '\0')
      {
         mvaddch(i+stty_height-5-hero.y, j+5-hero.x, viewMap[i][j] | COLOR_PAIR(50));
         if (viewMap[i][j] == '.') viewMap[i][j] = ' ';
      }
      else mvaddch(i+stty_height-5-hero.y, j+5-hero.x, ' ' | COLOR_PAIR(50));
   }
   mvaddch(stty_height-5, 5, '@' | COLOR_PAIR(50));
}

void display(void)
{

   getmaxyx(stdscr, stty_height, stty_width); // ?? оно сильно надо?
   center_x = stty_width/2;                  //
   center_y = stty_height/2;                //

   srand(1000);

   float b = hero.b, x2, y2, s = 1, dSize = 0.01, p = 0, ts;
   unsigned char i = 0, height, color = 1;

   clear();
   drawCeil();
   drawFloor();

   for (i; i < stty_width; i++)
   {
      x2 = hero.x + sin(b)*hero.d;
      y2 = hero.y + cos(b)*hero.d;

      ts = s;
      s = goLine(hero.x, hero.y, x2, y2);
      p = s/cos(abs(stty_width/dSize-sin(b)*hero.d));

      height = (int)round(stty_height)/s;
      if (height < 0) height = 0;
      if (height >= stty_height) height = stty_height;

      color = (int)(s);
      if (color <= 0) color = 1;
      if (color >= 20) color = 20;

      if (s > ts)
         Ch = ' ' | A_REVERSE | COLOR_PAIR(color);
      else if (s < ts)
         Ch = ' ' | A_REVERSE | COLOR_PAIR(color+3);

      b += dSize;
      if (b > hero.b+0.01*stty_width)
         break;

      drawColumn(i, center_y-height/2, height, Ch);
   }

   mvaddch(center_y, center_x, '+' | A_REVERSE);
   drawMiniMap();

   refresh();
}
