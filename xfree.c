#include "xmalloc.h"


//as a start only with single pointers and not arrays of arrays
void xfree(void **addr, t_reg_type type) {
	t_registry *registry = get_registry();
}
/*
	.find the right address
	.free the address and set the reg entry to NULL
		->if its an array, find the right address of every element and do the same
	.move the next reg entries backwards to fill the gap
		->if the count is MAXCOUNT and we have initialized another registry,
		idk if i should move over all of those elements into the previous registry
		or not. 
		If the count is MAXCOUNT, I can just leave gaps (reg entry == NULL)
		and skip them when freeing
*/