static int Ch;
unsigned short center_x, center_y;

float goLine(float fx, float fy, float sx, float sy)
{
   const float deltaX = abs(sx - fx);
   const float deltaY = abs(sy - fy);
   const float signX  = fx < sx ? 0.01 : -0.01;
   const float signY  = fy < sy ? 0.01 : -0.01;

   float error = deltaX - deltaY, error2, S = 0;

   while (map[(int)round(fy)][(int)round(fx)] == ' ' && (fx != sx || fy != sy))
   {
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


void drawColumn(int x, int y, int h, int color, float dx, float dy, float fx, float fy, float db)
{
   dx = 0;
   dy = 0;

}

void display(void)
{
   window.clear();
   center_x = stty_width/2;
   center_y = stty_height/2;

   float b = hero.b, x2, y2, s = 1, dSize = 0.001, ts, px;
   short i = 0, height, color = 1, dcolor;

   for (i; i < stty_width; i++)
   {
      x2 = hero.x + sin(b)*hero.d;
      y2 = hero.y + cos(b)*hero.d;

      s = goLine(hero.x, hero.y, x2, y2);

      dcolor = round(s*10+s*10);

      b += dSize;
      if (b > hero.b+dSize*stty_width)
         break;
      if (dcolor >= 255)
         continue;

      height = (int)round(stty_height/s);
      if (height < 0) height = 0;
      if (height >= stty_height) height = stty_height;

      px = i;
      if (px > 450) px -= 450*(round(px/450)-1);

      sandstone_sprite.setPosition(i, center_y-height/2);
      sandstone_sprite.setTextureRect(sf::IntRect(px, 0, 1, height));
      sandstone_sprite.setColor(sf::Color(255-dcolor, 255-dcolor, 255-dcolor));
      window.draw(sandstone_sprite);
   }
   window.display();
}
