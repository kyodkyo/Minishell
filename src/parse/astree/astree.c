/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 07:42:06 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/25 20:34:04 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astree.h"
#include <stdio.h>

int	parse_pipeline(t_mini *mini, t_token **current_token);
int	parse_command(t_ASTNode **node, t_token **current_token);

int	astree(t_mini *mini, t_token *tokens)
{
	t_token	*current_token;
	int		result;

	current_token = tokens;
	result = parse_pipeline(mini, &current_token);
	if (result != 0)
		return (result);
	return (0);
}

int	parse_command(t_ASTNode **node, t_token **current_token)
{
	t_ASTNode	*command_node;
	int			cmd_set;
	int			result;

	command_node = create_node(T_CMD, NULL);
	cmd_set = 0;
	while (*current_token && (*current_token)->type != T_PIPE)
	{
		if (is_redirect(*current_token))
			result = add_redirection(command_node, current_token);
		else
			result = add_argument(command_node, *current_token, &cmd_set);
		if (result != 0)
			return (result);
		*current_token = (*current_token)->next;
	}
	new_cmd(command_node);
	*node = command_node;
	return (0);
}

int	parse_pipeline(t_mini *mini, t_token **current_token)
{
	t_ASTNode	*pipe_node;
	t_ASTNode	*left_command;
	int			result;

	result = parse_command(&left_command, current_token);
	if (result != 0)
		return (result);
	while (*current_token && (*current_token)->type == T_PIPE)
	{
		pipe_node = create_node(T_PIPE, NULL);
		pipe_node->left = left_command;
		*current_token = (*current_token)->next;
		result = parse_command(&pipe_node->right, current_token);
		if (result != 0)
			return (result);
		left_command = pipe_node;
	}
	mini->astree_root = left_command;
	return (0);
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
