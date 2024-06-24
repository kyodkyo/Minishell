/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 00:58:53 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/24 17:28:52 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	execve_error(void)
{
	if (errno == EISDIR)
	{
		ft_putendl_fd(strerror(EISDIR), STDERR_FILENO);
		exit(1);
	}
	if (errno == EACCES)
	{
		ft_putendl_fd(strerror(EACCES), STDERR_FILENO);
		exit(1);
	}
	ft_putendl_fd("cmd not found", STDERR_FILENO);
	exit(127);
}

void	set_parent_status(int status)
{
	g_status_code = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGINT)
		{
			g_status_code = 130;
			printf("^C\n");
		}
		else if (WTERMSIG(status) == SIGQUIT)
		{
			g_status_code = 131;
			printf("^\\Quit: 3\n");
		}
		else
			g_status_code = 128 + status;
	}
}
