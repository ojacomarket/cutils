#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAXLINE 20

typedef struct buffer {
    char *filename;
    uint8_t rows;
    char **data;
} buffer_t;

buffer_t ioread(char *path);