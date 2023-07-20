#include <simplecpp>
#include "stand.h"
#include "ball.h"

const float steptime = 0.02;
const int windowx = 2000;
const int windowy = 1250;

int main(){

    cout << "Mention your mode of playing. Press 'k' for keyboard or 'm' for mouse ... ";
    char choice;
    cin >> choice;

    cout << "Choose difficuty, 'e' for easy, 'm' for medium or 'h' for hard ... ";
    char diff;
    cin >> diff;

    if (diff == 'e'){
        standspeed = 50;
        ballvx = 2000;
    }
    else if (diff == 'm'){
        standspeed = 75;
        ballvx = 3000;
    }
    else if (diff == 'h'){
        standspeed = 100;
        ballvx = 4000;
    }
    if (choice == 'k'){
        ballvx /= 2;
    }

    initCanvas("Pong",windowx,windowy);

    Rectangle full(windowx/2,windowy/2,windowx,windowy);
    full.setFill(true);
    full.setColor(COLOR(80,80,255));

    Text start(windowx/2,windowy/2,"Welcome to the game of Pong! Use the bat to control the ball and score points.");
    wait(3);
    start.reset(windowx/2,windowy/2,"Enjoy the game ... ");
    wait(1);
    start.hide();

    Line mid(windowx/2, 0, windowx/2, windowy);
    mid.imprint();

    Stand s, c(50);

    Ball b;

    XEvent event;

    // Main game loop
    while (true)
    {
        if (checkEvent(event)){
            if (mouseButtonPressEvent(event)){
                if (choice == 'm'){
                    standy = event.xbutton.y;
                    s.Imprint();
                }
            }
            if (keyPressEvent(event)){
                if (choice == 'k'){
                    if (charFromEvent(event) == 'w'){
                        s.moveup();
                    }
                    else if (charFromEvent(event) == 's'){
                        s.movedown();
                    }
                }
                if (charFromEvent(event) == '\33'){
                    return 0;
                }
            }
        }
        if (b.vx < 0){
            if (c.get_y() - standheight / 2 > b.get_center_y()){
            c.moveup();
            }
            else if (c.get_y() + standheight / 2 < b.get_center_y()){
                c.movedown();
            }
        }

        if (b.get_center_x() - c.get_x() <= standwidth / 2  + b.get_radius() && b.get_center_x() - c.get_x() >= -standwidth / 2 - b.get_radius()
        && c.get_y() - b.get_center_y() <= b.get_radius() + standheight / 2 && c.get_y() - b.get_center_y() >= -b.get_radius() - standheight / 2){

            b.vx = -b.vx;
            if (choice == 'm'){
                b.vy = 5*(b.get_center_y() - c.get_y());
            }
            else if (choice == 'k'){
                b.vy = 2*(b.get_center_y() - c.get_y());
            }         
        }

        if (b.get_center_x() - s.get_x() <= standwidth / 2  + b.get_radius() && b.get_center_x() - s.get_x() >= -standwidth / 2 - b.get_radius()
        && s.get_y() - b.get_center_y() <= b.get_radius() + standheight / 2 && s.get_y() - b.get_center_y() >= -b.get_radius() - standheight / 2){
            
            b.vx = -b.vx;
            b.vy = 25*(b.get_center_y() - s.get_y());
        }

        if (b.get_center_x() <= 0){
            s.score ++;
            cout << "Current scores are " << endl << "user : " << s.score << " computer : " << c.score << endl;
            if (s.score == 10){
                Text win(windowx/2,windowy/2,"You Win !");
                win.imprint();
                wait(3);
                return 0;
            }
            wait(3);
            b.serve();
        }

        if (b.get_center_x() >= windowx){
            c.score ++;
            cout << "Current scores are " << endl << "user : " << s.score << " computer : " << c.score << endl;
            if (c.score == 10){
                Text lose(windowx/2,windowy/2,"You Lose !");
                lose.imprint();
                wait(3);
                return 0;
            }
            wait(3);
            b.serve();
        }

        wait(steptime);

        b.nextStep(steptime);
    }
}
