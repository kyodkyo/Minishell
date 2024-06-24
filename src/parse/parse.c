/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 00:34:07 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/24 21:05:13 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdio.h>

int	parse(t_mini *mini, char *input)
{
	t_token	*token_lst;
	int		result;

	token_lst = NULL;
	result = tokenize(mini, &token_lst, input);
	t_token	*tmp = token_lst;
	while(tmp)
	{
		printf("%d %s, ", tmp->type, tmp->str);
		tmp = tmp->next;
	}
	printf("\n");
	if (result != 0)
		return (result);
	result = astree(mini, token_lst);
	if (result != 0)
		return (result);
	return (0);
}
