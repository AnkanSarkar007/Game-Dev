#include <simplecpp>
#include <cmath>
#include "light.h"

const int windowx = 900;
const int windowy = 900;

vector<light> create_classic_lights (){

    // create lights in the game in classic mode
    vector<light> lights;

    for (int i = 1; i < 4; i++){
        for (int j = 1; j < 4; j++){
            lights.push_back(light(50 + 200*j, 50 + 200*i));
        }
    }

    return lights;
}
vector<light> create_variant_lights (){

    // create lights in the game in variant mode
    vector<light> lights;

    int i = rand() % 5;

    if (i == 0){
        int j = rand() % 4;
        if (j == 0){
            lights.push_back(light(250,250,1));
            lights.push_back(light(450,250,1));
            lights.push_back(light(650,250,1));
            lights.push_back(light(250,450,1));
            lights.push_back(light(450,450,0));
            lights.push_back(light(650,450,0));
            lights.push_back(light(250,650,1));
            lights.push_back(light(450,650,0));
            lights.push_back(light(650,650,0));
        }
        else if (j == 1){
            lights.push_back(light(250,250,1));
            lights.push_back(light(450,250,1));
            lights.push_back(light(650,250,1));
            lights.push_back(light(250,450,0));
            lights.push_back(light(450,450,0));
            lights.push_back(light(650,450,1));
            lights.push_back(light(250,650,0));
            lights.push_back(light(450,650,0));
            lights.push_back(light(650,650,1));
        }
        else if (j == 2){
            lights.push_back(light(250,250,0));
            lights.push_back(light(450,250,0));
            lights.push_back(light(650,250,1));
            lights.push_back(light(250,450,0));
            lights.push_back(light(450,450,0));
            lights.push_back(light(650,450,1));
            lights.push_back(light(250,650,1));
            lights.push_back(light(450,650,1));
            lights.push_back(light(650,650,1));
        }
        else if (j == 3){
            lights.push_back(light(250,250,1));
            lights.push_back(light(450,250,0));
            lights.push_back(light(650,250,0));
            lights.push_back(light(250,450,1));
            lights.push_back(light(450,450,0));
            lights.push_back(light(650,450,0));
            lights.push_back(light(250,650,1));
            lights.push_back(light(450,650,1));
            lights.push_back(light(650,650,1));
        }
    }
    else if (i == 1){
        int j = rand() % 4;
        if (j == 0){
            lights.push_back(light(250,250,1));
            lights.push_back(light(450,250,1));
            lights.push_back(light(650,250,1));
            lights.push_back(light(250,450,0));
            lights.push_back(light(450,450,1));
            lights.push_back(light(650,450,0));
            lights.push_back(light(250,650,0));
            lights.push_back(light(450,650,1));
            lights.push_back(light(650,650,0));
        }
        else if (j == 1){
            lights.push_back(light(250,250,0));
            lights.push_back(light(450,250,0));
            lights.push_back(light(650,250,1));
            lights.push_back(light(250,450,1));
            lights.push_back(light(450,450,1));
            lights.push_back(light(650,450,1));
            lights.push_back(light(250,650,0));
            lights.push_back(light(450,650,0));
            lights.push_back(light(650,650,1));
        }
        else if (j == 2){
            lights.push_back(light(250,250,0));
            lights.push_back(light(450,250,1));
            lights.push_back(light(650,250,0));
            lights.push_back(light(250,450,0));
            lights.push_back(light(450,450,1));
            lights.push_back(light(650,450,0));
            lights.push_back(light(250,650,1));
            lights.push_back(light(450,650,1));
            lights.push_back(light(650,650,1));
        }
        else if (j == 3){
            lights.push_back(light(250,250,1));
            lights.push_back(light(450,250,0));
            lights.push_back(light(650,250,0));
            lights.push_back(light(250,450,1));
            lights.push_back(light(450,450,1));
            lights.push_back(light(650,450,1));
            lights.push_back(light(250,650,1));
            lights.push_back(light(450,650,0));
            lights.push_back(light(650,650,0));
        }
    }
    else if (i == 2){
        lights.push_back(light(250,250,0));
        lights.push_back(light(450,250,1));
        lights.push_back(light(650,250,0));
        lights.push_back(light(250,450,1));
        lights.push_back(light(450,450,1));
        lights.push_back(light(650,450,1));
        lights.push_back(light(250,650,0));
        lights.push_back(light(450,650,1));
        lights.push_back(light(650,650,0));
    }
    else if (i == 3){
        int j = rand() % 4;
        if (j == 0){
            lights.push_back(light(250,250,1));
            lights.push_back(light(450,250,0));
            lights.push_back(light(650,250,1));
            lights.push_back(light(250,450,0));
            lights.push_back(light(450,450,1));
            lights.push_back(light(650,450,1));
            lights.push_back(light(250,650,1));
            lights.push_back(light(450,650,1));
            lights.push_back(light(650,650,0));
        }
        else if (j == 1){
            lights.push_back(light(250,250,1));
            lights.push_back(light(450,250,0));
            lights.push_back(light(650,250,1));
            lights.push_back(light(250,450,1));
            lights.push_back(light(450,450,1));
            lights.push_back(light(650,450,0));
            lights.push_back(light(250,650,0));
            lights.push_back(light(450,650,1));
            lights.push_back(light(650,650,1));
        }
        else if (j == 2){
            lights.push_back(light(250,250,0));
            lights.push_back(light(450,250,1));
            lights.push_back(light(650,250,1));
            lights.push_back(light(250,450,1));
            lights.push_back(light(450,450,1));
            lights.push_back(light(650,450,0));
            lights.push_back(light(250,650,1));
            lights.push_back(light(450,650,0));
            lights.push_back(light(650,650,1));
        }
        else if (j == 3){
            lights.push_back(light(250,250,1));
            lights.push_back(light(450,250,1));
            lights.push_back(light(650,250,0));
            lights.push_back(light(250,450,0));
            lights.push_back(light(450,450,1));
            lights.push_back(light(650,450,1));
            lights.push_back(light(250,650,1));
            lights.push_back(light(450,650,0));
            lights.push_back(light(650,650,1));
        }
    }
    else if (i == 4){
        int j = rand() % 2;
        if (j == 0){
            lights.push_back(light(250,250,1));
            lights.push_back(light(450,250,0));
            lights.push_back(light(650,250,0));
            lights.push_back(light(250,450,0));
            lights.push_back(light(450,450,1));
            lights.push_back(light(650,450,0));
            lights.push_back(light(250,650,0));
            lights.push_back(light(450,650,0));
            lights.push_back(light(650,650,1));
        }
        else if (j == 1){
            lights.push_back(light(250,250,0));
            lights.push_back(light(450,250,0));
            lights.push_back(light(650,250,1));
            lights.push_back(light(250,450,0));
            lights.push_back(light(450,450,1));
            lights.push_back(light(650,450,0));
            lights.push_back(light(250,650,1));
            lights.push_back(light(450,650,0));
            lights.push_back(light(650,650,0));
        }
    }
    bool k = rand() % 2;
    if (k){
        for (unsigned int i = 0; i < lights.size(); i++){
            lights[i].toggle();
        }
    }
    return lights;
}
void classic (unsigned int mark, vector<light>& lights){

    int i = lights[mark].get_center_y();
    int j = lights[mark].get_center_x();
    int row = (i - 50) / 200;
    int col = (j - 50) / 200;

    lights[mark].toggle();
    if (row > 1) lights[mark - 3].toggle();
    if (row < 3) lights[mark + 3].toggle();
    if (col > 1) lights[mark - 1].toggle();
    if (col < 3) lights[mark + 1].toggle();

    return;
}
void variant (unsigned int mark, vector<light>& lights){

    int i = lights[mark].get_center_y();
    int j = lights[mark].get_center_x();
    int row = (i - 50) / 200;
    int col = (j - 50) / 200;

    lights[mark].toggle();
    if (row == 1){
        lights[mark + 3].toggle();
        lights[mark + 6].toggle();
    }
    if (row == 2){
        lights[mark - 3].toggle();
        lights[mark + 3].toggle();
    }
    if (row == 3){
        lights[mark - 3].toggle();
        lights[mark - 6].toggle();
    }
    if (col == 1){
        lights[mark + 1].toggle();
        lights[mark + 2].toggle();
    }
    if (col == 2){
        lights[mark - 1].toggle();
        lights[mark + 1].toggle();
    }
    if (col == 3){
        lights[mark - 1].toggle();
        lights[mark - 2].toggle();
    }

    return;
}
int main (){

    cout << "Mention your toggle option, press 0 for classic or 1 for variant ... ";
    int mode;
    cin >> mode;
    if (mode != 0 && mode != 1){
        cout << "Not a valid toggle option." << endl;
        return 0;
    }

    initCanvas("Lights Out",windowx,windowy);
    Rectangle full(windowx/2,windowy/2,windowx,windowy);
    full.setFill(true);
    full.setColor(COLOR(155,80,155));

    Text start1(windowx/2,50,"Welcome to the game of Lights Out! Depending on your mode of choice, try to switch off all the lights.");
    Text start2(windowx/2,windowy - 100,"Classic mode toggles all the neighbouring lights (excluding the diagonals) while variant mode toggles all the lights in that row and column.");
    Text start3(windowx/2,100,"Enjoy the game ... ");

    srand (time (NULL));
    vector<light> lights;
    if (mode == 0){
        lights = create_classic_lights();
    }
    else if (mode == 1){
        lights = create_variant_lights();
    }
    
    XEvent event;

    while (true){

        if (checkEvent(event)){
            if (mouseButtonPressEvent(event)){
                if (mode){
                    variant (3*floor((event.xbutton.y-150)/200) + floor((event.xbutton.x-150)/200),lights);
                }
                else{
                    classic (3*floor((event.xbutton.y-150)/200) + floor((event.xbutton.x-150)/200),lights);
                }
            }
            if (keyPressEvent(event)){
                if (charFromEvent(event) == '\33'){
                    return 0;
                }
            }
        }
        int counter = 0;
        for (unsigned int k = 0; k < lights.size(); k++){

            if (lights[k].get_state()){
                counter ++;
            }
        }
        if (counter == 0){
            start1.hide();
            start2.hide();
            start3.hide();
            Text win(windowx/2,75,"You win !");
            wait(3);
            return 0;
        }
    }
}