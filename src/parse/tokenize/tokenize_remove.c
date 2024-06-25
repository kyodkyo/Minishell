/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 23:19:29 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/25 20:41:12 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

void	remove_quotes(t_token *token);

void	tokenize_remove_quotes(t_token *token_lst)
{
	while (token_lst)
	{
		remove_quotes(token_lst);
		token_lst = token_lst->next;
	}
}

void	remove_quotes(t_token *token)
{
	int		i;
	int		j;
	int		length;
	char	*new_str;

	i = 0;
	j = 0;
	length = ft_strlen(token->str);
	new_str = (char *)ft_calloc(length + 1, sizeof(char));
	while (i < length)
	{
		if (token->str[i] != '"' && token->str[i] != '\'')
		{
			new_str[j++] = token->str[i];
		}
		i++;
	}
	new_str[j] = '\0';
	free(token->str);
	token->str = new_str;
}
