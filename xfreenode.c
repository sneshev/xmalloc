#include "xmalloc.h"

typedef void	(*free_func_t)(void *);
free_func_t 	find_function2(t_reg_type type);

t_registry	**registry_addr();
void		move_entries_back(t_registry *registry, int i);


static void xfree_entry_node(t_reg_entry *reg) {
	t_reg_type type = reg->type;
	free_func_t free_whole = find_function2(type);
	free_whole(reg->address);
	free(reg);
}

/*
	PASS THE ADDRESS OF THE POINTER!
	-> xfree(&var);

	desc: finds the entry in the registry. Frees and deletes the address and every subaddress too
	does not free node->next in linked list
	
	->you need to add your own free_node() function(s) inside of find_functions2.c

	arrays must be NULL terminated
*/
void xfree_node(void *address) {
	void **addr = (void **)address;
	t_registry *registry = *registry_addr();
	int i = 0;

	while (i < registry->count) {
		if (i == LASTENTRY) {
			registry = (t_registry *)registry->reg[LASTENTRY]; i = 0;
		}
		t_reg_entry *reg = registry->reg[i];
		if (reg && reg->address == *addr) {
			xfree_entry_node(reg);
			registry->reg[i] = NULL;
			*addr = NULL;
			if (registry->count != MAXCOUNT)
				registry->count--;
			move_entries_back(registry, i);
			return ;
		}
		i++;
	}
}
