#ifndef XMALLOC_H
# define XMALLOC_H

#include <stdlib.h>
#include <stdio.h>

#define MAXCOUNT 128
#define LASTENTRY (MAXCOUNT - 1)

typedef enum e_reg_type
{
	CHAR,
	CHAR_ARR,
	INT_ARR,
	T_LIST,
	T_ENV,
	T_REGISTRY,
	T_REG_ENTRY,
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




void		free_reg_entry(t_reg_entry *reg);
void		new_reg_entry(void **address, t_reg_type type);

int			init_registry();
t_registry	*get_registry();
void		free_registry();
void		*xmalloc(size_t size, t_reg_type type);
// void		xfree();


#endif