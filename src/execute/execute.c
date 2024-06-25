/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:02:40 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/25 19:46:34 by dakyo            ###   ########.fr       */
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
}

void	execute_core(t_ASTNode *node, t_list *env_list)
{
	int		pipefd[2];
	pid_t	pid;
	int		status;

	if (node == NULL)
		return ;
	if (node->type == T_PIPE)
	{
		if (pipe(pipefd) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}

		if (pid == 0)
		{
			close(pipefd[0]);
			if (dup2(pipefd[1], STDOUT_FILENO) == -1)
			{
				perror("dup2");
				exit(EXIT_FAILURE);
			}
			close(pipefd[1]);
			execute_core(node->left, env_list);
			exit(EXIT_SUCCESS);
		}
		else
		{
			close(pipefd[1]);
			if (dup2(pipefd[0], STDIN_FILENO) == -1)
			{
				perror("dup2");
				exit(EXIT_FAILURE);
			}
			close(pipefd[0]);
			execute_core(node->right, env_list);
			waitpid(pid, &status, 0);
		}
	}
	else
		execute_node(node, env_list);
}
