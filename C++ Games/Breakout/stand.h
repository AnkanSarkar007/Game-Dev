#include <simplecpp>

const int standwidth = 250;
const int standheight = 10;
const int standspeed = 100;
int standx = 1200;
const int standy = 1200;

class Stand{
private:
    Rectangle rectangle;
    double speed;
    Color color;
public:
    Stand(double cx_=standx, double cy_=standy, double speed_=standspeed, Color color_=COLOR(255, 0, 0))
    {
        // Stand constructor
        color = color_;
        speed = speed_;
        rectangle = Rectangle(cx_,cy_,standwidth,standheight);
        rectangle.setColor(color);
        rectangle.setFill(true);
    }
    void moveleft(){
        if (standx - standwidth / 2 <= 0){
            return;
        }
        rectangle.move(-standspeed,0);
        standx -= standspeed;
        return;
    }

    void moveright(){
        if (standx + standwidth / 2 >= 2000){
            return;
        }
        rectangle.move(standspeed,0);
        standx += standspeed;
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
};