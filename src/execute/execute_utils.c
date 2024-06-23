/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 00:58:53 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 18:09:24 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*is_valid_path(char **path, char *result, char *tmp)
{
	while (*path)
	{
		tmp = ft_strjoin(*path, result);
		if (!access(tmp, X_OK))
		{
			free(result);
			return (tmp);
		}
		free(tmp);
		path++;
	}
	return (0);
}

void	check_slash_exist(char *cmd)
{
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK))
			printf("error no file\n");
		exit(126);
	}
	else
	{
		unlink("/tmp/.infile");
		printf("error cmd not found\n");
		exit(127);
	}
}

char	*get_execute_path(char **path, char *cmd)
{
	char	*tmp;
	char	*result;

	tmp = 0;
	if (access(cmd, X_OK) == 0)
	{
		if (opendir(cmd))
			printf("error\n");
		return (ft_strdup(cmd));
	}
	if (!ft_strcmp(cmd, ""))
		printf("error\n");
	result = ft_strjoin("/", cmd);
	tmp = is_valid_path(path, result, tmp);
	if (tmp)
		return (tmp);
	free(result);
	check_slash_exist(cmd);
	return (NULL);
}

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
	if (WTERMSIG(status))
	{
		if (WTERMSIG(status) == SIGINT)
			g_status_code = 130;
		else if (WTERMSIG(status) == SIGQUIT)
			g_status_code = 131;
		else
			g_status_code = 128 + status;
	}
}
