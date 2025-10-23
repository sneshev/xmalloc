#ifndef XMALLOC_H
# define XMALLOC_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define MAXCOUNT 128
# define LASTENTRY (MAXCOUNT - 1)
# define ISTOOMUCH > 100

typedef enum e_reg_type
{
	UNKNOWN,
	CHAR,
	INT,
	CHAR_P,		//must be NULLed 
	INT_P,		//must be NULLed
	CHAR_PP,	//.. in both directions
	INT_PP,		//.. in both directions
	T_REGISTRY,
	T_REG_ENTRY,
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
void xfreeptr(void *address);
void free_registry(); // at end of progrm

// util functions
void xexit(int status); //frees registry and exits with exitcode
#endif


/*
   [0]   [1]   [2]    [3]   [4]   [5]
	0     1     NULL   3     4     5 .     count == 6
	0     1     3      4     5     .       count == 5
*/