#include "data.h"

#ifndef UTILS_H
#define UTILS_H

t_data *parsing(char **av);
int *generate_maze(t_data *data);
void free_data(t_data *data);
void printf_map(t_data *data);

#endif
