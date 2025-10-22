/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:26:43 by sneshev           #+#    #+#             */
/*   Updated: 2025/07/26 19:26:21 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xmalloc.h"

void	cleanup_char_ptr(char **ptr)
{
	if (!ptr || !*ptr)
		return ;
	free(*ptr);
	*ptr = NULL;
}

void cleanup_chararr_ptr(char ***arr)
{
	size_t	i;

	if (!arr || !*arr)
		return ;
	i = 0;
	while((*arr)[i])
	{
		free((*arr)[i]);
		(*arr)[i] = NULL;
		i++;
	}
	free(*arr);
	*arr = NULL;
}

void	free_reg_entry(t_reg_entry *reg)
{
	if (reg->type == CHAR)
		cleanup_char_ptr((char **)reg->address);
	else if (reg->type == CHAR_ARR)
		cleanup_chararr_ptr(reg->address);
	// else if (reg->type == INT_ARR)
		// cleanup_int_arr_ptr(reg->address);
	// else if (reg->type == T_LIST)
		// cleanup_t_list_ptr(reg->address);
	// else if (reg->type == T_ENV)
		// cleanup_t_env_ptr(reg->address);
	else
		printf("idk, man??");
	free(reg);
}
