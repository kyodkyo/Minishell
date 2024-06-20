/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 00:35:44 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/21 02:07:26 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>
# include <termios.h>

# include "../libft/libft.h"

typedef struct s_env
{
	char	*data;
	char	*key;
	char	*value;
}	t_env;

// signal
# define DEFAULT 11
# define IGNORE 12
# define SHELL 13
# define HEREDOC 14

int	g_status_code;

void	sig_shell(int sig);
void	sig_heredoc(int sig);
void	set_signal(int s_int, int s_quit);
void	init_signal(void);

#endif