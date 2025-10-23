#include "xmalloc.h"

#define MEMERROR "xmalloc: memory allocation failed\n"
#define MEMERRORLEN 34
#define MEMERRORCODE 2

void xexit(int status) {
	free_registry();
	exit(status);
}

void xerr() {
	write(2, MEMERROR, MEMERRORLEN);
	xexit(MEMERRORCODE);
}
