/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:11:10 by sneshev           #+#    #+#             */
/*   Updated: 2025/07/26 18:51:16 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xmalloc.h"

char *create_str()
{
	char *str;

	str = malloc(5 * sizeof(char));
	str[0] = 'W';
	str[1] = 'S';
	str[2] = 'A';
	str[3] = 'D';
	str[4] = '\0';
	return (str);
}

void *xmalloc(size_t size, t_reg_type type)
{
	void *ptr;

	ptr = malloc(size);
	if (!ptr)
		write(1, "malloc err\n", 11);
	else
	{
		new_reg_entry(ptr, type);
	}
	return (ptr);
}

int	main(void)
{
	char *str = create_str();
	printf("%s\n", str);
	// t_reg_entry *new_entry = malloc(sizeof(t_reg_entry));
	// new_entry->address = &str;
	// new_entry->type = CHAR;
	t_reg_entry *new_entry = new_reg_entry(str, CHAR);
	free_reg_entry(new_entry);
	printf("%s\n", str);
}
