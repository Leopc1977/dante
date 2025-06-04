#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "data.h"

int main(int ac, char **av) {
    if (ac < 3) {
        printf("Usage: ./generator <numbers>\n");
        return 1;
    }

    t_data *data = parsing(av);
    if (data == NULL) {
        return 1;
    }

    generate_maze(data);
    printf_map(data);
    free_data(data);

    return 0;
}
