#include "../xmalloc.h"

static void	free_2darr(void *address)
{
	void	**arr;
	int		i;

	if (!address)
		return ;
	arr = (void **)address;
	i = 0;
	while (arr[i])
	{
		xfree(arr[i]);
		i++;
	}
	free(arr);
}

static void	free_3darr(void *address)
{
	void	***arr;
	int		i;
	int		j;

	if (!address)
		return ;
	arr = (void ***)address;
	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			xfree(arr[i][j]);
			j++;
		}
		xfree(arr[i]);
		i++;
	}
	free(arr);
}

static void	wtfudoin(void *address)
{
	(void)address;
	write(2, "wrong xfree function\n", 21);
	xexit(1);
}

t_free_func	find_function(t_reg_type type)
{
	if (type == XCHAR || type == XINT)
		return (free);
	else if (type == XCHAR_P || type == XINT_P)
		return (free_2darr);
	else if (type == XCHAR_PP || type == XINT_PP)
		return (free_3darr);
	/* add your own custom types	
	else if ()
		return (); */	
	else
		return (wtfudoin);
}
