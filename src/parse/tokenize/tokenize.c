/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:19:17 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/22 15:10:36 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

void	tokenize(t_mini *mini, t_token **token_lst, char *line)
{
	int		left;
	int		right;
	int		in_single_quote;
	int		in_double_quote;
	t_token	*token;

	left = 0;
	right = 0;
	in_single_quote = 0;
	in_double_quote = 0;
	while (right < (int)ft_strlen(line))
	{
		while (line[right] != '\0' && is_delimiter(line[right]))
			right++;
		left = right;

		while (line[right] != '\0' && 
			(!is_delimiter(line[right]) || in_single_quote || in_double_quote))
		{
			if (line[right] == '\'' && !in_double_quote)
				in_single_quote = !in_single_quote;
			else if (line[right] == '"' && !in_single_quote)
				in_double_quote = !in_double_quote;
			right++;
		}
		if (right > left)
		{
			token = new_token(line, left, right);
			if (tokenize_expend(mini, token_lst, token) == 0)
				add_token(token_lst, token);
		}
	}
	if (in_single_quote || in_double_quote)
		exit(1);
}
