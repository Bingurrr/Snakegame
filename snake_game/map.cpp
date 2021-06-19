#include <fstream>
#include <iostream>
#include <ncurses.h>
#include <random>
#include <vector>
#include <string>
#include <cstring>
#include <unistd.h>
#include "map.h"
#include "snake.h"
#include "controll.h"
#include "manager.h"
using namespace std;

Snake s;
Controll c;
Manager manager;
deque<int> gate_x;
deque<int> gate_y;


int j = 0;
int wallcount =0;
int item_px, item_py = 0;
int item_mx, item_my = 0;
int potal_x, potal_y = 0;
int potal_x2, potal_y2 = 0;
int score = 0;
int plus_time, minus_time = 0;
int potal_time = 0;
int goal_length= 4;
int goal_plu = 2;
int goal_min = 1;
int goal_gate = 1;
char len_ch = ' ';
char plu_ch = ' ';
char min_ch = ' ';
char gate_ch = ' ';
char sp[2];


void Map::render(){
  initscr();
  resize_term(60, 100);
  start_color();
  init_pair(1, COLOR_RED, COLOR_WHITE);
  init_pair(2, COLOR_RED, COLOR_GREEN);
  init_pair(3, COLOR_BLUE, COLOR_WHITE);

  attron(COLOR_PAIR(1));
  border('+', '+', '+', '+', '*', '*', '*', '*');
  attroff(COLOR_PAIR(1));
  refresh();
  attron(COLOR_PAIR(2));
  mvprintw(2, 9, "<<snake game>>");
  attroff(COLOR_PAIR(2));


  WINDOW *gamebox; 
  gamebox = newwin(25, 25, 3, 3);
  wbkgd(gamebox, COLOR_PAIR(3));
  wattron(gamebox, COLOR_PAIR(3));

  WINDOW *scoreBox;
  scoreBox = newwin(10, 15, 3, 35);

  WINDOW *missionBox;
  missionBox = newwin(10, 15 ,14,35);
  upDate();

  box(scoreBox, 0, 0); 
  mvwprintw(scoreBox, 1, 1, "Score Borad");
  mvwprintw(scoreBox, 3, 1, " %d / %d",  s.body_y.size(), s.max_length);
  mvwprintw(scoreBox, 4, 1, " + : %d", s.count_plu);
  mvwprintw(scoreBox, 5, 1, " - : %d", s.count_min);
  mvwprintw(scoreBox, 6, 1, " G : %d", s.count_gate);

  box(missionBox, 0, 0);
  mvwprintw(missionBox, 1, 1, "Mission Board");
  mvwprintw(missionBox, 3, 1, " L : %d (%c)", goal_length, len_ch );
  mvwprintw(missionBox, 4, 1, " + : %d (%c)", goal_plu, plu_ch);
  mvwprintw(missionBox, 5, 1, " - : %d (%c)", goal_min, min_ch);
  mvwprintw(missionBox, 6, 1, " G : %d (%c)", goal_gate, gate_ch);

  for (int i = 0; i < 25; i++){
    for (int j = 0; j < 25; j++){
        wprintw(gamebox, "%c", v[i][j]);
    }
  }
  wrefresh(gamebox);
  wrefresh(scoreBox);
  wrefresh(missionBox);
  delwin(missionBox);
  delwin(scoreBox);
  delwin(gamebox);

}


void Map::upDate(){
  char a = s.direction;
  char b = c.controll(a);
  s.Move(b, v, gate);
  if(v[s.head_y][s.head_x] == '+'||v[s.head_y][s.head_x] =='0'|| b=='f' ){
    md = 'f';
  }

  for (int i = 0; i < 25; i++){
    for (int j = 0; j < 25; j++){
      if (v[i][j] == '@')
        v[i][j] = ' ';
      else if (v[i][j] == '0')
        v[i][j] = ' ';
    }
  }
  s.Draw(v, s.head_x, s.head_y, a);
  int length = s.body_y.size();
  if(length<3){
    md = 'f';
  }
  if (s.count_plu>=goal_plu){
    plu_ch = 'v';
  }
  else{
    plu_ch = ' ';
  }
  if(s.count_min>=goal_min){
    min_ch = 'v';
  }
  else{
    min_ch = ' ';
  }
  if(s.count_gate>=goal_gate){
    gate_ch = 'v';
  }
  else{
    gate_ch = ' ';
  }
  if(length>=goal_length){
    len_ch = 'v';
  }
  else{
    len_ch = ' ';
  }
  if (s.count_plu>=goal_plu && s.count_min>=goal_min && s.count_gate>=goal_gate &&length>=goal_length){
    md = 's';
  }

  j++;
  plus_item();
  minus_item();
  potal();

  plus_time++;
  minus_time++;
  potal_time++;
}
void Map::failed(){
  init_pair(1, COLOR_RED, COLOR_YELLOW);
  attron(COLOR_PAIR(1));
  mvprintw(15, 10, "<Game Over>");
  attroff(COLOR_PAIR(1));
  refresh();
}

void Map::success(){
  mvprintw(11, 10, "<Game success>");
  refresh();
}


void Map::getMap(int stage){
  int i = 0;
  ifstream infile;
  if (stage ==1){
   infile.open("map1.txt");
  }
  else  if (stage ==2){
    infile.open("map2.txt");
    goal_length= 5;
    goal_plu = 4;
    goal_min = 0;
    goal_gate = 1;
  }
  else  if (stage ==3){
    infile.open("map3.txt");
    goal_length= 5;
    goal_plu = 3;
    goal_min = 0;
    goal_gate = 1;
  }
  else  if (stage ==4){
    infile.open("map4.txt");
    goal_length= 6;
    goal_plu = 3;
    goal_min = 0;
    goal_gate = 1;
  }
  char buffer[30];
  while (infile.getline(buffer, 30))
  {
    for (int j = 0; j < strlen(buffer); j++)
    {
      if (buffer[j] == '2'){
          v[i][j] = '*';
      }
      else if (buffer[j] == '1'){
          v[i][j] = '+';
          gate_y.push_back(i);
          gate_x.push_back(j);
      }
      else{
          v[i][j] = ' ';
      }
    }
    i++;
  }
  infile.close();
}

void Map::plus_item(){
  if (plus_time == 30){
    if (item_px > 0 || item_py > 0){
      v[item_py][item_px] = ' ';
    }
    do{
    time_t t1 = time(NULL);
    srand(t1);
    item_px = rand() % 23 + 1;
    time_t t2 = time(NULL);
    srand(t2);
    item_py = rand() % 23 + 1;
    }while(v[item_py][item_px] != ' ');
    v[item_py][item_px] = 'G';
    plus_time = 0;
  }
}

void Map::minus_item(){
  if (minus_time == 40){
    if (item_mx > 0 || item_my > 0){
      v[item_my][item_mx] = ' ';
    }
    do{
    time_t t3 = time(NULL);
    srand(t3);
    item_mx = rand() % 23 + 1;
    time_t t4 = time(NULL);
    srand(t4);
    item_my = rand() % 23 + 1;
    }while (v[item_my][item_mx] != ' ');
    v[item_mx][item_my] = 'S';
    minus_time = 0;
  }
}
void Map::potal_throw(){
  if(v[s.head_y][s.head_x] == '#'){
    potal_time -= s.body_y.size();
  }
}
void Map::potal(){
  potal_throw();
  if(potal_time == 50){
    srand((unsigned int)time(NULL));
    if (item_mx > 0 || item_my > 0){
      v[potal_y][potal_x] = '+';
      v[potal_y2][potal_x2] = '+';
    }
    time_t tp1 = time(NULL);
    srand(tp1);
    int tmp1 = rand() % gate_x.size();
    potal_x = gate_x[tmp1];
    potal_y = gate_y[tmp1];
    v[potal_y][potal_x] = '#';

    int tmp2 = rand() % gate_x.size();
    potal_x2 = gate_x[tmp2];
    potal_y2 = gate_y[tmp2];
    v[potal_y2][potal_x2] = '#';

    gate[0][1] = potal_x;
    gate[0][0] = potal_y;
    gate[1][1] = potal_x2;
    gate[1][0] = potal_y2;
    potal_time = 0;

  }
}

void Map::clearMap(){
 s.countClear();
 md ='l';
 gate[0][0] = 0; gate[0][1] = 0;
 gate[1][0] = 0; gate[1][1] = 0;
 item_mx=0; item_my=0;
 item_px=0; item_py=0;
 j = 0;
 potal_x=0; potal_y = 0;
 potal_x2=0; potal_y2 = 0;
 score = 0;
 plus_time=0; minus_time = 0;
 potal_time = 0;
}
