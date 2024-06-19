/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 00:34:07 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/19 17:54:50 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	parse(char *input)
{
	t_token	*token_lst;

	token_lst = NULL;
	tokenize(&token_lst, input);
	while (token_lst)
	{
		printf("%d %s -> ", token_lst->type, token_lst->str);
		token_lst = token_lst->next;
	}
	printf("\n");
}
