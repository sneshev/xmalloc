#include "../xmalloc.h"

size_t find_size(t_reg_type type)
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
