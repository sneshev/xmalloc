#include "../xmalloc.h"

void	xerr(void);

t_registry	**registry_addr(void)
{
	static t_registry	*registry = NULL;

	return (&registry);
}

static int	init_registry(t_registry **reg_addr)
{
	if (*reg_addr != NULL)
		return (0);
	*reg_addr = calloc(1, sizeof(t_registry));
	if (!*reg_addr)
		xerr();
	(*reg_addr)->count = 0;
	return (1);
}

t_registry	*get_registry(void)
{
	t_registry	**address;
	t_registry	*registry;

	address = registry_addr();
	if (!*address)
		init_registry(address);
	registry = *address;
	while (registry->count == MAXCOUNT)
		registry = (t_registry *)registry->reg[LASTENTRY];
	if (registry->count == MAXCOUNT - 1)
	{
		init_registry((t_registry **)&registry->reg[LASTENTRY]);
		registry->count++;
		registry = (t_registry *)registry->reg[LASTENTRY];
	}
	return (registry);
}

void	new_reg_entry(void *address, t_reg_type type)
{
	t_registry	*registry;
	t_reg_entry	*entry;

	registry = get_registry();
	entry = calloc(1, sizeof(t_reg_entry));
	if (!entry)
		xerr();
	entry->address = address;
	entry->type = type;
	registry->reg[registry->count] = entry;
	registry->count++;
}
