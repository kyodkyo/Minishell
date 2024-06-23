/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 00:34:07 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/23 17:50:45 by woonshin         ###   ########.fr       */
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
	if (result != 0)
		return (result);
	mini->astree_root = astree(token_lst);
	return (0);
}
