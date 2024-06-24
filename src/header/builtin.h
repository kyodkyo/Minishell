/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:31:50 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/24 19:23:21 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# include "astree.h"
# include "structure.h"
# include "env_utils.h"

int		built_in(t_ASTNode *node, t_list *env_list);
void	cd(t_ASTNode *node, t_list *env_list);
void	echo(t_ASTNode *node);
void	env(t_list *env_list);
void	built_in_exit(t_ASTNode *node);
void	export(t_ASTNode *node, t_list *env_list);
void	pwd();
void	unset(t_ASTNode *node, t_list *env_list);

#endif