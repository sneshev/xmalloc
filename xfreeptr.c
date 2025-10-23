#include "xmalloc.h"

t_registry **registry_addr();

void move_entries_back(t_registry *registry) {
	if (registry->count == MAXCOUNT)
		return ;

	registry->count--;
	int i = 0;
	while (registry->reg[i])
		i++;
	if (registry->count - i ISTOOMUCH)
		return ;
	
	while (i < registry->count) {
		registry->reg[i] = registry->reg[i + 1];
		i++;
	}
	registry->reg[registry->count] = NULL;
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
			move_entries_back(registry);
			return ;
		}
		i++;
	}
}