#include "xmalloc.h"

void new_reg_entry(void **address, t_reg_type type);
void xerr();

static size_t find_size(t_reg_type type)
{
	if (type == XCHAR)
		return (sizeof(char));
	else if (type == XINT)
		return (sizeof(int));
	else if (type == XCHAR_P)
		return (sizeof(char *));
	else if (type == XINT_P)
		return (sizeof(int *));
	else if (type == XCHAR_PP)
		return (sizeof(char **));
	else if (type == XINT_PP)
		return (sizeof(int **));
	else if (type == X_REG_ENTRY)
		return (sizeof(t_reg_entry));
	else if (type == X_REGISTRY)
		return (sizeof(t_registry));
	else
		return (0);
}

void *xmalloc(size_t size, t_reg_type type)
{
	void *ptr;

	ptr = malloc(size * find_size(type));
	if (!ptr)
		xerr();
	
	new_reg_entry(&ptr, type);
	return (ptr);
}

void *xcalloc(size_t size, t_reg_type type)
{
	void *ptr;

	ptr = calloc(size, find_size(type));
	if (!ptr)
		xerr();
	
	new_reg_entry(&ptr, type);
	return (ptr);
}
