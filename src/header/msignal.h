/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msignal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:24:20 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/23 21:30:15 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSIGNAL_H
# define MSIGNAL_H
# include <signal.h>
# include <termios.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <stdlib.h>

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