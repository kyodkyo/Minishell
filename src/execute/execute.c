/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:09:03 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/25 02:37:05 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void execute(t_ASTNode *node, t_list *env_list)
{
	int	i;
	int	num;

	heredoc(node);
	execute_core(node, env_list);
	set_signal(IGNORE, IGNORE);
	i = 0;
	while (i < astree_counter(node))
	{
		waitpid(0, &num, 0);
		i++;
	}
	set_signal(SHELL, SHELL);
}

void execute_core(t_ASTNode *node, t_list *env_list)
{
	int pipefd[2];
	pid_t pid;
	int status;

	if (node == NULL)
		return;
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
		} else
		{
			close(pipefd[1]);
			if (dup2(pipefd[0], STDIN_FILENO) == -1)
			{
				perror("dup2");
				exit(EXIT_FAILURE);
			}
			close(pipefd[0]);
			execute_core(node->right, env_list);
		}
	}
	else
		execute_node(node, env_list);
}
