/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:21:14 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/20 18:47:14 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "./minishell.h"

# define IN 1
# define OUT 2
# define HEREDOC 3
# define OUT_APPEND 4

typedef struct s_command {
	t_io		*io_handler;
	t_cmd		*cmd_lst;
	t_redir		*redir_lst;
	t_command	*next;
}	t_command;

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

typedef struct s_cmd{
	char			**str;
	struct s_cmd	*next;
}	t_cmd;

/** execute_heredoc.c */
void	child_process(char *delimiter, t_io *io);

/** execute_redirection.c */
void	redir_in(t_redir *redir, t_io *io);
void	redir_out(t_redir *redir, t_io *io);
void	redir_heredoc(t_redir *redir, t_io *io);
void	redir_out_append(t_redir *redir, t_io *io);

/** execute.c */
void	exec_redir(t_redir *redir, t_io	*io);
void	exec_cmd(t_command *command);
void	execute(t_command *command);

void	error(void);

#endif