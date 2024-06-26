/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:19:17 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/26 11:30:06 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"
#include <stdio.h>

void	skip_delimiters(const char *line, t_token_iter *iter);
int		process_quotes(const char c, t_token_iter *iter);
void	process_token(t_mini *mini, t_token **token_lst,
			char *line, t_token_iter *iter);

int	tokenize(t_mini *mini, t_token **token_lst, char *line)
{
	t_token_iter	iter;

	ft_memset(&iter, 0, sizeof(t_token_iter));
	while (line[iter.right])
	{
		skip_delimiters(line, &iter);
		iter.left = iter.right;
		if (line[iter.right] == '|')
			iter.right++;
		else
		{
			while (line[iter.right] && (!is_delimiter(line[iter.right])
					|| iter.in_single_quote || iter.in_double_quote)
				&& (line[iter.right] != '|'
					|| iter.in_single_quote || iter.in_double_quote))
			{
				if (process_quotes(line[iter.right], &iter) != 0)
					break ;
				iter.right++;
			}
		}
		process_token(mini, token_lst, line, &iter);
	}
	tokenize_remove_quotes(*token_lst);
	return (iter.in_single_quote || iter.in_double_quote);
}

void	skip_delimiters(const char *line, t_token_iter *iter)
{
	while (line[iter->right] && is_delimiter(line[iter->right]))
		iter->right++;
}

int	process_quotes(const char c, t_token_iter *iter)
{
	if (c == '\'' && !iter->in_double_quote)
		iter->in_single_quote = !iter->in_single_quote;
	else if (c == '"' && !iter->in_single_quote)
		iter->in_double_quote = !iter->in_double_quote;
	return (0);
}

void	process_token(t_mini *mini, t_token **token_lst
	, char *line, t_token_iter *iter)
{
	t_token	*token;

	if (iter->right > iter->left)
	{
		token = new_token(line, iter->left, iter->right);
		if (!tokenize_expend(mini, token_lst, token))
			add_token(token_lst, token);
	}
}
