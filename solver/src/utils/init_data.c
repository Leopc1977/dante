#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "data.h"
#include "utils.h"

int get_count_line(char *file_content) {
    int count_line = 1;
    int index = 0;

    while(file_content[index] != '\0') {
        if (file_content[index] == '\n')
            count_line++;

        index++;
    }

    return count_line;
}

int get_count_column(char *file_content) {
    int count_col = 0;
    int index = 0;

    while (file_content[index] != '\n') {
        count_col++;
        index++;
    }

    return count_col;
}

t_data *init_data(char *filepath) {
    t_data *data = malloc(sizeof(t_data));
    if (data == NULL) {
        return NULL;
    }

    FILE *file;
    struct stat infos;
    char *buffer;

    if (stat(filepath, &infos) != 0) {
        perror("Erreur avec stat");
        return NULL;
    }

    file = fopen(filepath, "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return NULL;
    }

    buffer = malloc(infos.st_size + 1);
    if (buffer == NULL) {
        perror("Erreur d'allocation mémoire");
        fclose(file);
        return NULL;
    }

    size_t lus = fread(buffer, 1, infos.st_size, file);
    buffer[lus] = '\0';

    int count_line = get_count_line(buffer);
    int count_col = get_count_column(buffer);

    data->map = get_map(buffer, count_line, count_col);
    if (data->map == NULL) return NULL;
    data->height = count_line;
    data->width = count_col;

    free(buffer);
    fclose(file);

    return data;
}
