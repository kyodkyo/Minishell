/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:13:23 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/25 21:16:39 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	heredoc_core(t_ASTNode *node);
void	heredoc_child_process(int fd, char *delimiter);

void	heredoc(t_ASTNode *node)
{
	if (node == NULL)
		return ;
	if (node->type == T_REDIR_HERE)
	{
		heredoc_core(node);
		set_signal(SHELL, IGNORE);
	}
	heredoc(node->left);
	heredoc(node->right);
}

char	*find_infile_num(t_ASTNode *node)
{
	int		i;
	int		find;
	char	*name;

	i = 0;
	find = 0;
	while (!find)
	{
		name = ft_strjoin("/tmp/.infile", ft_itoa(i));
		if (access(name, F_OK) != 0)
			find = 1;
		else
			i++;
	}
	return (name);
}

void	heredoc_core(t_ASTNode *node)
{
	int		status;
	char	*filename;
	pid_t	pid;
	int		fd;

	filename = find_infile_num(node);
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		file_open_error(node->value);
		return ;
	}
	set_signal(IGNORE, IGNORE);
	pid = fork();
	if (pid < 0)
		ft_putendl_fd("pid error", STDERR_FILENO);
	if (pid == 0)
		heredoc_child_process(fd, node->value);
	waitpid(pid, &status, 0);
	node->value = filename;
}

void	heredoc_child_process(int fd, char *delimiter)
{
	char	*line;

	set_signal(HEREDOC, IGNORE);
	while (1)
	{
		line = readline("heredog🐶> ");
		if (line)
		{
			if (!cmp_str(line, delimiter))
			{
				g_status_code = 0;
				break ;
			}
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
			free(line);
		}
		else
			break ;
	}
	free(line);
	exit(0);
}
