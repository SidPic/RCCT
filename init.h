unsigned char stty_height, stty_width;
bool in_X = true;

void init(void)
{
   setlocale(LC_CTYPE, "");

   initscr();
   getmaxyx(stdscr, stty_height, stty_width);

   noecho();
   curs_set(0);

   keypad(stdscr, 1);
   timeout(100);

   if (system("xset r rate 120 10"))
      in_X = false;

   start_color();
   init_pair(17, 232, 0);
   init_pair(16, 233, 0);
   init_pair(15, 234, 0);
   init_pair(14, 235, 0);
   init_pair(13, 236, 0);
   init_pair(12, 237, 0);
   init_pair(11, 238, 0);
   init_pair(10, 239, 0);
   init_pair( 9, 240, 0);
   init_pair( 8, 241, 0);
   init_pair( 7, 242, 0);
   init_pair( 6, 245, 0);
   init_pair( 5, 246, 0);
   init_pair( 4, 247, 0);
   init_pair( 3, 248, 0);
   init_pair( 2, 249, 0);
   init_pair( 1, 250, 0);
}

void end(void)
{
   endwin();

   if (in_X)
      system("xset r rate");
   else
      fputs("Рекомендуется запуск в X-сервере!", stderr);

  exit(0);
}
