#include "io.h"

buffer_t ioread(char* path) {

    uint8_t count_rows = 0;
    FILE* f_ptr = fopen(path, "rt");
    char** buffer = (char**)malloc(sizeof(char*)*MAXLINE);
    *buffer = (char*)malloc(sizeof(char)*MAXLINE);
    if (f_ptr == NULL)
        exit(EXIT_FAILURE);
    while(fgets(*(buffer + count_rows), MAXLINE, f_ptr)) {
        if (count_rows == MAXLINE) {
            buffer = realloc(buffer, sizeof(char*) * MAXLINE * (count_rows));
        }
        count_rows = count_rows + 1;
        *(buffer + count_rows) = (char*)malloc(sizeof(char)*MAXLINE);
    }
    buffer_t buf = {path, count_rows, buffer};
    fclose(f_ptr);
    return buf;
}