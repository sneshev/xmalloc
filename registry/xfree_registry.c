#include "../xmalloc.h"

t_registry	**registry_addr(void);

void	free_this_registry(t_registry *registry)
{
	t_reg_entry	*reg;
	int			count;

	if (!registry)
		return ;
	if (registry->count == MAXCOUNT)
	{
		free_this_registry((t_registry *)registry->reg[LASTENTRY]);
		registry->count--;
	}
	count = registry->count;
	while (count > 0)
	{
		reg = registry->reg[count - 1];
		if (reg)
		{
			if (reg->address)
				free(reg->address);
			free(reg);
		}
		count--;
	}
	free(registry);
}

// frees whole registry and destroys it
void	xfree_registry(void)
{
	t_registry	*root;

	root = *registry_addr();
	if (!root)
		return ;
	free_this_registry(root);
	*registry_addr() = NULL;
}
