#define KEY(k) if (sf::Keyboard::isKeyPressed(sf::Keyboard::k))

void keyboard(void)
{
   const float x_angle = sin(hero.b+0.0005*center_x*2);
   const float y_angle = cos(hero.b+0.0005*center_x*2);

   KEY(Left)  hero.b -= hero.r*gameTime;
   KEY(Right) hero.b += hero.r*gameTime;

   KEY(Up){ hero.x += hero.v*x_angle*gameTime;
           hero.y += hero.v*y_angle*gameTime;}

   KEY(Down){ hero.x += -hero.v*x_angle*gameTime;
             hero.y += -hero.v*y_angle*gameTime;}

   KEY(Escape) end();
}
