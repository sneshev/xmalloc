#include "xmalloc.h"

t_registry	**registry_addr();
void	move_entries_back(t_registry *registry, int i);

// can call recursively on addresses inside the array (if is an array)
static void xfree_entry(t_reg_entry *reg) {
	// t_reg_type type = reg->type;
	free(reg->address);
	free(reg);
	// move_entries_back(registry);
}

//as a start only with single pointers and not arrays of arrays
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
			xfree_entry(reg);
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