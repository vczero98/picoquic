#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BUFFER_INC_SIZE 10
#define CONFIG_FILE "config.txt"

int read_config(char **buffer) {
    FILE *fileStream;
    int buffer_size = BUFFER_INC_SIZE;
    char c;
    int ctr = 0;

    *buffer = malloc(buffer_size);
    if (*buffer == NULL) return -1;

    fileStream = fopen(CONFIG_FILE, "r");
    if (fileStream == NULL) {
        free(*buffer);
        return -1;
    }

    c = getc(fileStream);
    while ((c != EOF) && (c != '\n')) {
        if (ctr >= buffer_size - 1) {
            buffer_size += BUFFER_INC_SIZE;
            *buffer = realloc(*buffer, buffer_size);
            if (*buffer == NULL) return -1;
        }

        (*buffer)[ctr++] = c;
        c = getc(fileStream);
    }

    (*buffer)[ctr++] = '\0';

    fclose(fileStream);

    printf("Config file loaded\n");

    return 0;
}

int free_config(char **buffer) {
    if (*buffer != NULL) free(*buffer);
    return 0;
}