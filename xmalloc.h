#ifndef XMALLOC_H
# define XMALLOC_H

# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# define MAXCOUNT 128
# define LASTENTRY (MAXCOUNT - 1)
# define ISTOOMUCH > 100

typedef enum e_reg_type
{
	XUNKNOWN,
	XCHAR,
	XINT,
	XCHAR_P,		//must be NULLed 
	XINT_P,		//must be NULLed
	XCHAR_PP,	//.. in both directions
	XINT_PP,		//.. in both directions
	X_REGISTRY,
	X_REG_ENTRY,
	// add custom types
	CLEANUP_TYPE_COUNT
}	t_reg_type;

typedef struct s_reg_entry
{
	void		*address;
	uintptr_t	pointsto; //not needed, can cast it inside xfree()
	t_reg_type	type;
}	t_reg_entry;

typedef struct s_registry
{
	t_reg_entry	*reg[MAXCOUNT];
	int			count;
}	t_registry;


void *xmalloc(size_t nmemb, t_reg_type type);
void *xcalloc(size_t nmemb, t_reg_type type);

/*
	.perhaps i dont need to pass the address to xfree(). 
		-> i can compare the dereferenced address because it
		should be pointing to the same memory. Only then I can
		not NULL the pointer in the function where I call
		xfree() but that is fine because normal free doesn't either
*/
void xfree(void *address);
void xfree_ptr(void *address);
void xfree_node(void *address);
void free_registry(); // frees whole registry and destroys it

void xexit(int status); // destroys registry and exits with status

#endif