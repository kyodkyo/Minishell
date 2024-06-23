/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:14:14 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 23:21:13 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	execute_user_defined(t_ASTNode *node, t_list *env_list)
{
	extern char	**environ;

	if (execve(node->cmd->path, node->cmd->argv, environ) == -1)
		execve_error();
}

void	execute_fork(t_ASTNode *node, t_list *env_list)
{
	pid_t	pid;
	pid_t	child_pid;
	int		status;

	set_signal(IGNORE, IGNORE);
	pid = fork();
	if (pid == -1)
		ft_putendl_fd("error pid\n", STDERR_FILENO);
	else if (pid == 0)
	{
		set_signal(DEFAULT, DEFAULT);
		if (built_in(node, env_list) == 0)
			return ;
		else
			execute_user_defined(node, env_list);
	}
	else
	{
		child_pid = waitpid(pid, &status, WUNTRACED);
		set_parent_status(status);
	}
}
