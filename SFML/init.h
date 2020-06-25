unsigned short stty_height = 768, stty_width = 1366;
sf::RenderWindow window(sf::VideoMode(1366, 768), "RCoC", sf::Style::Fullscreen);
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
}

void end(void)
{
  window.close();
  exit(0);
}
