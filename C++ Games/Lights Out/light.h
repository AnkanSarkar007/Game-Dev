#include <simplecpp>

class light{

private:
    Circle circle;  // the circle representing the light
    bool state;

public:
    light(int cx, int cy){

        circle = Circle(cx, cy, 100);
        state = rand() % 2;
        if (state){
            circle.setColor(COLOR(255,255,0));
            circle.setFill(true);
        }
        else{
            circle.setColor(COLOR(0,255,0));
            circle.setFill(true);
        }
    }
    light(int cx, int cy, bool cond){

        circle = Circle(cx, cy, 100);
        state = cond;
        if (state){
            circle.setColor(COLOR(255,255,0));
            circle.setFill(true);
        }
        else{
            circle.setColor(COLOR(0,255,0));
            circle.setFill(true);
        }
    }
    void toggle(){
        state = !state;
        if (state){
            circle.setColor(COLOR(255,255,0));
            circle.setFill(true);
        }
        else{
            circle.setColor(COLOR(0,255,0));
            circle.setFill(true);
        }
    }
    double get_radius(){

        // return the radius of the light
        return circle.getRadius();
    }
    double get_center_x(){

        // return the x coordinate of the center of the light
        return circle.getX();
    }
    double get_center_y(){

        // return the y coordinate of the center of the light
        return circle.getY();
    }
    bool get_state(){

        // return the state of the light
        return state;
    }
};