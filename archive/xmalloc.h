/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmalloc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:10:27 by sneshev           #+#    #+#             */
/*   Updated: 2025/07/26 19:37:19 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XMALLOC_H
# define XMALLOC_H

#include <stdlib.h>
#include <stdio.h>

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
	t_reg_entry	*reg[1024];
	int			count;
}	t_registry;

void		free_reg_entry(t_reg_entry *reg);
int			new_reg_entry(void *address, t_reg_type type);

int			init_registry();
t_registry	*get_registry();
int			free_registry();
void		*xmalloc(size_t size, t_reg_type type);


#endif