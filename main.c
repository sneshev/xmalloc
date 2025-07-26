/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:11:10 by sneshev           #+#    #+#             */
/*   Updated: 2025/07/26 19:38:45 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xmalloc.h"

size_t	find_size(t_reg_type type)
{
	if (type == CHAR)
		return (sizeof(char));
	else if (type == CHAR_ARR)
		return (sizeof(char *));
	else if (type == INT_ARR)
		return (sizeof(int *));
	// else if (type == T_LIST)
	// 	return (sizeof(t_list *));
	// else if (type == T_ENV)
	// 	return (sizeof(t_env *));
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
		printf("malloc err\n");
	else
	{
		new_reg_entry(ptr, type);
	}
	return (ptr);
}


char *create_str()
{
	char *str;

	str = xmalloc(5, CHAR);
	str[0] = 'W';
	str[1] = 'S';
	str[2] = 'A';
	str[3] = 'D';
	str[4] = '\0';
	return (str);
}

void	write_str(char *str)
{
	printf("%s\n", str);
}

int	main(void)
{
	init_registry();
	char *str = create_str();
	write_str(str);
	free_registry();
	write_str(str);
	
}
