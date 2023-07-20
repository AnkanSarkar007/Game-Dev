#include <simplecpp>
#include "stand.h"
#include "ball.h"
#include "obstacle.h"

const float steptime = 0.02;
const int windowx = 2000;
const int windowy = 1250;

vector<Obstacle> create_obstacles()
{
    // create initial obstacless in the game
    vector<Obstacle> obs;
    
    for (int i = 0; i < 16; i++){
        for (int j = 0; j < 6; j++){
            obs.push_back(Obstacle((i + 0.5)*obswidth, (j + 0.5)*obsheight, obswidth, obsheight, COLOR(15 * i,42 * j,255 - 7 * i - 22 * j)));
        }
    }

    return obs;
}
vector<Obstacle> create_tough_obstacles()
{
    // create initial tough obstacless in the game
    vector<Obstacle> tough;
    
    for (int i = 0; i < 16; i += 2){
        tough.push_back(Obstacle((i + 0.5)*obswidth, (6 + 0.5)*obsheight, obswidth, obsheight, COLOR(0,0,0)));
    }

    return tough;
}
vector<Obstacle> create_invisible_obstacles()
{
    // create initial tough obstacless in the game
    vector<Obstacle> invi;
    
    for (int i = 1; i < 16; i += 2){
        invi.push_back(Obstacle((i + 0.5)*obswidth, (6 + 0.5)*obsheight, obswidth, obsheight, COLOR(80,80,80)));
    }

    return invi;
}
vector<Obstacle> create_border()
{
    // create saviours in the game
    vector<Obstacle> bor;
    
    for (int i = 0; i < 4; i++){
        bor.push_back(Obstacle((i + 0.5)*500, 1250, 500, 20));
    }

    return bor;
}


int main(){
    initCanvas("Breakout",windowx,windowy);
    Rectangle full(windowx/2,windowy/2,windowx,windowy);
    full.setFill(true);
    full.setColor(COLOR(80,80,80));

    Text start(windowx/2,windowy/2,"Welcome to the game of Breakout! Destroy the bricks with the ball and use the bat to control the same.");
    wait(3);
    start.reset(windowx/2,windowy/2,"The white line at the bottom acts as a shield. Beware! Some bricks are not so easy to break.");
    wait(3);
    start.reset(windowx/2,windowy/2,"Enjoy the game ... ");
    wait(1);
    start.hide();

    Stand s;

    Ball b;

    // Initialize the obstacles
    vector<Obstacle> obs = create_obstacles();
    vector<Obstacle> bor = create_border();
    vector<Obstacle> tough = create_tough_obstacles();
    vector<Obstacle> invi = create_invisible_obstacles();

    XEvent event;

    // Main game loop
    while (true)
    {
        bool pendingEvent = checkEvent(event);
        if (pendingEvent)
        {
            // Get the key pressed
            char c = charFromEvent(event);

            // Update the shooter
            if(c == 'd')
                s.moveright();
            else if(c == 'a')
                s.moveleft();
            else if(c == '\33')
                return 0;
        }

        if (b.get_center_x() - s.get_x() <= standwidth / 2 && b.get_center_x() - s.get_x() >= -standwidth / 2 
        && s.get_y() - b.get_center_y() <= b.get_radius() + standheight / 2 && s.get_y() - b.get_center_y() >= -b.get_radius() - standheight / 2){
            
            if (b.vy > 0){
                b.vy = -b.vy;
                b.vx = 6*(b.get_center_x() - s.get_x());
            }
        }
        if (b.get_center_y() >= windowy){
            Text lose(windowx/2,windowy/2,"You Lose !");
            lose.imprint();
            wait(3);
            return 0;
        }

        for (unsigned int j = 0; j < obs.size(); j++){
            if (obs[j].get_x() - b.get_center_x() <= obs[j].get_width() / 2  + b.get_radius() && obs[j].get_x() - b.get_center_x() >= -obs[j].get_width() / 2 - b.get_radius()
            && obs[j].get_y() - b.get_center_y() >= -obs[j].get_height() / 2 - b.get_radius() && obs[j].get_y() - b.get_center_y() <= (obs[j].get_height() / 2 + b.get_radius())){

                if (obs[j].get_x() - b.get_center_x() <= obs[j].get_width() / 2 + b.get_radius() && obs[j].get_x() - b.get_center_x() >= obs[j].get_width() / 2 + b.get_radius() - 10){
                    b.vx = -b.vx;
                    obs.erase(obs.begin() + j,obs.begin() + j + 1);
                }
                else if (obs[j].get_x() - b.get_center_x() >= -obs[j].get_width() / 2 - b.get_radius() && obs[j].get_x() - b.get_center_x() <= -obs[j].get_width() / 2 - b.get_radius() + 10){
                    b.vx = -b.vx;
                    obs.erase(obs.begin() + j,obs.begin() + j + 1);
                }
                else if (obs[j].get_y() - b.get_center_y() >= -obs[j].get_height() / 2 - b.get_radius() && obs[j].get_y() - b.get_center_y() <= -obs[j].get_height() / 2 - b.get_radius() + 10){
                    b.vy = -b.vy;
                    obs.erase(obs.begin() + j,obs.begin() + j + 1);
                }
                else if (obs[j].get_y() - b.get_center_y() <= obs[j].get_height() / 2 + b.get_radius() && obs[j].get_y() - b.get_center_y() >= obs[j].get_height() / 2 + b.get_radius() - 10){
                    b.vy = -b.vy;
                    obs.erase(obs.begin() + j,obs.begin() + j + 1);
                }

            }
        }

        for (unsigned int j = 0; j < tough.size(); j++){
            if (tough[j].get_x() - b.get_center_x() <= tough[j].get_width() / 2  + b.get_radius() && tough[j].get_x() - b.get_center_x() >= -tough[j].get_width() / 2 - b.get_radius()
            && tough[j].get_y() - b.get_center_y() >= -tough[j].get_height() / 2 - b.get_radius() && tough[j].get_y() - b.get_center_y() <= (tough[j].get_height() / 2 + b.get_radius())){

                if (tough[j].get_x() - b.get_center_x() <= tough[j].get_width() / 2 + b.get_radius() && tough[j].get_x() - b.get_center_x() >= tough[j].get_width() / 2 + b.get_radius() - 10){
                    b.vx = -b.vx;
                }
                else if (tough[j].get_x() - b.get_center_x() >= -tough[j].get_width() / 2 - b.get_radius() && tough[j].get_x() - b.get_center_x() <= -tough[j].get_width() / 2 - b.get_radius() + 10){
                    b.vx = -b.vx;
                }
                else if (tough[j].get_y() - b.get_center_y() >= -tough[j].get_height() / 2 - b.get_radius() && tough[j].get_y() - b.get_center_y() <= -tough[j].get_height() / 2 - b.get_radius() + 10){
                    b.vy = -b.vy;
                }
                else if (tough[j].get_y() - b.get_center_y() <= tough[j].get_height() / 2 + b.get_radius() && tough[j].get_y() - b.get_center_y() >= tough[j].get_height() / 2 + b.get_radius() - 10){
                    b.vy = -b.vy;
                    tough.erase(tough.begin() + j,tough.begin() + j + 1);
                }

            }
        }

        for (unsigned int j = 0; j < invi.size(); j++){
            if (invi[j].get_x() - b.get_center_x() <= invi[j].get_width() / 2  + b.get_radius() && invi[j].get_x() - b.get_center_x() >= -invi[j].get_width() / 2 - b.get_radius()
            && invi[j].get_y() - b.get_center_y() >= -invi[j].get_height() / 2 - b.get_radius() && invi[j].get_y() - b.get_center_y() <= (invi[j].get_height() / 2 + b.get_radius())){

                if (invi[j].get_x() - b.get_center_x() <= invi[j].get_width() / 2 + b.get_radius() && invi[j].get_x() - b.get_center_x() >= invi[j].get_width() / 2 + b.get_radius() - 10){
                    b.vx = -b.vx;
                    obs.push_back(Obstacle(invi[j].get_x(), invi[j].get_y(), obswidth, obsheight));
                    invi.erase(invi.begin() + j,invi.begin() + j + 1);
                    
                }
                else if (invi[j].get_x() - b.get_center_x() >= -invi[j].get_width() / 2 - b.get_radius() && invi[j].get_x() - b.get_center_x() <= -invi[j].get_width() / 2 - b.get_radius() + 10){
                    b.vx = -b.vx;
                    obs.push_back(Obstacle(invi[j].get_x(), invi[j].get_y(), obswidth, obsheight));
                    invi.erase(invi.begin() + j,invi.begin() + j + 1);
                }
                else if (invi[j].get_y() - b.get_center_y() >= -invi[j].get_height() / 2 - b.get_radius() && invi[j].get_y() - b.get_center_y() <= -invi[j].get_height() / 2 - b.get_radius() + 10){
                    b.vy = -b.vy;
                    obs.push_back(Obstacle(invi[j].get_x(), invi[j].get_y(), obswidth, obsheight));
                    invi.erase(invi.begin() + j,invi.begin() + j + 1);
                }
                else if (invi[j].get_y() - b.get_center_y() <= invi[j].get_height() / 2 + b.get_radius() && invi[j].get_y() - b.get_center_y() >= invi[j].get_height() / 2 + b.get_radius() - 10){
                    b.vy = -b.vy;
                    obs.push_back(Obstacle(invi[j].get_x(), invi[j].get_y(), obswidth, obsheight));
                    invi.erase(invi.begin() + j,invi.begin() + j + 1);
                }

            }
        }

        if (obs.size() == 0 && tough.size() == 0 && invi.size() == 0){
                    Text win(windowx/2,windowy/2,"You Win !");
                    win.imprint();
                    wait(3);
                    return 0;
                }

        for (unsigned int j = 0; j < bor.size(); j++){
            if (bor[j].get_x() - b.get_center_x() <= bor[j].get_width() / 2  + b.get_radius() && bor[j].get_x() - b.get_center_x() >= -bor[j].get_width() / 2 - b.get_radius()
            && bor[j].get_y() - b.get_center_y() >= -bor[j].get_height() / 2 - b.get_radius() && bor[j].get_y() - b.get_center_y() <= (bor[j].get_height() / 2 + b.get_radius())){

                if (bor[j].get_x() - b.get_center_x() <= bor[j].get_width() / 2 + b.get_radius() && bor[j].get_x() - b.get_center_x() >= bor[j].get_width() / 2 + b.get_radius() - 10){
                    b.vx = -b.vx;
                    bor.erase(bor.begin() + j,bor.begin() + j + 1);
                }
                else if (bor[j].get_x() - b.get_center_x() >= -bor[j].get_width() / 2 - b.get_radius() && bor[j].get_x() - b.get_center_x() <= -bor[j].get_width() / 2 - b.get_radius() + 10){
                    b.vx = -b.vx;
                    bor.erase(bor.begin() + j,bor.begin() + j + 1);
                }
                else if (bor[j].get_y() - b.get_center_y() >= -bor[j].get_height() / 2 - b.get_radius() && bor[j].get_y() - b.get_center_y() <= -bor[j].get_height() / 2 - b.get_radius() + 10){
                    b.vy = -b.vy;
                    bor.erase(bor.begin() + j,bor.begin() + j + 1);
                }
                else if (bor[j].get_y() - b.get_center_y() <= bor[j].get_height() / 2 + b.get_radius() && bor[j].get_y() - b.get_center_y() >= bor[j].get_height() / 2 + b.get_radius() - 10){
                    b.vy = -b.vy;
                    bor.erase(bor.begin() + j,bor.begin() + j + 1);
                }

            }
        }
        wait(steptime);

        b.nextStep(steptime);
    }
}
