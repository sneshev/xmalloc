#include "xmalloc.h"

void new_reg_entry(void **address, t_reg_type type);
void xalloc_err();

size_t	find_size(t_reg_type type)
{
	if (type == CHAR)
		return (sizeof(char));
	else if (type == INT)
		return (sizeof(int));
	else if (type == CHAR_P)
		return (sizeof(char *));
	else if (type == INT_P)
		return (sizeof(int *));
	else if (type == CHAR_PP)
		return (sizeof(char **));
	else if (type == INT_PP)
		return (sizeof(int **));
	else if (type == T_REG_ENTRY)
		return (sizeof(t_reg_entry));
	else if (type == T_REGISTRY)
		return (sizeof(t_registry));
	else
		return (0);
}

void *xmalloc(size_t size, t_reg_type type)
{
	void *ptr;

	ptr = malloc(size * find_size(type));
	if (!ptr)
		xalloc_err();
	
	new_reg_entry(&ptr, type);
	return (ptr);
}

void *xcalloc(size_t size, t_reg_type type)
{
	void *ptr;

	ptr = calloc(size, find_size(type));
	if (!ptr)
		xalloc_err();
	
	new_reg_entry(&ptr, type);
	return (ptr);
}
