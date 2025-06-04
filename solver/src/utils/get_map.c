#include <stdio.h>
#include <stdlib.h>

#include "maze_const.h"

void check_free(int l, int **map) {
    for (int i = 0; i < l; i++) free(map[i]);
    free(map);
}

int **get_map(char *buffer, int count_line, int count_col) {
    int index = 0;

    int **map = malloc(sizeof(int *) * count_line);
    if (map == NULL) return NULL;

    for (int l = 0; l < count_line; l++) {
        map[l] = malloc(sizeof(int) * count_col);
        if (map[l] == NULL) {
            check_free(l, map);
            return NULL;
        }

        for (int c = 0; c < count_col; c++) {
            map[l][c] = buffer[index] == 'X' ? WALL : PATH;
            index++;
        }
        index++;
    }

    return map;
}
