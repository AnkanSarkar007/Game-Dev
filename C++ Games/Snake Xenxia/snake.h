#include<simplecpp>

int gridsep, xinit = 25, yinit = 15, npts;
const int length = 103;

struct Snake{
    Circle body[length];
    int headindex;
    char dir;
    int l;
    Snake(){
        headindex = 0;
        l = 3;
        for (int i = 0; i < length; i++){
            body[i].setFill(true);
            body[i].setColor(COLOR(0,255,0));
        }
        for (int i = 0; i < l; i++){
            body[i].reset((xinit + 0.5 + i)*gridsep,(yinit + 0.5)*gridsep,0.5*gridsep);
        }
        dir = 'a';
    }
    void move(){
        move(dir);
    }
    void move(char command){
        if (!(command == 'w' || command == 'a' || command == 'd' || command == 's')
            || (dir == 'w' && command == 's') || (dir == 's' && command == 'w')
            || (dir == 'a' && command == 'd') || (dir == 'd' && command == 'a')){
            command = dir;
        }
        int newhead = (headindex + l - 1) % l;
        body[newhead] = body[headindex];
        headindex = newhead;

        if (command == 'a') body[headindex].move(-gridsep,0);
        else if (command == 'd') body[headindex].move(gridsep,0);
        else if (command == 'w') body[headindex].move(0,-gridsep);
        else if (command == 's') body[headindex].move(0,gridsep);

        dir = command;

        if (body[headindex].getX() < gridsep / 2 && dir == 'a') body[headindex].move(gridsep*npts,0);
        else if (body[headindex].getX() > gridsep*npts - gridsep / 2 && dir == 'd') body[headindex].move(-gridsep*npts,0);
        else if (body[headindex].getY() < gridsep / 2 && dir == 'w') body[headindex].move(0,gridsep*npts);
        else if (body[headindex].getY() > gridsep*npts - gridsep / 2 && dir == 's') body[headindex].move(0,-gridsep*npts);
    }
    void increment(){
        body[l].reset(2*body[l-1].getX()-body[l-2].getX(),2*body[l-1].getY()-body[l-2].getY(),0.5*gridsep);
        l++;
    }
};
