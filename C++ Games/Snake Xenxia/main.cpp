#include<simplecpp>
#include"snake.h"
#include"food.h"

float steptime = 0.1;

int main(){
    srand (time (NULL));
    char lvl;
    cout << "Choose a difficulty level out of 'e', 'm' & 'h' ... " << endl;
    cin >> lvl;
    if (lvl == 'e'){
        gridsep = 35;
        npts = 40;
    }
    else if (lvl == 'm'){
        gridsep = 40;
        npts = 30;
    }
    else if (lvl == 'h'){
        gridsep = 50;
        npts = 20;
    }
    else{
        cout << "Not a valid difficulty level !";
    }
    initCanvas("Snake Xenzia",gridsep*npts,gridsep*npts + 50);
    Rectangle full(gridsep*npts/2,gridsep*npts/2,gridsep*npts,gridsep*npts);
    full.setFill(true);
    full.setColor(COLOR(80,80,80));
    Text start(gridsep*npts / 2, gridsep*npts / 2, "Welcome to the game of SNAKE XENZIA !");
    wait(3);
    start.reset(gridsep*npts / 2, gridsep*npts / 2, "Use 'W','A','S','D' to CONTROL the snake");
    wait(3);
    start.reset(gridsep*npts / 2, gridsep*npts / 2, "Can you achieve a SCORE of 50 in less than 250 SECONDS ?");
    wait(3);
    start.hide();
    Text beware(gridsep*npts/2,gridsep*npts + 25, "SPEED increases & TIME moves faster as the snake ENLARGES !");
    Text challenge(gridsep*npts/2,gridsep*npts + 40, "Eat BONUS food quickly & save TIME to gain time bonus !");
    int t = 0, t1 = 0;
    Text time(gridsep*npts/4, gridsep*npts + 10, "Time: ");
    Text T(gridsep*npts/4 + 25, gridsep*npts + 10, t/10);
    int s1 = 0, s2 = 0;
    Text score(gridsep*npts*0.75, gridsep*npts + 10, "Score: ");
    Text S(gridsep*npts*0.75 + 30, gridsep*npts + 10, s1);
    int b = 0;
    Text bonus(gridsep*npts/2, gridsep*npts + 10, "Bonus: ");
    Text B(gridsep*npts/2 + 35, gridsep*npts + 10, b);
    Snake s;
    Food f;
    int c = 0;
    while (true){
        XEvent event;
        if (checkEvent(event)){
            if (keyPressEvent(event)){
                char c = charFromEvent(event);
                if (c == '\33') break;
                s.move(c);
            }
        }
        else{
            s.move();
        }
        int h = s.headindex;
        if (f.item.getX() == s.body[h].getX() && f.item.getY() == s.body[h].getY()){
            s.increment();
            f.generate();
            if (steptime > 0.0125){
                steptime -= 0.00175;
            }
            s1++;
            S.reset(gridsep*npts*0.75 + 30, gridsep*npts + 10, s1);
            if (s1 == 50){
                Text T(gridsep*npts / 2, gridsep*npts / 2, "GAME WON !");
                wait(3);
                T.reset(gridsep*npts / 2, gridsep*npts / 2, "Your FINAL score is: ");
                Text fs(gridsep*npts / 2 + 80, gridsep*npts / 2, b + 5*s1 + (2500-t)/5 + 3*(b-300));
                wait(3);
                fs.hide();
                T.reset(gridsep*npts / 2, gridsep*npts / 2, "You may continue playing ...");
                wait(3);
            }
        }
        for (int i = 0; i < s.l; i++){
            if (i == h) continue;
            if (s.body[h].getX() == s.body[i].getX() && s.body[h].getY() == s.body[i].getY()){
                Text T(gridsep*npts / 2, gridsep*npts / 2, "GAME LOST !");
                wait(3);
                T.reset(gridsep*npts / 2, gridsep*npts / 2, "Your FINAL score is: ");
                Text fs(gridsep*npts / 2 + 80, gridsep*npts / 2, b + 5*s1 + (50*s1-t)/5 + 3*(b-300));
                wait(3);
                return 0;
            }
        }
        wait(steptime);
        t++;
        T.reset(gridsep*npts/4 + 25, gridsep*npts + 10, t/10);
        if (t >= 2500 && s1 < 50){
            Text T(gridsep*npts / 2, gridsep*npts / 2, "GAME LOST !");
            wait(3);
            T.reset(gridsep*npts / 2, gridsep*npts / 2, "Your FINAL score is: ");
            Text fs(gridsep*npts / 2 + 80, gridsep*npts / 2, b + 5*s1 + 3*(b-300));
            return 0;
        }
        if (s1 % 5 == 0 || c == 1){
            if (c == 0 && s1 != 0 && s2 != s1){
                f.bonusstart();
                c = 1;
                s2 = s1;
                t1 = t;
            }
            if (t >= t1 + 30){
                f.bonusend();
                c = 0;
            }
            if (f.bon.getX() >= s.body[h].getX() - gridsep && f.bon.getX() <= s.body[h].getX() + gridsep
                && f.bon.getY() >= s.body[h].getY() - gridsep && f.bon.getY() <= s.body[h].getY() + gridsep){
                f.bonusend();
                b += 100 - 3*(t-t1);
                B.reset(gridsep*npts/2 + 35,gridsep*npts + 10, b);
                c = 0;
            }
        }
    }
}
