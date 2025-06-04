#include <stdio.h>

#include "data.h"
#include "maze_const.h"

void printf_maze(t_data *data) {
    for (int i = 0; i < data->height; i++) {
        for (int j = 0; j < data->width; j++) {
            if (data->map[i][j] == WALL) printf("X");
            else if (data->map[i][j] == PATH) printf("*");
            else if (data->map[i][j] == SOLUTION) printf("o");
        }
        printf("\n");
    }
}
