/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 07:42:06 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/22 22:56:39 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astree.h"
#include <stdio.h>

t_ASTNode	*parse_command(t_token **current_token)
{
	t_ASTNode	*command_node;
	int			cmd_set;

	command_node = create_node(T_CMD, NULL);
	cmd_set = 0;
	while (*current_token && (*current_token)->type != T_PIPE)
	{
		if (is_redirect(*current_token))
			add_redirection(command_node, current_token);
		else
			add_argument(command_node, *current_token, &cmd_set);
		*current_token = (*current_token)->next;
	}
	return (command_node);
}

t_ASTNode	*parse_pipeline(t_token **current_token)
{
	t_ASTNode	*pipe_node;
	t_ASTNode	*left_command;

	left_command = parse_command(current_token);
	while (*current_token && (*current_token)->type == T_PIPE)
	{
		pipe_node = create_node(T_PIPE, NULL);
		pipe_node->left = left_command;
		*current_token = (*current_token)->next;
		pipe_node->right = parse_command(current_token);
		left_command = pipe_node;
	}
	return (left_command);
}

t_ASTNode	*astree(t_token *tokens)
{
	t_token	*current_token;

	current_token = tokens;
	return (parse_pipeline(&current_token));
}

void	print_ast(t_ASTNode *node, int level)
{
	int	i;

	if (!node)
		return ;
	i = 0;
	while (i++ < level)
		printf("  ");
	printf("Type: %d, Value: %s\n", node->type, node->value);
	if (node->left)
	{
		printf("Left:\n");
		print_ast(node->left, level + 1);
	}
	if (node->right)
	{
		printf("Right:\n");
		print_ast(node->right, level + 1);
	}
	if (node->next)
	{
		printf("Next:\n");
		print_ast(node->next, level + 1);
	}
}

void	free_tokens(t_token *tokens)
{
	t_token	*next;

	while (tokens)
	{
		next = tokens->next;
		free(tokens->str);
		free(tokens);
		tokens = next;
	}
}
