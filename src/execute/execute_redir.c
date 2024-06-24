/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:02:26 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/24 22:22:29 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	heredoc_child_process(int fd, char *delimiter);

void	redir_in(t_ASTNode *node)
{
	int	fd;

	fd = open(node->value, O_RDONLY);
	if (fd < 0)
		printf("error\n");
	dup2(fd, STDIN_FILENO);
}

void	redir_out(t_ASTNode *node)
{
	int	fd;

	fd = open(node->value, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		printf("error\n");
	dup2(fd, STDOUT_FILENO);
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

void	redir_heredoc(t_ASTNode *node)
{
	int		status;
	char	*filename;
	pid_t	pid;
	int		fd;

	filename = find_infile_num(node);
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	// 음수
	set_signal(IGNORE, IGNORE);
	pid = fork();
	if (pid == 0)
		heredoc_child_process(fd, node->value);
	waitpid(pid, &status, 0);
	set_signal(SHELL, IGNORE);
	fd = open(filename, O_RDONLY, 0644);
	dup2(fd, STDIN_FILENO);
	node->value = filename;
	free(filename);
}

void	redir_out_append(t_ASTNode *node)
{
	int	fd;

	fd = open(node->value, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
		printf("error\n");
	dup2(fd, STDOUT_FILENO);
}

void	heredoc_child_process(int fd, char *delimiter)
{
	char	*line;

	set_signal(HEREDOC, IGNORE);
	while (1)
	{
		line = readline("heredoc> ");
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
