#include "../xmalloc.h"

void 			new_reg_entry(void *address, t_reg_type type);
size_t	find_size(t_reg_type type);

void xerr();

size_t find_size(t_reg_type type);

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