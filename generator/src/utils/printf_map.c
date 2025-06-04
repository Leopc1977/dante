#include <stdio.h>

#include "data.h"
#include "maze_const.h"

void printf_map(t_data *data) {
    for (int l = 0; l < data->height; l++) {
        for (int c = 0; c < data->width; c++) {
            int cell = data->map[l][c];

            if (cell == WALL) printf("X");
            else printf("*");
        }
        if (l < data->height - 1) printf("\n");
    }
}
