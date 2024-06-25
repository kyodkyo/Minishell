/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 05:32:56 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/25 20:38:04 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

t_token	*token_lst_back(t_token *token_lst)
{
	if (token_lst == NULL)
		return (NULL);
	while (token_lst->next != NULL)
		token_lst = token_lst->next;
	return (token_lst);
}

void	add_token(t_token **token_lst, t_token *token)
{
	t_token	*back;

	if ((*token_lst) == 0)
	{
		*token_lst = token;
		return ;
	}
	back = token_lst_back(*token_lst);
	back->next = token;
}

int	check_token_type(char c)
{
	if (c == '\'')
		return (T_SINGLE_QUOTE);
	else
		return (T_DOUBLE_QUOTE);
}

t_token	*new_token(char *line, int l, int r)
{
	t_token	*token;
	char	*tmp;

	token = (t_token *)ft_calloc(1, sizeof(t_token));
	if (token == NULL)
		memory_error();
	token->str = ft_substr(line, l, r - l);
	if (token->str == NULL)
		memory_error();
	token->type = get_token_type(token->str);
	if (is_quotation_str(line, l, r))
	{
		token->type = check_token_type(line[l]);
		tmp = token->str;
		if (l + 1 == r)
			token->str = ft_calloc(0, sizeof(char));
		else
			token->str = ft_substr(line, l + 1, r - l - 2);
		if (token->str == NULL)
			memory_error();
		free(tmp);
	}
	return (token);
}
