#include <simplecpp>

const int standwidth = 10;
const int standheight = 250;
int standspeed = 50;
const int standx = 1950;
int standy = 625;

class Stand{

private:
    
    Rectangle rectangle;
    double speed;
    Color color;

public:
    int score;
    Stand(double cx_=standx, double cy_=standy, double speed_=standspeed, Color color_=COLOR(255, 0, 0))
    {
        // Stand constructor
        color = color_;
        speed = speed_;
        rectangle = Rectangle(cx_,cy_,standwidth,standheight);
        rectangle.setColor(color);
        rectangle.setFill(true);
        score = 0;
    }
    void moveup(){
        rectangle.move(0,-standspeed);
        standy -= standspeed;
        return;
    }

    void movedown(){
        rectangle.move(0,standspeed);
        standy += standspeed;
        return;
    }

    double get_width()
    {
        // return the width of the stand
        return rectangle.getWidth();
    }

    double get_height()
    {
        // return the height of the stand
        return rectangle.getHeight();
    }

    double get_x()
    {
        // return the x coordinate of the center of the stand
        return rectangle.getX();
    }

    double get_y()
    {
        // return the y coordinate of the center of the stand
        return rectangle.getY();
    }

    double get_speed()
    {
        // return the speed of the stand
        return speed;
    }

    void Imprint(){
        rectangle.reset(standx,standy,standwidth,standheight);
    }
};