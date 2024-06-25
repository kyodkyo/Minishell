/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:06:28 by dakang            #+#    #+#             */
/*   Updated: 2024/06/25 16:46:41 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astree.h"

void	free_cmd(t_cmd *cmd)
{
	int	i;

	if (cmd == NULL)
		return ;
	if (cmd->name)
		free(cmd->name);
	if (cmd->path)
		free(cmd->path);
	if (cmd->argv)
	{
		i = 0;
		while (cmd->argv[i])
		{
			free(cmd->argv[i]);
			i++;
		}
		free(cmd->argv);
	}
	free(cmd);
}

void	free_ast(t_ASTNode *node)
{
	if (node == NULL)
		return ;
	if (node->left)
		free_ast(node->left);
	if (node->right)
		free_ast(node->right);
	if (node->cmd)
		free_cmd(node->cmd);
	if (node->next)
		free_ast(node->next);
	free(node);
}
