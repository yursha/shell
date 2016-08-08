#include <stdio.h>
#include "version.h"

#define VERSION "0.1.0-SNAPSHOT"

extern char* get_shell_version();
extern void print_shell_version();

char* get_shell_version() {
    return VERSION;
}

void print_shell_version() {
    printf("%s\n", VERSION);
}
