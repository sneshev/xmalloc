#include "xmalloc.h"

void new_reg_entry(void *address, t_reg_type type);
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
	/* add your own custom types
	else if (type == )
		return (sizeof()); */
	else if (type == X_REG_ENTRY)
		return (sizeof(t_reg_entry));
	else if (type == X_REGISTRY)
		return (sizeof(t_registry));
	else
		return (0);
}

/*
	Allocates NMEMB elements of XTYPE. Stores it in a registry of all xallocs. 

	Initializes registry if it isn't already.
*/

void *xmalloc(size_t nmemb, t_reg_type type)
{
	void *ptr;

	ptr = malloc(nmemb * find_size(type));
	if (!ptr)
		xerr();
	
	new_reg_entry(ptr, type);
	return (ptr);
}


/*
	Allocates NMEMB elements of XTYPE. Sets all bytes to 0.
	Stores entry in a registry of all xallocs. 

	Initializes registry if it isn't already.
*/
void *xcalloc(size_t nmemb, t_reg_type type)
{
	void *ptr;

	ptr = calloc(nmemb, find_size(type));
	if (!ptr)
		xerr();
	
	new_reg_entry(ptr, type);
	return (ptr);
}
