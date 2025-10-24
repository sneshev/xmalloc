#include "xmalloc.h"

#define MEMERROR "xmalloc: memory allocation failed\n"
#define MEMERRORLEN 34
#define MEMERRORCODE 2

// destroys registry and exits with status
void xexit(int status) {
	xfree_registry();
	exit(status);
}

void xerr() {
	write(2, MEMERROR, MEMERRORLEN);
	xexit(MEMERRORCODE);
}
