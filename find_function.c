#include "xmalloc.h"

typedef void (*free_func_t)(void *);

void free_arr(void *address) {
	void **arr = (void **)address;
	for (int i = 0; arr[i]; i++) {
		xfree(&arr[i]);
	}
	free(arr);
}

void wtfudoin(void *address) {
	(void)address;
	write(2, "wrong xfree function\n", 21);
	xexit(1);
}


free_func_t find_function(t_reg_type type) {
	if (type == XCHAR || type == XINT)
		return (free);
	else if (type == XCHAR_P || type == XINT_P)
		return (free_arr);
	/* add your own custom types	
	else if ()
		return (); */	
	else
		return (wtfudoin);
}