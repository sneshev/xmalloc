#include "xmalloc.h"

t_registry **registry_addr();

void free_this_registry(t_registry *registry) {
	if (!registry)	return ;

	if (registry->count == MAXCOUNT) {
		free_this_registry((t_registry *)registry->reg[LASTENTRY]);
		registry->count--;
	}

	int count = registry->count;
	while(count > 0) {
		t_reg_entry *reg = registry->reg[count - 1];
		if (reg) {
			if (reg->address) {
				free(reg->address);
			}
			free(reg);
		}
		count--;
	}
	free(registry);
}

void free_registry() {
	t_registry *root = *registry_addr();
	if (!root)
		return ;
	free_this_registry(root);
	*registry_addr() = NULL;
}