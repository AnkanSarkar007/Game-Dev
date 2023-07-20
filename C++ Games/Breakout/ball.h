#include <simplecpp>

const int ballx = 1000;
const int bally = 1000;
const int ballvx = 500;
const int ballvy = 500;

class Ball
{
private:
    Circle circle;  // the circle representing the bubble
    Color color;    // color of the bubble

public:
    double vx, vy;  // velocity in x and y direction
    Ball(double cx_=ballx, double cy_=bally, double vx_=ballvx, double vy_=ballvy, Color color_=COLOR(255, 255, 255))
    {
        // Ball constructor
        color = color_;
        circle = Circle(cx_, cy_, 20);
        circle.setColor(color);
        circle.setFill(true);

        vx = vx_;
        vy = vy_;
    }
    void nextStep(double t)
    {
        // move the ball
        double new_x = circle.getX() + vx*t;
        double new_y = circle.getY() + vy*t;

        if ((vx < 0 && new_x < (0 + circle.getRadius())) // bounce along X direction at left border
            ||
            (vx > 0 && new_x > (2000 - circle.getRadius()))) // bounce along X direction at right border
        {

            vx = -vx;
            new_x = circle.getX() + vx*t;

        }

        if (vy < 0 && new_y < (0 + circle.getRadius())) // bounce along Y direction at top border
        {

            vy = -vy;
            new_y = circle.getY() + vy*t;

        }

        circle.moveTo(new_x, new_y);
    }
    double get_radius()
    {
        // return the radius of the ball
        return circle.getRadius();
    }

    double get_center_x()
    {
        // return the x coordinate of the center of the ball
        return circle.getX();
    }

    double get_center_y()
    {
        // return the y coordinate of the center of the ball
        return circle.getY();
    }

    double get_vx()
    {
        // return the x velocity of the ball
        return vx;
    }
    double get_vy()
    {
        // return the y velocity of the ball
        return vy;
    }
};