#include "../xmalloc.h"

// destroys registry and exits with status
void xexit(int status) {
	xfree_registry();
	exit(status);
}
