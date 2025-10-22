#include "xmalloc.h"

t_registry **registry_addr();

// can call recursively on addresses inside the array (if is an array)
void xfree_entry(t_reg_entry *reg) {
	// t_reg_type type = reg->type;
	free(reg->address);
	free(reg);
	//move addresses backwards to fill the gap
}

//as a start only with single pointers and not arrays of arrays
void xfree(void *address) {
	void **addr = (void **)address;
	t_registry *registry = *registry_addr();
	int i = 0;

	while (i < registry->count) {
		if (i == LASTENTRY) {
			registry = (t_registry *)registry->reg[LASTENTRY]; i = 0;
		}
		t_reg_entry *reg = registry->reg[i];
		if (reg && reg->address == *addr) {
			xfree_entry(reg);
			registry->reg[i] = NULL;
			*addr = NULL;
			return ;
		}
		i++;
	}
}

void xfreeptr(void *address) {
	void **addr = (void **)address;
	t_registry *registry = *registry_addr();
	int i = 0;

	while (i < registry->count) {
		if (i == LASTENTRY) {
			registry = (t_registry *)registry->reg[LASTENTRY]; i = 0;
		}
		t_reg_entry *reg = registry->reg[i];
		if (reg && reg->address == *addr) {
			free(reg->address);
			free(reg);
			registry->reg[i] = NULL;
			*addr = NULL;
			return ;
		}
		i++;
	}
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