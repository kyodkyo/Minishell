/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 00:34:07 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/15 05:13:47 by woonshin         ###   ########.fr       */
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
