/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:50:16 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 16:32:50 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_next_pipe(t_ASTNode *node, t_io *io)
{
	int	result;

	if (node->right && node->right->type == T_PIPE)
	{
		result = pipe(io->pipe);
		if (result < 0)
			printf("error\n");
		io->pipe_write_fd = io->pipe[1];
		io->next_pipe = 1;
	}
}

void	execute_command(t_ASTNode *node, t_list *env_list, t_io *io)
{
	// if (io->input_fd != STDIN_FILENO)
	// 	dup2(STDIN_FILENO, io->input_fd);
	// if (io->output_fd != STDOUT_FILENO)
	// 	dup2(STDOUT_FILENO, io->output_fd);
	if (built_in(node, env_list, io) == 0)
		return ;
	else
		execute_fork(node, env_list, io);
}

void	execute_node(t_ASTNode *node, t_list *env_list, t_io *io)
{
	if (node->type == T_PIPE)
		check_next_pipe(node, io);
	if (node->type == T_CMD)
		execute_command(node, env_list, io);
	if (node->type == T_REDIR_IN)
		redir_in(node, io);
	if (node->type == T_REDIR_OUT)
		redir_out(node, io);
	if (node->type == T_REDIR_HERE)
		redir_heredoc(node, io);
	if (node->type == T_REDIR_APPEND)
		redir_out_append(node, io);
	if (node->type == T_REDIR_ERR)
		printf("not yet\n");
		// redirect_error(node, env_list, io);
}

void	execute_tree(t_ASTNode *node, t_list *env_list, t_io *io)
{
	if (node->left)
		execute_tree(node->left, env_list, io);
	execute_node(node, env_list, io);
	if (node->right)
		execute_tree(node->right, env_list, io);
}
