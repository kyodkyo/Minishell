/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:02:26 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/15 03:01:35 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	redir_in(t_redir *redir, t_io *io)
{
	int	fd;

	fd = open(redir->filename, O_RDONLY);
	if (fd < 0)
		error();
	if (io->input_fd != STDIN_FILENO)
		close(io->input_fd);
	io->input_fd = fd;
}

void	redir_out(t_redir *redir, t_io *io)
{
	int	fd;

	fd = open(redir->filename, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		error();
	if (io->output_fd != STDOUT_FILENO)
		close(io->output_fd);
	io->output_fd = fd;
}

void	redir_heredoc(t_redir *redir, t_io *io)
{
	int		fd[2];
	char	*line;

	if (pipe(fd) < 0)
		error();
	if (io->input_fd != STDIN_FILENO)
		close(io->input_fd);
	while (1)
	{
		// line = readline();
		if (!strcmp(line, redir->filename))
		{
			free(line);
			break ;
		}
		//달러 처리 호출하기
		write(fd[1], line, ft_strlen(line));
		write(fd[1], "\n", 1);
		free(line);
	}
	close(fd[1]);
	io->input_fd = fd[0];
}

void	redir_out_append(t_redir *redir, t_io *io)
{
	int	fd;

	fd = open(redir->filename, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
		error();
	if (io->output_fd != STDOUT_FILENO)
		close(io->output_fd);
	io->output_fd = fd;
}
