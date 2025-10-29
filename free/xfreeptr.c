#include "../xmalloc.h"

t_registry	**registry_addr(void);

void	move_entries_back(t_registry *registry, int i)
{
	if (registry->count == MAXCOUNT)
		return ;
	else if (registry->count - i > 100)
		return ;
	while (i < registry->count)
	{
		registry->reg[i] = registry->reg[i + 1];
		i++;
	}
	registry->reg[registry->count] = NULL;
}

/*
	Frees the address and deletes it from the registry.
	Does not free anything else.
*/
void	xfree_ptr(void *address_ptr)
{
	t_registry	*registry;
	t_reg_entry	*reg;
	int			i;

	registry = *registry_addr();
	i = -1;
	while (++i < registry->count)
	{
		if (i == LASTENTRY)
		{
			registry = (t_registry *)registry->reg[LASTENTRY];
			i = 0;
		}
		reg = registry->reg[i];
		if (reg && (uintptr_t)reg->address == (uintptr_t)address_ptr)
		{
			free(reg->address);
			free(reg);
			registry->reg[i] = NULL;
			if (registry->count != MAXCOUNT)
				registry->count--;
			move_entries_back(registry, i);
			return ;
		}
	}
}
