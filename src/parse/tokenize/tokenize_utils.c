/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 05:30:57 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/23 23:37:38 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

int	is_quotation_str(char *str, int l, int r)
{
	if (str[l] == '\'' && str[r - 1] == '\'')
		return (1);
	if (str[l] == '\"' && str[r - 1] == '\"')
		return (1);
	return (0);
}

int	is_delimiter(char c)
{
	return (c == ' ' || c == '\t');
}

int	ft_strcmp(const char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	get_token_type(const char *str)
{
	if (ft_strcmp(str, "|") == 0)
		return (T_PIPE);
	else if (ft_strcmp(str, "<") == 0)
		return (T_REDIR_IN);
	else if (ft_strcmp(str, ">") == 0)
		return (T_REDIR_OUT);
	else if (ft_strcmp(str, "<<") == 0)
		return (T_REDIR_HERE);
	else if (ft_strcmp(str, ">>") == 0)
		return (T_REDIR_APPEND);
	else if (ft_strcmp(str, "2>") == 0)
		return (T_REDIR_ERR);
	else
		return (T_WORD);
}
