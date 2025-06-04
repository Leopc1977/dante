#include <stdlib.h>
#include <string.h>

#include "data.h"
#include "maze_const.h"

t_data *parsing(char **av) {
    t_data *data = malloc(sizeof(t_data));

    if (!data) {
        return NULL;
    }

    data->width = atoi(av[1]);
    data->height = atoi(av[2]);

    if (
        (data->width == 0 && strcmp(av[1], "0") != 0) 
        || (data->height == 0 && strcmp(av[2], "0") != 0)
    ) {
        free(data);
        return NULL;
    }

    data->map = malloc(sizeof(int *) * data->height);
    if (data->map == NULL) {
        free(data);
        return NULL;
    }

    for (int l = 0; l < data->height; l++) {
        data->map[l] = malloc(sizeof(int) * data->width);

        for (int c = 0; c < data->width; c++) {
            data->map[l][c] = WALL;
        }
    }

    return data;
}
