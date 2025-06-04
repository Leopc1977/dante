#include <stdlib.h>

#include "data.h"

void free_data(t_data *data) {
    for (int l = 0; l < data->height; l++) {
        free(data->map[l]);
    }
    free(data->map);

    free(data);
}
