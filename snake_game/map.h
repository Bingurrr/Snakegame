class Map
{
public:
    char md ='l';
    char v[25][25];
    int gate[2][2];
    int item_sx;
    int item_sy;
    int item_gx;
    int item_gy;
    void getMap(int stage);
    void render();
    void upDate();
    void failed();
    void makeGate();
    void plus_item();
    void minus_item();
    void potal();
    void success();
    void clearMap();
    void potal_throw();
};
