#include <raylib.h> // Include the raylib library header file
#include "example_functions.h" // Include example_functions header file

using namespace std;

// Dimensions of the window
const int win_width = 600;
const int win_height = 400;

/**
 * @brief Resets the position of the square if the space bar is pressed
 * 
 * @param x The square's x-coordinate
 * @param y The square's y-coordinate
 * @param s The size (side-length) of the square
 */
void check_space_reset(float& x, float& y, int s);

int main(){

    InitWindow(win_width, win_height, "Test window"); // Create the window instance
    SetTargetFPS(60); // 60 FPS

    int s = 50; // The side length of the square

    // Coordinates of the square (center them based on width)
    float x = (win_width - s) / 2;
    float y = (win_height - s) / 2;

    while(!WindowShouldClose()){ // While the window remains open

        BeginDrawing();// Being drawing sequence

            check_space_reset(x, y, s); // Reset to center if space is pressed down
            WASD_move_deltaTime(x, y, 500, 500); // Update the square's position based on user input

            ClearBackground(SKYBLUE); // Clear the background
            DrawRectangle(x, y, s, s, RED); // Draw the square
            DrawText("WASD - move\n\n(SPACE) - reset", 50, 0, 24, BLACK);

        EndDrawing(); // End drawing sequence
    }

    CloseWindow(); // Ensure that the window is closed
    return 0;
}

void check_space_reset(float& x, float& y, int s){

    if(IsKeyPressed(KEY_SPACE)){

        x = (win_width - s) / 2;
        y = (win_height - s) / 2;
    }
}