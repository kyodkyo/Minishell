/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:14:14 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 12:27:41 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_user_defined(t_ASTNode *node, t_list *env_list, t_io *io)
{
	char *const argv[] = {"ls", "-l", NULL};
	extern char	**environ;

	if (execve(node->path, argv, environ) == -1)
		execve_error();
}

void	execute_fork(t_ASTNode *node, t_list *env_list, t_io *io)
{
	pid_t	pid;
	pid_t	child_pid;
	int		status;

	pid = fork();
	if (pid == -1)
		ft_putendl_fd("error pid\n", STDERR_FILENO);
	else if (pid == 0)
	{
		set_signal(DEFAULT, DEFAULT);
		check_pipe_read(io);
		set_process_io(io);
		if (built_in(node, env_list, io) == 0)
			return ;
		else
			execute_user_defined(node, env_list, io);
	}
	else
	{
		set_signal(IGNORE, IGNORE);
		child_pid = waitpid(pid, &status, WUNTRACED);
		set_parent_status(status);
		close_pipe(io);
		close_file(io);
	}
}
