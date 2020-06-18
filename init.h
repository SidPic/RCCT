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
   init_pair(50, 0, 78);

   init_pair(24, 199, 0);
   init_pair(23, 16,  0);
   init_pair(22, 232, 0);
   init_pair(21, 233, 0);
   init_pair(20, 234, 0);
   init_pair(19, 235, 0);
   init_pair(18, 236, 0);
   init_pair(17, 237, 0);
   init_pair(16, 238, 0);
   init_pair(15, 239, 0);
   init_pair(14, 240, 0);
   init_pair(13, 241, 0);
   init_pair(12, 242, 0);
   init_pair(11, 245, 0);
   init_pair(10, 246, 0);
   init_pair( 9, 247, 0);
   init_pair( 8, 248, 0);
   init_pair( 7, 249, 0);
   init_pair( 6, 250, 0);
   init_pair( 5, 251, 0);
   init_pair( 4, 252, 0);
   init_pair( 3, 253, 0);
   init_pair( 2, 254, 0);
   init_pair( 1, 255, 0);
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
