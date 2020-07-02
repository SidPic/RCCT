#define KEY(k) if (sf::Keyboard::isKeyPressed(sf::Keyboard::k))
float tmpMouseX;

void keyboard(void)
{
   const float x_angle = sin(hero.b+0.001*center_x);
   const float y_angle = cos(hero.b+0.001*center_x);
   const float dx_angle = sin(hero.b-20+0.001*center_x);
   const float dy_angle = cos(hero.b-20+0.001*center_x);

   KEY(Left)  hero.b -= hero.r*gameTime;
   KEY(Right) hero.b += hero.r*gameTime;

   KEY(W){ hero.x += hero.v*x_angle*gameTime;
           hero.y += hero.v*y_angle*gameTime;}

   KEY(S){ hero.x += -hero.v*x_angle*gameTime;
             hero.y += -hero.v*y_angle*gameTime;}

   KEY(A){ hero.x += hero.v/2*dx_angle*gameTime;
             hero.y += hero.v/2*dy_angle*gameTime; }

   KEY(D){ hero.x += -hero.v/2*dx_angle*gameTime;
             hero.y += -hero.v/2*dy_angle*gameTime;}


   if (sf::Mouse::getPosition(window).x != tmpMouseX)
   {
      int difference = sf::Mouse::getPosition(window).x - tmpMouseX;
      sf::Mouse::setPosition({ (int)window.getSize().x / 2, (int)window.getSize().y / 2 }, window);
      tmpMouseX = sf::Mouse::getPosition(window).x;

      hero.b += difference*gameTime/10000;
   }

   KEY(Escape) end();
}
