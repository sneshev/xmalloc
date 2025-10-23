#ifndef XMALLOC_H
# define XMALLOC_H

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
	t_reg_type	type;
}	t_reg_entry;

typedef struct s_registry
{
	t_reg_entry	*reg[MAXCOUNT];
	int			count;
}	t_registry;


// allocation functions
void *xmalloc(size_t size, t_reg_type type);
void *xcalloc(size_t size, t_reg_type type);

// freeing functions
void xfree(void *address);
void xfree_ptr(void *address);
// void xfree_node(void *address);
void free_registry(); // frees whole registry and destroys it

// util functions
void xexit(int status); // destroys registry and exits with status
#endif


/*
   [0]   [1]   [2]    [3]   [4]   [5]
	0     1     NULL   3     4     5 .     count == 6
	0     1     3      4     5     .       count == 5
*/