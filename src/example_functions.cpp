#include <raylib.h> // Include the raylib library header file
#include "example_functions.h" // Include example_functions header file
#include <iostream>

using namespace std;

void WASD_move_deltaTime(float &x, float &y, int x_speed, int y_speed){

    int directions_moved = 0; // Used to properly calculate diagonal movement

    // Amount to add to coordinates
    float xAdd = 0;
    float yAdd = 0;

    // Update y-coordinate
    if(IsKeyDown(KEY_W)){

        yAdd -= (GetFrameTime() * x_speed);
        directions_moved++;
    }
    else if(IsKeyDown(KEY_S)){

        yAdd += (GetFrameTime() * x_speed);
        directions_moved++;
    }

    // Update x-coordinate
    if(IsKeyDown(KEY_A)){

        xAdd -= (GetFrameTime() * y_speed);
        directions_moved++;
    }
    else if(IsKeyDown(KEY_D)){

        xAdd += (GetFrameTime() * y_speed);
        directions_moved++;
    }

    if(directions_moved){
        
        if(directions_moved > 1){// If diagonal, divide components by sqrt(2)

            yAdd /= SQRT_2;
            xAdd /= SQRT_2;
        }

        // Update coordinates
        y += yAdd;
        x += xAdd;
    }
}