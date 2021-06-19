#include <ncurses.h>
#include <unistd.h>
#include "snake.h"
#include "map.h"


Map m;
int main()
{

    for(int i=1; i<5; i++){
      m.getMap(i);
      while (1)
      {
        m.render();
        if ( m.md == 'f'){
          m.failed();
          m.clearMap();
          usleep(300000);
          i=5;
          break;

        }
        else if (m.md == 's'){
          m.success();
          m.clearMap();
          usleep(3000000);
          break;
        }
        usleep(300000); 
      }
    }
    endwin();

    return 0;
}
