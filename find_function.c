#include "xmalloc.h"

typedef void (*free_func_t)(void *);

static void free_2darr(void *address) {
	void **arr = (void **)address;
	for (int i = 0; arr[i]; i++) {
		xfree(arr[i]);
	}
	free(arr);
}

static void free_3darr(void *address) {
	void ***arr = (void ***)address;
	for (int i = 0; arr[i]; i++) {
		for (int j = 0; arr[i][j]; j++) {
			xfree(arr[i][j]);
		}
		xfree(arr[i]);
	}
	free(arr);
}

static void wtfudoin(void *address) {
	(void)address;
	write(2, "wrong xfree function\n", 21);
	xexit(1);
}

free_func_t find_function(t_reg_type type) {
	if (type == XCHAR || type == XINT)
		return (free);
	else if (type == XCHAR_P || type == XINT_P)
		return (free_2darr);
	else if (type == XCHAR_PP || type == XINT_PP)
		return (free_3darr);
	/* add your own custom types	
	else if ()
		return (); */	
	else
		return (wtfudoin);
}
