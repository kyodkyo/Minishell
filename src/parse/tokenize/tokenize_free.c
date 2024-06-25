/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:37:39 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/25 20:37:42 by dakyo            ###   ########.fr       */
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

void	token_free(t_token *token)
{
	if (token->str)
		free(token->str);
	free(token);
}
