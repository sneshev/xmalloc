/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:26:43 by sneshev           #+#    #+#             */
/*   Updated: 2025/07/26 18:38:41 by sneshev          ###   ########.fr       */
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

void	free_reg_entry(t_reg_entry *reg)
{
	if (reg->type == CHAR_PTR)
		cleanup_char_ptr((char **)reg->address);
	// else if (reg->type == CHAR_ARR_PTR)
		// cleanup_char_arr_ptr(reg->address);
	// else if (reg->type == INT_ARR_PTR)
		// cleanup_int_arr_ptr(reg->address);
	// else if (reg->type == T_LIST_PTR)
		// cleanup_t_list_ptr(reg->address);
	// else if (reg->type == T_ENV_PTR)
		// cleanup_t_env_ptr(reg->address);
	else
		printf("idk, man??");
	free(reg);
}
