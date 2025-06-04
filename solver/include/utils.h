#include "data.h"

#ifndef UTILS_H
# define UTILS_H

t_data *init_data(char *filepath);
int **get_map(char *buffer, int count_line, int count_col);
void generate_solution(t_data *data);
void printf_maze(t_data *data);
void free_map(t_data *data);

#endif
