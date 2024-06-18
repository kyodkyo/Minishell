/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 23:21:14 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/15 06:17:05 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "built_in.h"

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

int		is_valid(char *s, int i);
int		find_start_pos(char *s);
int		find_end_pos(char *s, int i);
char	*get_value(t_list *env_list, char *key);
void	change_to_value(char *result, char *front, char *env_value, char *back);
char	*make_expand_data(t_list *env_list, char *origin, int start, int end);
char	*expand_env(t_list *env_list, char *origin);
void	redirection(t_redir *redir);

#endif