#include <ncurses.h>
#include <deque>
#include <vector>

using namespace std;
class Snake
{
public:
    int head_x = 13;
    int head_y = 13;
    int count_plu = 0;
    int count_min = 0;
    int count_gate = 0;
    int max_length=10;
    deque<int> body_x;
    deque<int> body_y;
    char direction = 'l';
    void Draw(char v[][25], int x, int y, char dir);

    void rebody();
    void pass();
    void Move(char dir, char v[][25], int gate[][2]);
    void countClear();
};
