#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "data.h"
#include "maze_const.h"

typedef struct s_node {
    int x, y;
    int g, f;
    struct s_node *parent;
} t_node;

int is_valid(int l, int c, t_data *data) {
    return (l >= 0 && l < data->height && c >= 0 && c < data->width);
}

int heuristic(int l1, int c1, int l2, int c2){
    return abs(l1 - l2) + abs(c1 - c2);
}

void reconstruct_path(t_node *end, t_data *data) {
    t_node *current = end;

    while (current != NULL) {
        data->map[current->y][current->x] = SOLUTION;
        current = current->parent;
    }
}

void free_astar(t_node *open_list [], int **visited, t_data *data) {
    for (int l = 0; l < data->height; l++) {
        free(visited[l]);
    }
    free(visited);

    for (int i = 0; i < data->height * data->width; i++) {
        if (open_list[i] != NULL) {
            free(open_list[i]);
        }
    }
}

int astar(t_data *data) {
    t_node *open_list [data->height * data ->width];
    for (int i = 0; i < data->height * data->width; i++) open_list[i] = NULL;
    int open_list_index = 0;

    int **visited = malloc(sizeof(int *) * data->height);
    for (int l = 0; l < data->height; l++) {
        visited[l] = malloc(sizeof(int) * data->width);

        for (int c = 0; c < data->width; c++) {
            visited[l][c] = UNVISITED;
        }
    }

    t_node *start = malloc(sizeof(t_node));
    if (start == NULL) return 1;
    start->x = 0;
    start->y = 0;
    start->g = 0;
    start->f = heuristic(0, 0, data->height - 1, data->width - 1);
    start->parent = NULL;
    open_list[open_list_index++] = start;

    while (open_list_index > 0) {
        int smallest_f_index = 0;
        for (int i = 0; i < open_list_index; i++) {
            if (open_list[i]->f < open_list[smallest_f_index]->f) smallest_f_index = i;
        }
        t_node *current = open_list[smallest_f_index];

        if (current->y == data->height - 1 && current->x == data->width - 1) {
            reconstruct_path(current, data);
            free_astar(open_list, visited, data);
            return 1;
        }

        for (int i = smallest_f_index; i < open_list_index - 1; i++) {
            open_list[i] = open_list[i + 1];
        }
        open_list_index--;

        visited[current->y][current->x] = VISITED;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int dir [2] = {dy[i], dx[i]};
            int pos [2] = {current->y + dir[0], current->x + dir[1]};

            if (
                is_valid(pos[0], pos[1], data)
                && visited[pos[0]][pos[1]] != VISITED
                && data->map[pos[0]][pos[1]] != WALL
            ) {
                t_node *n = malloc(sizeof(t_node));
                n->y = pos[0];
                n->x = pos[1];
                n->g = current->g + 1;
                n->f = n->g + heuristic(pos[0], pos[1], data->height - 1, data->width - 1);
                n->parent = current;
                open_list[open_list_index++] = n;
            }
        }
    }

    free_astar(open_list, visited, data);
    return 0;
}

int generate_solution(t_data *data) {
    return astar(data);
}
