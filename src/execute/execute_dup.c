/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_dup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 00:58:07 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 02:34:32 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_pipe_read(t_io *io)
{
	if (io->prev_pipe == 1)
	{
		if (io->pipe_read_fd != STDIN_FILENO)
		{
			dup2(io->pipe_read_fd, STDIN_FILENO);
			close(io->pipe_read_fd);
		}
	}
	if (io->next_pipe == 1)
	{
		close(io->pipe[1]);
		dup2(io->pipe_write_fd, STDOUT_FILENO);
		close(io->pipe_write_fd);
	}
}

void	set_process_io(t_io *io)
{
	if (io->input_fd != STDIN_FILENO)
		dup2(io->input_fd, STDIN_FILENO);
	if (io->output_fd != STDOUT_FILENO)
		dup2(io->output_fd, STDOUT_FILENO);
}

void	close_pipe(t_io *io)
{
	if (io->prev_pipe == 1)
	{
		close(io->pipe_read_fd);
		io->next_pipe = 0;
	}
	if (io->next_pipe == 1)
	{
		close(io->pipe[1]);
		io->next_pipe = 0;
		io->pipe_read_fd = io->pipe[0];
		io->prev_pipe = 1;
	}
}

void	close_file(t_io *io)
{
	if (io->input_fd != STDIN_FILENO)
		close(io->input_fd);
	if (io->output_fd != STDOUT_FILENO)
		close(io->output_fd);
}
