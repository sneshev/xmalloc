#include "xmalloc.h"

static t_registry **registry_addr()
{
	static t_registry	*registry = NULL;

	return (&registry);
}

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

int	init_registry(t_registry **reg_addr)
{
	// t_registry **reg_addr = registry_addr();

	if (*reg_addr != NULL)
		return (0);
	*reg_addr = calloc(1, sizeof(t_registry));
	if (!*reg_addr) {
    	printf("malloc err\n");
		free_registry();
		exit(EXIT_FAILURE);
	}
	(*reg_addr)->count = 0;
	return (1);
}

t_registry *get_registry()
{
	t_registry **address = registry_addr();
	if (!*address)	init_registry(address); 
	
	t_registry *registry = *address;
	while(registry->count == MAXCOUNT) {
		registry = (t_registry *)registry->reg[LASTENTRY];
	}
	if (registry->count == MAXCOUNT - 1) {
		init_registry((t_registry **)&registry->reg[LASTENTRY]);
		registry = (t_registry *)registry->reg[LASTENTRY];
	}
	
	return (registry);
}

void new_reg_entry(void **address, t_reg_type type)
{
	t_registry	*registry = get_registry();
	t_reg_entry	*entry = calloc(1, sizeof(t_reg_entry));
	if (!entry) { printf("malloc err\n"); free_registry(); exit(EXIT_FAILURE); }

	entry->address = *address;
	entry->type = type;
	registry->reg[registry->count] = entry;
	registry->count++;
	printf("reg->addr%%p = %p\n", entry->address);
}
