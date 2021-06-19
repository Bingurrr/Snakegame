#include <ncurses.h>
#include <cstring>
#include "snake.h"
#include "map.h"
#include <iostream>
void Snake::Move(char dir, char v[][25], int gate[][2])
{
  int s = body_y.size();
    if (dir == 'l'){
      direction = 'l';
      if(v[head_y][head_x-1]=='G'){
        body_y.push_back(body_y[s-1]);
        body_x.push_back(body_x[s-1]);
        count_plu++;
      }
      else if(v[head_y][head_x-1]=='S'){
        body_y.pop_back();
        body_x.pop_back();
        count_min++;
      }
      head_x--;
      rebody();
    }
    else if (dir == 'r'){
      direction = 'r';
      if(v[head_y][head_x+1]=='G'){
        body_y.push_back(body_y[s-1]);
        body_x.push_back(body_x[s-1]);
        count_plu++;
      }
      else if(v[head_y][head_x+1]=='S'){
        body_y.pop_back();
        body_x.pop_back();
        count_min++;
      }
      head_x++;
      rebody();
    }
    else if (dir == 'u'){
      direction = 'u';
      if(v[head_y-1][head_x]=='G'){
        body_y.push_back(body_y[s-1]);
        body_x.push_back(body_x[s-1]);
        count_plu++;
      }
      else if(v[head_y-1][head_x]=='S'){
        body_y.pop_back();
        body_x.pop_back();
        count_min++;
      }
      head_y--;
      rebody();
    }
    else if (dir == 'd'){
      direction = 'd';
      if(v[head_y+1][head_x]=='G'){
        body_y.push_back(body_y[s-1]);
        body_x.push_back(body_x[s-1]);
        count_plu++;
      }
      else if(v[head_y+1][head_x]=='S'){
        body_y.pop_back();
        body_x.pop_back();
        count_min++;
      }
      head_y++;
      rebody();
    }


      if(head_y==gate[0][0]&&head_x==gate[0][1]){
        count_gate++;
     
        if(gate[1][0]==0){
          head_y = gate[1][0] + 1;
          head_x = gate[1][1];
          pass();
          direction = 'd';
        }
        else if(gate[1][0]==24){
          head_y = gate[1][0] - 1;
          head_x = gate[1][1];
          pass();
          direction = 'u';
        }
        else if(gate[1][1]==24){
          head_y = gate[1][0];
          head_x = gate[1][1] - 1;
          pass();
          direction = 'l';
        }
        else if(gate[1][1]==0){
          head_y = gate[1][0];
          head_x = gate[1][1] + 1;
          pass();
          direction = 'r';
        }
  
        if( direction == 'l'){
          if( v[gate[1][0]][gate[1][1]-1] == ' '){
            head_y = gate[1][0];
            head_x = gate[1][1] - 1;
            pass();
            direction = 'l';
          }
          else if ( v[gate[1][0]-1][gate[1][1]] == ' '){
           head_y = gate[1][0] - 1;
           head_x = gate[1][1];
           pass();
           direction = 'u';
          }
          else if ( v[gate[1][0]][gate[1][1]+1] == ' '){
            head_y = gate[1][0];
            head_x = gate[1][1] + 1;
            pass();
            direction = 'r';
          }
          else if ( v[gate[1][0]+1][gate[1][1]] == ' '){
            head_y = gate[1][0] + 1;
            head_x = gate[1][1];
            pass();
            direction = 'd';
          }
        }
        else if( direction == 'u'){
          if ( v[gate[1][0]-1][gate[1][1]] == ' '){
           head_y = gate[1][0] - 1;
           head_x = gate[1][1];
           pass();
           direction = 'u';
          }
          else if ( v[gate[1][0]][gate[1][1]+1] == ' '){
            head_y = gate[1][0];
            head_x = gate[1][1] + 1;
            pass();
            direction = 'r';
          }
          else if ( v[gate[1][0]+1][gate[1][1]] == ' '){
            head_y = gate[1][0] + 1;
            head_x = gate[1][1];
            pass();
            direction = 'd';
          }
          else if( v[gate[1][0]][gate[1][1]-1] == ' '){
            head_y = gate[1][0];
            head_x = gate[1][1] - 1;
            pass();
            direction = 'l';
          }
        }
        else if( direction == 'r'){
          if ( v[gate[1][0]][gate[1][1]+1] == ' '){
            head_y = gate[1][0];
            head_x = gate[1][1] + 1;
            pass();
            direction = 'r';
          }
          else if ( v[gate[1][0]+1][gate[1][1]] == ' '){
            head_y = gate[1][0] + 1;
            head_x = gate[1][1];
            pass();
            direction = 'd';
          }
          else if( v[gate[1][0]][gate[1][1]-1] == ' '){
            head_y = gate[1][0];
            head_x = gate[1][1] - 1;
            pass();
            direction = 'l';
          }
          else if ( v[gate[1][0]-1][gate[1][1]] == ' '){
           head_y = gate[1][0] - 1;
           head_x = gate[1][1];
           pass();
           direction = 'u';
          }
        }
        else if( direction == 'd'){
         if ( v[gate[1][0]+1][gate[1][1]] == ' '){
            head_y = gate[1][0] + 1;
            head_x = gate[1][1];
            pass();
            direction = 'd';
          }
          else if( v[gate[1][0]][gate[1][1]-1] == ' '){
            head_y = gate[1][0];
            head_x = gate[1][1] - 1;
            pass();
            direction = 'l';
          }
          else if ( v[gate[1][0]-1][gate[1][1]] == ' '){
           head_y = gate[1][0] - 1;
           head_x = gate[1][1];
           pass();
           direction = 'u';
          }
          else if ( v[gate[1][0]][gate[1][1]+1] == ' '){
            head_y = gate[1][0];
            head_x = gate[1][1] + 1;
            pass();
            direction = 'r';
          }
        }
      }
      else if(head_y==gate[1][0]&&head_x==gate[1][1]){
        count_gate++;
        if(gate[0][0]==0){
          head_y = gate[0][0] + 1;
          head_x = gate[0][1];
          pass();
          direction = 'd';

        }
        else if(gate[0][0]==24){
          head_y = gate[0][0] - 1;
          head_x = gate[0][1];
          pass();
          direction = 'u';

        }
        else if(gate[0][1]==24){
          head_y = gate[0][0];
          head_x = gate[0][1] - 1;
          pass();
          direction = 'l';

        }
        else if(gate[0][1]==0){
          head_y = gate[0][0];
          head_x = gate[0][1] + 1;
          pass();
          direction = 'r';
        }
        if( direction == 'l'){
          if( v[gate[0][0]][gate[0][1]-1] == ' '){
            head_y = gate[0][0];
            head_x = gate[0][1] - 1;
            pass();
            direction = 'l';
          }
          else if ( v[gate[0][0]-1][gate[0][1]] == ' '){
           head_y = gate[0][0] - 1;
           head_x = gate[0][1];
           pass();
           direction = 'u';
          }
          else if ( v[gate[0][0]][gate[0][1]+1] == ' '){
            head_y = gate[0][0];
            head_x = gate[0][1] + 1;
            pass();
            direction = 'r';
          }
          else if ( v[gate[0][0]+1][gate[0][1]] == ' '){
            head_y = gate[0][0] + 1;
            head_x = gate[0][1];
            pass();
            direction = 'd';
          }
        }
        else if( direction == 'u'){
          if ( v[gate[0][0]-1][gate[0][1]] == ' '){
           head_y = gate[0][0] - 1;
           head_x = gate[0][1];
           pass();
           direction = 'u';
          }
          else if ( v[gate[0][0]][gate[0][1]+1] == ' '){
            head_y = gate[0][0];
            head_x = gate[0][1] + 1;
            pass();
            direction = 'r';
          }
          else if ( v[gate[0][0]+1][gate[0][1]] == ' '){
            head_y = gate[0][0] + 1;
            head_x = gate[0][1];
            pass();
            direction = 'd';
          }
          else if( v[gate[0][0]][gate[0][1]-1] == ' '){
            head_y = gate[0][0];
            head_x = gate[0][1] - 1;
            pass();
            direction = 'l';
          }
        }
        else if( direction == 'r'){
          if ( v[gate[0][0]][gate[0][1]+1] == ' '){
            head_y = gate[0][0];
            head_x = gate[0][1] + 1;
            pass();
            direction = 'r';
          }
          else if ( v[gate[0][0]+1][gate[0][1]] == ' '){
            head_y = gate[0][0] + 1;
            head_x = gate[0][1];
            pass();
            direction = 'd';
          }
          else if( v[gate[0][0]][gate[0][1]-1] == ' '){
            head_y = gate[0][0];
            head_x = gate[0][1] - 1;
            pass();
            direction = 'l';
          }
          else if ( v[gate[0][0]-1][gate[0][1]] == ' '){
           head_y = gate[0][0] - 1;
           head_x = gate[0][1];
           pass();
           direction = 'u';
          }
        }
        else if( direction == 'd'){
          if ( v[gate[0][0]+1][gate[0][1]] == ' '){
            head_y = gate[0][0] + 1;
            head_x = gate[0][1];
            pass();
            direction = 'd';
          }
          else if( v[gate[0][0]][gate[0][1]-1] == ' '){
            head_y = gate[0][0];
            head_x = gate[0][1] - 1;
            pass();
            direction = 'l';
          }
          else if ( v[gate[0][0]-1][gate[0][1]] == ' '){
           head_y = gate[0][0] - 1;
           head_x = gate[0][1];
           pass();
           direction = 'u';
          }
          else if ( v[gate[0][0]][gate[0][1]+1] == ' '){
            head_y = gate[0][0];
            head_x = gate[0][1] + 1;
            pass();
            direction = 'r';
          }
        }
      }
  if(body_y.size()>max_length){
    body_y.pop_back();
    body_x.pop_back();
  }
}
void Snake::pass(){
  body_y.pop_front();
  body_x.pop_front();
  body_y.push_front(head_y);
  body_x.push_front(head_x);
}
void Snake::rebody(){
  body_y.push_front(head_y);
  body_y.pop_back();
  body_x.push_front(head_x);
  body_x.pop_back();
}

void Snake::Draw(char v[][25], int x, int y, char dir){
  int s = body_y.size();
  if ( s == 0){
    body_x.push_back(12);
    body_x.push_back(13);
    body_x.push_back(14);
    body_y.push_back(13);
    body_y.push_back(13);
    body_y.push_back(13);
  }
  for (int i=0; i<s; i++){
    if( i ==0){
      v[body_y[i]][body_x[i]] = '@';
    }
    else{
    v[body_y[i]][body_x[i]] = '0';
    }
  }
}
void Snake::countClear(){
  head_x = 13;
  head_y = 13;
  count_plu = 0;
  count_min = 0;
  count_gate = 0;
  direction = 'l';
  body_x.clear();
  body_y.clear();
}
