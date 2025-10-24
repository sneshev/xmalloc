#include "xmalloc.h"

t_registry	**registry_addr();
void		move_entries_back(t_registry *registry, int i);

typedef void	(*free_func_t)(void *);
free_func_t find_function(t_reg_type type);



static void xfree_entry(t_reg_entry *reg) {
	t_reg_type type = reg->type;
	free_func_t free_whole = find_function(type);
	free_whole(reg->address);
	free(reg);
}

void xfree(void *address_ptr) {
	t_registry *registry = *registry_addr();
	uintptr_t address = (uintptr_t)address_ptr;
	int i = 0;

	while (i < registry->count) {
		if (i == LASTENTRY) {
			registry = (t_registry *)registry->reg[LASTENTRY]; i = 0;
		}
		t_reg_entry *reg = registry->reg[i];
		if (reg && reg->pointsto == address) {
			xfree_entry(reg);
			registry->reg[i] = NULL;
			if (registry->count != MAXCOUNT)
				registry->count--;
			move_entries_back(registry, i);
			return ;
		}
		i++;
	}
}
