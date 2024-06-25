/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:54:25 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/25 16:06:53 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astree.h"

int	is_redirect(t_token *token)
{
	return (token->type == T_REDIR_IN || token->type == T_REDIR_OUT
		|| token->type == T_REDIR_APPEND || token->type == T_REDIR_HERE
		|| token->type == T_REDIR_ERR);
}

t_ASTNode	*create_node(int type, char *value)
{
	t_ASTNode	*node;

	node = (t_ASTNode *)ft_calloc(1, sizeof(t_ASTNode));
	node->type = type;
	node->value = value;
	return (node);
}

int	add_redirection(t_ASTNode *command_node, t_token **token)
{
	t_ASTNode	*redir_node;

	if ((*token)->next == NULL)
		return (1);
	redir_node = create_node((*token)->type, (*token)->next->str);
	*token = (*token)->next;
	redir_node->left = command_node->left;
	command_node->left = redir_node;
	return (0);
}

int	add_argument(t_ASTNode *command_node, t_token *token, int *cmd_set)
{
	t_ASTNode	*arg_node;
	t_ASTNode	*current_arg;

	arg_node = create_node(T_ARG, token->str);
	if (command_node->right == NULL)
		command_node->right = arg_node;
	else
	{
		current_arg = command_node->right;
		while (current_arg->next)
			current_arg = current_arg->next;
		current_arg->next = arg_node;
	}
	if (!(*cmd_set))
	{
		command_node->value = token->str;
		*cmd_set = 1;
	}
	return (0);
}
