/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   registry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:43:16 by sneshev           #+#    #+#             */
/*   Updated: 2025/07/26 19:06:16 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xmalloc.h"

static t_registry **registry_addr()
{
	static t_registry	*registry = NULL;

	return (&registry);
}

int	init_registry()
{
	t_registry **reg_addr;

	reg_addr = registry_addr();
	if (*reg_addr != NULL)
		return (0);
	*reg_addr = malloc(sizeof(t_registry));
	if (!*reg_addr)
		return (-1);
	(*reg_addr)->count = 0;
	return (1);
}

t_registry *get_registry()
{
	return (*registry_addr());
}

int free_registry()
{
	t_registry **reg_addr;
	reg_addr = registry_addr();
	if (*reg_addr == NULL)
		return (0);
	while ((*reg_addr)->count > 0)
	{
		(*reg_addr)->count--;
		free_reg_entry((*reg_addr)->reg[(*reg_addr)->count]);
	}
	free(*reg_addr);
	*reg_addr = NULL;
	return (1);
}

t_reg_entry *new_reg_entry(void *address, t_reg_type type)
{
	t_reg_entry *entry;

	entry = xmalloc(sizeof(t_reg_entry));
	entry->address = address;
	entry->type = type;
	return (entry);
}
