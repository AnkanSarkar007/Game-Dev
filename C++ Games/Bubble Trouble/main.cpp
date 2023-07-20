#include <simplecpp>
#include "shooter.h"
#include "bubble.h"

/* Simulation Vars */
const double STEP_TIME = 0.02;

/* Game Vars */
const int PLAY_Y_HEIGHT = 1200;
const int TOP_MARGIN = 20;
const int BOTTOM_MARGIN = (PLAY_Y_HEIGHT+TOP_MARGIN);


void move_bullets(vector<Bullet> &bullets){
    // move all bullets
    for(unsigned int i=0; i<bullets.size(); i++){
        if(!bullets[i].nextStep(STEP_TIME)){
            bullets.erase(bullets.begin()+i);
        }
    }
}

void move_bubbles(vector<Bubble> &bubbles){
    // move all bubbles
    for (unsigned int i=0; i < bubbles.size(); i++)
    {
        bubbles[i].nextStep(STEP_TIME);
    }
}

vector<Bubble> create_bubbles()
{
    // create initial bubbles in the game
    vector<Bubble> bubbles;
    bubbles.push_back(Bubble(3*WINDOW_X/4.0, BUBBLE_START_Y/2, 4 * BUBBLE_DEFAULT_RADIUS, BUBBLE_DEFAULT_VX, BUBBLE_DEFAULT_VY));
    bubbles.push_back(Bubble(WINDOW_X/4.0, BUBBLE_START_Y/2, 4 * BUBBLE_DEFAULT_RADIUS, -BUBBLE_DEFAULT_VX, BUBBLE_DEFAULT_VY));
    bubbles.push_back(Bubble(WINDOW_X/4.0, BUBBLE_START_Y, 2 * BUBBLE_DEFAULT_RADIUS, BUBBLE_DEFAULT_VX, -BUBBLE_DEFAULT_VY));
    bubbles.push_back(Bubble(3*WINDOW_X/4.0, BUBBLE_START_Y, 2 * BUBBLE_DEFAULT_RADIUS, -BUBBLE_DEFAULT_VX, -BUBBLE_DEFAULT_VY));

    // initially, 4 bubbles are created with different sizes and at different location with different initial velocities

    return bubbles;
}

int main()
{
    cout << "Select level, possible options are 1,2,3,4,5 ...";
    int lvl;
    cin >> lvl;
    int hmax = 160 - 20 * lvl;
    int tmax = 50 - 5 * lvl;
    int fmax = 30 + 5 * abs(lvl - 3);
    BUBBLE_DEFAULT_VX = 350 + 50*lvl;
    BUBBLE_DEFAULT_VY = 350 + 50*lvl;
    gravity = 17 + 3 * lvl;

    initCanvas("Bubble Trouble", WINDOW_X, WINDOW_Y);

    Rectangle border (WINDOW_X/2, WINDOW_Y/2, WINDOW_X, WINDOW_Y);
    border.setFill(true);
    border.setColor(COLOR(120,120,120));
    Line b1(0, PLAY_Y_HEIGHT, WINDOW_X, PLAY_Y_HEIGHT);
    b1.setColor(COLOR(0, 0, 255));

    int H = hmax; // 'H' represents health
    Text health(WINDOW_X - 1600,20,"Health:    / "); // health is initially set to hmax
    Text health2(WINDOW_X - 1600 + textWidth("XXXXXXX"),20,hmax);
    Text health1(WINDOW_X - 1600 + textWidth("XXX"),20,H); // the letter X is included just to adjust spacing

    int S = 0; // 'S' represents score
    Text score(WINDOW_X - 1200,20,"Score: ");
    Text score1(WINDOW_X - 1200 + textWidth("XXXXX"),20,S); // XXX is included just for spacing

    int T = 0; // 'T' represents time
    Text time(WINDOW_X - 800,20,"Time:    / "); // max time allowed is tmax seconds
    Text time2(WINDOW_X - 800 + textWidth("XXXXXX"),20,tmax);
    Text time1(WINDOW_X - 800 + textWidth("X"),20,T); // X is included just for spacing

    int F = fmax; // 'T' represents time
    Text fire(WINDOW_X - 400,20,"Bullets:     / "); // max bullets allotted is 30
    Text fire2(WINDOW_X - 400 + textWidth("XXXXXXXXX"),20,fmax);
    Text fire1(WINDOW_X - 400 + textWidth("XXX"),20,F); // X is included just for spacing

    // Intialize the shooter
    Shooter shooter(SHOOTER_START_X, SHOOTER_START_Y, SHOOTER_VX);

    // Initialize the bubbles
    vector<Bubble> bubbles = create_bubbles();

    // Initialize the bullets (empty)
    vector<Bullet> bullets;

    XEvent event;

    // Main game loop
    while (true)
    {
        bool pendingEvent = checkEvent(event);
        if (pendingEvent)
        {
            char c = charFromEvent(event);
            // Update the shooter
            if(c == 'a')
                shooter.move(STEP_TIME, true);
            else if(c == 'd')
                shooter.move(STEP_TIME, false);
            else if(c == 'w'){
                bullets.push_back(shooter.shoot());
                F--;
                fire1.reset(WINDOW_X - 400 + textWidth("XXX"),20,F);
                if (F == 0){
                    Text t(WINDOW_X - 1000,PLAY_Y_HEIGHT + 20,"GAME OVER! NO BULLETS REMAIN");
                    t.imprint();
                    wait(3);
                    return 0;
                }
            }
            else if(c == '\33')
                return 0;
        }

        // Update the bubbles
        move_bubbles(bubbles);

        // Update the bullets
        move_bullets(bullets);

        wait(STEP_TIME);

        for(unsigned int i=0; i<bullets.size(); i++){
            for (unsigned int j=0; j < bubbles.size(); j++){
                if (bubbles[j].get_radius() > BUBBLE_RADIUS_THRESHOLD){
                    if ((((bubbles[j].get_center_x() - bullets[i].get_center_x()) <= bubbles[j].get_radius() + bullets[i].get_width() / 2) && ((bubbles[j].get_center_x() - bullets[i].get_center_x()) >= -(bubbles[j].get_radius() + bullets[i].get_width() / 2)))
                        &&
                        (((bubbles[j].get_center_y() - bullets[i].get_center_y()) <= bubbles[j].get_radius() + bullets[i].get_height() / 2) && ((bubbles[j].get_center_y() - bullets[i].get_center_y()) >= -(bubbles[j].get_radius() + bullets[i].get_height() / 2)))){

                        // we loop across all possible pairs of bubbles and bullets and then check the "touching" condition
                        // if radius is larger than default value, then it splits into 2 smaller bubbles having opposite vx but equal vy (opposite to what the bigger bubble had)

                        bubbles.push_back(Bubble(bubbles[j].get_center_x(), bubbles[j].get_center_y(), bubbles[j].get_radius() / 2, bubbles[j].get_vx(), -bubbles[j].get_vy()));
                        bubbles.push_back(Bubble(bubbles[j].get_center_x(), bubbles[j].get_center_y(), bubbles[j].get_radius() / 2, -bubbles[j].get_vx(), -bubbles[j].get_vy()));
                        bubbles.erase(bubbles.begin() + j,bubbles.begin() + j + 1);
                        bullets.erase(bullets.begin() + i,bullets.begin() + i + 1);

                        S++; // score gets incremented accordingly
                        score1.reset(WINDOW_X - 1200 + textWidth("XXXXX"),20,S);
                    }
                }
                else{
                    if ((((bubbles[j].get_center_x() - bullets[i].get_center_x()) <= bubbles[j].get_radius() + bullets[i].get_width() / 2) && ((bubbles[j].get_center_x() - bullets[i].get_center_x()) >= -(bubbles[j].get_radius() + bullets[i].get_width() / 2)))
                        &&
                        (((bubbles[j].get_center_y() - bullets[i].get_center_y()) <= bubbles[j].get_radius() + bullets[i].get_height() / 2) && ((bubbles[j].get_center_y() - bullets[i].get_center_y()) >= -(bubbles[j].get_radius() + bullets[i].get_height() / 2)))){

                        // if bubble is already small, then we just eliminate it from the vector list

                        bubbles.erase(bubbles.begin() + j,bubbles.begin() + j + 1);
                        bullets.erase(bullets.begin() + i,bullets.begin() + i + 1);

                        S++; // score gets incremented accordingly
                        score1.reset(WINDOW_X - 1200 + textWidth("XXXXX"),20,S);

                        if (bubbles.size() == 0){ // if no bubble remains, then nothing needs to be done ... THE GAME IS WON
                            Text t(WINDOW_X - 1000,PLAY_Y_HEIGHT + 20,"YOU WIN!");
                            t.imprint();
                            wait(3);
                            return 0;
                        }
                    }
                }
            }
        }
        for(unsigned int i=0; i<bubbles.size(); i++){
            if ((((shooter.get_head_center_x() - bubbles[i].get_center_x()) <= shooter.get_body_width() / 2 + bubbles[i].get_radius()) && ((shooter.get_head_center_x() - bubbles[i].get_center_x()) >= -(shooter.get_body_width() / 2 + bubbles[i].get_radius())))
                &&
                (((shooter.get_body_center_y() - bubbles[i].get_center_y()) <= shooter.get_body_height() / 2 + bubbles[i].get_radius() + 2 * shooter.get_head_radius()) && ((shooter.get_body_center_y() - bubbles[i].get_center_y()) >= -(shooter.get_body_height() / 2 - bubbles[i].get_radius())))){

                // in this game, a somewhat different health bar is implemented ... how much health will reduce depends upon how long the "touch" was between bubble and shooter

                H -= 5; // for each STEP_TIME duration, health reduces by 5 units
                health1.reset(WINDOW_X - 1600 + textWidth("XXX"),20,H);

                if (H <= 0){ // if health drops to 0, GAME IS OVER
                    Text t(WINDOW_X - 1000,PLAY_Y_HEIGHT + 20,"GAME OVER! HEALTH DROPPED TO 0");
                    t.imprint();
                    wait(3);
                    return 0;
                }
            }
        }
        T ++; // time increases afer each STEP_TIME but since 50 such STEP_TIME equals a second, so what is printed is 'T / 50'
        time1.reset(WINDOW_X - 800 + textWidth("X"),20,T / 50);

        if (T >= 50*tmax){ // if tmax seconds are exceeded ... GAME IS OVER
            Text t(WINDOW_X - 1000,PLAY_Y_HEIGHT + 20,"GAME OVER! TIME LIMIT REACHED");
            t.imprint();
            wait(3);
            return 0;
        }
    }
}
