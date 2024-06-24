/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_expend.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 06:13:12 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/24 23:15:05 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tokenize.h"
#include "utils.h"

/**
 * return 0 -> 변경 없음.
 * return 1 -> 변경 있음.
*/
int	tokenize_expend(t_mini *mini, t_token **token_lst, t_token *token)
{
	t_token	*back;
	char	*new_line;
	char	**splited;
	t_token	*token_tmp;
	int		i;

	back = token_lst_back(*token_lst);
	if (back && back->type == T_REDIR_HERE || token->type == T_SINGLE_QUOTE)
		return (0);
	new_line = expand_env(mini->env_list, token->str);
	if (ft_strcmp(token->str, new_line) == 0)
	{
		free(new_line);
		return (0);
	}
	splited = ft_split(new_line, ' ');
	i = 0;
	while (splited[i])
	{
		token_tmp = new_token(splited[i], 0, ft_strlen(splited[i]));
		add_token(token_lst, token_tmp);
		i++;
	}
	token_free(token);
	return (1);
}
