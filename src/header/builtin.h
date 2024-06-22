/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:33:59 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/21 02:10:26 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"
# include "execute.h"

int		built_in(t_cmd *cmd_list, t_list *env_list, t_io *io_handler);
void	cd(t_cmd *cmd_list, t_list *env_list);
void	echo(t_cmd *cmd_list, t_io *io_handler);
void	env(t_list *env_list, t_io *io_handler);
void	built_in_exit(t_cmd *cmd_list);
void	export(t_cmd *cmd_list, t_list *env_list, t_io *io_handler);
void	pwd(t_io *io_handler);
void	unset(t_cmd *cmd_list, t_list *env_list);

void	error(void);

#endif