#include "xmalloc.h"

void xalloc_err() {
    printf("malloc err\n");
	free_registry();
	exit(EXIT_FAILURE);
}