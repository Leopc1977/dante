#include <time.h>
#include <stdlib.h>

#include "data.h"
#include "maze_const.h"

int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

void shuffle_dirs(void) {
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        int tmp0 = dirs[i][0], tmp1 = dirs[i][1];

        dirs[i][0] = dirs[j][0];
        dirs[i][1] = dirs[j][1];
        dirs[j][0] = tmp0;
        dirs[j][1] = tmp1;
    }
}

void dig(t_data *data, int l, int c) {
    data->map[l][c] = PATH;

    shuffle_dirs();

    for (int i = 0; i < 4; i++) {
        int newWallL = dirs[i][0] + l;
        int newWallC = dirs[i][1] + c;

        int newL = dirs[i][0] * 2 + l;
        int newC = dirs[i][1] * 2 + c;

        if (
            newL >= 0 && newL < data->height &&
            newC >= 0 && newC < data->width &&
            data->map[newL][newC] == WALL
        ) {
            data->map[newWallL][newWallC] = PATH;
            dig(data, newL, newC);
        }
    }
}

int *generate_maze(t_data *data) {
    srand(time(NULL));

    (void)data;

    dig(data, 0, 0);

    return (int *)NULL;
}
