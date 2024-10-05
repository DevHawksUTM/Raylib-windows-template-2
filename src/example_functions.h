#ifndef EXAMPLE_FUNCTIONS_H
#define EXAMPLE_FUNCTIONS_H

    #define SQRT_2 1.414

    /**
     * @brief Updates x & y coordinates based on the number of elapsed seconds
     *        (Also divides distances when diagonal)
     * 
     * @param x The x-coordinate to update
     * @param y The y-coordinate to update
     * @param x_speed The multiplier used when updating the x-coordinate (pixels per second)
     * @param y_speed The multiplier used when updating the y-coordinate (pixels per second)
     */
    void WASD_move_deltaTime(float &x, float &y, int x_speed, int y_speed);

#endif