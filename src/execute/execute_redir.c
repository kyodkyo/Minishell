/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:02:26 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/21 02:29:36 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_t.h"

void	redir_in(t_redir *redir, t_io *io)
{
	int	fd;

	fd = open(redir->filename, O_RDONLY);
	if (fd < 0)
		printf("error\n");
	if (io->input_fd != STDIN_FILENO)
		close(io->input_fd);
	io->input_fd = fd;
}

void	redir_out(t_redir *redir, t_io *io)
{
	int	fd;

	fd = open(redir->filename, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		printf("error\n");
	if (io->output_fd != STDOUT_FILENO)
		close(io->output_fd);
	io->output_fd = fd;
}

void	redir_heredoc(t_redir *redir, t_io *io)
{
	int		status;
	char	*file;
	pid_t	pid;

	file = ft_strjoin("/tmp/.infile", ft_itoa(1));
	io->input_fd = open(file, O_CREAT, O_WRONLY, O_TRUNC, 0666);
	set_signal(IGNORE, IGNORE);
	pid = fork();
	if (pid == 0)
		child_process(redir->filename, io);
	waitpid(pid, &status, 0);
	set_signal(SHELL, IGNORE);
	close(io->input_fd);
	io->input_fd = open(file, O_RDONLY, 0644);
	free(file);
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
