#include <stdio.h>

#include "utils.h"

int main(int ac, char **av) {
    if (ac < 2) {
        printf("Usage: ./solver <filename>\n");
        return 1;
    }

    t_data *data = init_data(av[1]);
    if (data == NULL) return 1;

    generate_solution(data);
    printf_maze(data);

    free_map(data);

    return 0;
}
