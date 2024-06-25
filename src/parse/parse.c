/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 00:34:07 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/25 20:33:35 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdio.h>

int	parse(t_mini *mini, char *input)
{
	t_token	*tmp;
	t_token	*token_lst;
	int		result;

	token_lst = NULL;
	result = tokenize(mini, &token_lst, input);
	tmp = token_lst;
	if (result != 0)
		return (result);
	result = astree(mini, token_lst);
	if (result != 0)
		return (result);
	return (0);
}
