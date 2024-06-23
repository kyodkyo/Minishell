/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:41:19 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/23 15:43:19 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astree.h"
#include <stdio.h>

char	**concat_args(t_ASTNode *node);

void	new_cmd(t_ASTNode *node)
{
	node->cmd = (t_cmd *) ft_calloc(1, sizeof(t_cmd));
	node->cmd->name = node->value;
	node->cmd->argv = concat_args(node->right);
}

char	**concat_args(t_ASTNode *node)
{
	char		**result;
	t_ASTNode	*tmp_node;
	size_t		len;
	size_t		i;

	tmp_node = node;
	len = 0;
	while (tmp_node)
	{
		tmp_node = tmp_node->next;
		len++;
	}
	result = (char **)ft_calloc(len + 1, sizeof(char *));
	tmp_node = node;
	i = 0;
	while (i < len)
	{
		result[i] = ft_strdup(tmp_node->value);
		tmp_node = tmp_node->next;
		i++;
	}
	return result;
}
