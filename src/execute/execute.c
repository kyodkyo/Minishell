/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:02:40 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/25 21:34:11 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	execute(t_ASTNode *node, t_list *env_list)
{
	int		i;
	int		status;
	pid_t	pid;

	heredoc(node);
	execute_core(node, env_list);
	set_signal(IGNORE, IGNORE);
	while (waitpid(-1, &status, 0) > 0)
	{
	}
	set_signal(SHELL, SHELL);
	free_ast(node);
}

void	execute_core_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	child_process(t_ASTNode *node)
{
	close(node->pipefd[0]);
	if (dup2(node->pipefd[1], STDOUT_FILENO) == -1)
		execute_core_error("dup2");
	close(node->pipefd[1]);
}

void	parent_process(t_ASTNode *node)
{
	close(node->pipefd[1]);
	if (dup2(node->pipefd[0], STDIN_FILENO) == -1)
		execute_core_error("dup2");
	close(node->pipefd[0]);
}

void	execute_core(t_ASTNode *node, t_list *env_list)
{
	if (node == NULL)
		return ;
	if (node->type == T_PIPE)
	{
		if (pipe(node->pipefd) == -1)
			execute_core_error("pipe");
		node->pid = fork();
		if (node->pid == -1)
			execute_core_error("fork");
		if (node->pid == 0)
		{
			child_process(node);
			execute_core(node->left, env_list);
			exit(EXIT_SUCCESS);
		}
		else
		{
			parent_process(node);
			execute_core(node->right, env_list);
			waitpid(node->pid, &node->status, 0);
		}
	}
	else
		execute_node(node, env_list);
}
