#include<simplecpp>
#include<cstdlib>

struct Food{
    Rectangle item;
    Rectangle bon;
    Food(){
        int x = rand() % npts;
        int y = rand() % npts;
        item.reset((x + 0.5)*gridsep,(y + 0.5)*gridsep,gridsep,gridsep);
        item.setFill(true);
        item.setColor(COLOR(255,0,0));
        bon.reset(1000,1000,1,1);
        bon.setFill(true);
        bon.setColor(COLOR(0,0,255));
    }
    void generate(){
            int x = rand() % npts;
            int y = rand() % npts;
            item.reset((x + 0.5)*gridsep,(y + 0.5)*gridsep,gridsep,gridsep);
    }
    void bonusstart(){
        int x1 = 1 + rand() % (npts-2);
        int y1 = 1 + rand() % (npts-2);
        bon.reset((x1 + 0.5)*gridsep,(y1 + 0.5)*gridsep,3*gridsep,3*gridsep);
    }
    void bonusend(){
        bon.reset(1000,1000,1,1);
    }
};
