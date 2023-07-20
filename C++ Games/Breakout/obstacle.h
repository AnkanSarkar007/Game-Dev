#include <simplecpp>

int obswidth = 125;
int obsheight = 100;

class Obstacle{
public:
    Rectangle rectangle;
    Color color;
    Obstacle(double cx_, double cy_, double width = obswidth, double height = obsheight, Color color_ = COLOR(255,255,255))
    {
        // Stand constructor
        color = color_;
        rectangle = Rectangle(cx_,cy_,width,height);
        rectangle.setColor(color);
        rectangle.setFill(true);
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
};
