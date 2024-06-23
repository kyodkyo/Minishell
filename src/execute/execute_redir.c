/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:02:26 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 23:10:07 by woonshin         ###   ########.fr       */
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
	dup2(STDIN_FILENO, fd);
}

void	redir_out(t_ASTNode *node)
{
	int	fd;

	fd = open(node->value, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		printf("error\n");
	dup2(fd, STDOUT_FILENO);
}

void	redir_heredoc(t_ASTNode *node)
{
	int		status;
	char	*file;
	pid_t	pid;
	int		fd;

	file = ft_strjoin("/tmp/.infile", ft_itoa(1)); // 이거 변경.
	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	// 음수
	set_signal(IGNORE, IGNORE);
	pid = fork();
	if (pid == 0)
		heredoc_child_process(fd, node->value);
	waitpid(pid, &status, 0);
	set_signal(SHELL, IGNORE);
	fd = open(file, O_RDONLY, 0644);
	dup2(STDIN_FILENO, fd);
	free(file);
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

	set_signal(DEFAULT, IGNORE);
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
