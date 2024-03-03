#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "include/utils.h"


char* readFile(const char* name){
    FILE* f = fopen(name, "r");
    if(!f){
        printf("Error: %s: %s\n", name, strerror(errno));
        exit(1);
    }

    fseek(f, 0, SEEK_END);
    size_t size = (size_t)ftell(f);
    fseek(f, 0, SEEK_SET);

    char* buffer = malloc(size+1);
    if(!buffer){
        printf("Haha go buy more RAM!\n");
        exit(1);
    }
    fread(buffer, 1, size, f);
    buffer[size] = '\0';
    return buffer;
}