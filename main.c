#include <stdio.h>
#include "util.h"

int     main(int argc, char** argv) {

    printf("tamañan: %d\n", filesize(argv[1]));
    return 0;

}
