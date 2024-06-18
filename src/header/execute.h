/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:21:14 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/18 14:52:27 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "minishell.h"

# define IN 1
# define OUT 2
# define HEREDOC 3
# define OUT_APPEND 4

typedef struct s_redirection {
	int						type;
	char					*filename;
	struct s_redirection	*next;
}	t_redir;

typedef struct s_iohandler {
	int	input_fd;
	int	output_fd;
	int	pipe_read_fd;
	int	pipe_write_fd;
}	t_io;

void	redir_in(t_redir *redir, t_io *io);
void	redir_out(t_redir *redir, t_io *io);
void	redir_heredoc(t_redir *redir, t_io *io);
void	redir_out_append(t_redir *redir, t_io *io);

void	redirection(t_redir *redir);

#endif