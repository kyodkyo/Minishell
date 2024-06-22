/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2024/06/20 16:14:14 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 01:28:44 by dakyo            ###   ########.fr       */
=======
/*   Created: 2024/06/21 02:48:47 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/22 22:44:27 by woonshin         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

<<<<<<< HEAD
void	execute_user_defined(t_ASTNode *node, t_list *env_list, t_io *io)
{
	char		*str;
	char		*path;
	char		*execute_path;
	extern char	**environ;

	str = "PATH";
	path = find_by_key(env_list, str);
	execute_path = get_execute_path(&path, node->value);
	if (execve(execute_path, &node->next->value, environ) == -1)
		execve_error();
}
=======
// void    child_process()
// {
    
// }
>>>>>>> main

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
		if (built_in(node, env_list, io))
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
