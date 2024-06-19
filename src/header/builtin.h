/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:33:59 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/19 16:10:27 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "./minishell.h"

int		built_in(int argc, char **argv, char **envp);
void	cd(int argc, char **argv, char **envp, t_list *env_list);
void	echo(int argc, char **argv, char **envp);
void	env(int argc, char **argv, char **envp, t_list *env_list);
void	pwd(int argc, char **argv, char **envp);
void	built_in_exit(int argc, char **argv, char **envp);
void	unset(int argc, char **argv, char **envp, t_list *env_list);
void	export(int argc, char **argv, char **envp, t_list *env_list);

void	error(void);

#endif