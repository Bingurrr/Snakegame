#include <ncurses.h>
#include "map.h"
#include "snake.h"
#include "controll.h"

char Controll::controll(char dir)
{
    int key;
    nodelay(stdscr, true);
    key = getch();
    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();

    switch (key)
    {
    case KEY_UP:
      if(dir=='d')
        dir = 'f';
      else
        dir = 'u';
      break;
    case KEY_LEFT:
      if(dir=='r')
        dir = 'f';
      else
        dir = 'l';
      break;
    case KEY_RIGHT:
      if(dir=='l')
        dir = 'f';
      else
        dir = 'r';
      break;
    case KEY_DOWN:
      if(dir == 'u')
        dir = 'f';
      else
        dir = 'd';
      break;
    default:
        break;
    }

    return dir;
}
