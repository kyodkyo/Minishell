/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:02:26 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 16:47:34 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_in(t_ASTNode *node, t_io *io)
{
	int	fd;

	fd = open(node->value, O_RDONLY);
	if (fd < 0)
		printf("error\n");
	if (io->input_fd != STDIN_FILENO)
		close(io->input_fd);
	io->input_fd = fd;
}

void	redir_out(t_ASTNode *node, t_io *io)
{
	int	fd;

	fd = open(node->value, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		printf("error\n");
	if (io->output_fd != STDOUT_FILENO)
		close(io->output_fd);
	io->output_fd = fd;
}

void	redir_heredoc(t_ASTNode *node, t_io *io)
{
	int		status;
	char	*file;
	pid_t	pid;

	file = ft_strjoin("/tmp/.infile", ft_itoa(1)); // 이거 변경.
	io->input_fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	// 음수
	set_signal(IGNORE, IGNORE);
	pid = fork();
	if (pid == 0)
		heredoc_child_process(node->value, io);
	waitpid(pid, &status, 0);
	set_signal(SHELL, IGNORE);
	close(io->input_fd);
	io->input_fd = open(file, O_RDONLY, 0644);
	free(file);
}

void	redir_out_append(t_ASTNode *node, t_io *io)
{
	int	fd;

	fd = open(node->value, O_WRONLY | O_APPEND | O_CREAT, 0644);
	// if (fd < 0)
	// 	error();
	if (io->output_fd != STDOUT_FILENO)
		close(io->output_fd);
	io->output_fd = fd;
}

void	heredoc_child_process(char *delimiter, t_io *io)
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
				g_status_code = 1;
				break ;
			}
			write(io->input_fd, line, ft_strlen(line));
			write(io->input_fd, "\n", 1);
			free(line);
		}
		else
			break ;
	}
	free(line);
	exit(0);
}
