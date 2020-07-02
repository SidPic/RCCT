unsigned short stty_height = 768, stty_width = 1366;
sf::RenderWindow window(sf::VideoMode(stty_width, stty_height), "RCoC", sf::Style::Fullscreen);
sf::Event event;
sf::Clock gameTimer;
float gameTime = 1;
sf::Image sandstone_image;
sf::Texture sandstone_texture;
sf::Sprite sandstone_sprite;

void init(void)
{
   setlocale(LC_CTYPE, "");

   sandstone_image.loadFromFile("Images/sandstone.jpg");
   sandstone_texture.loadFromImage(sandstone_image);
   sandstone_texture.setRepeated(true);
   sandstone_sprite.setTexture(sandstone_texture);

   window.setMouseCursorVisible(false);
}

void end(void)
{
  window.close();
  exit(0);
}
