/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 05:32:56 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/15 06:25:50 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

void	token_lst_free(t_token **token_lst)
{
	t_token	*token;
	t_token	*n_token;

	token = *token_lst;
	while (token)
	{
		n_token = token->next;
		token_free(token);
		token = n_token;
	}
	free(*token_lst);
	*token_lst = NULL;
}

void token_free(t_token *token)
{
	if (token->str)
		free(token->str);
	free(token);
}

t_token	*token_lst_back(t_token *token_lst)
{
	if (token_lst == NULL)
		return (NULL);
	while (token_lst->next != NULL)
		token_lst = token_lst->next;
	return (token_lst);
}

void add_token(t_token **token_lst, t_token *token)
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

t_token *new_token(char *line, int l, int r)
{
	t_token	*token;
	char	*tmp;

	token = (t_token *)ft_calloc(1, sizeof(t_token));
	if (token == NULL)
		exit(0);
	token->str = ft_substr(line, l, r - l);
	if (token->str == NULL)
		exit(0);
	token->type = get_token_type(token->str);
	if (is_quotation_str(token->str, l, r))
	{
		tmp = token->str;
		if (l + 1 == r)
			token->str = ft_calloc(0, sizeof(char));
		else
			token->str = ft_substr(token->str, l + 1, r - l - 2);
		if (token->str == NULL)
			exit(0);
		free(tmp);
	}
	return (token);
}
