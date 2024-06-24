/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:23:09 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/23 22:36:18 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H
# include "astree.h"
# include "msignal.h"
# include "builtin.h"
# include <errno.h>
# include <fcntl.h>
# include <dirent.h>

void	execute(t_ASTNode *node, t_list *env_list);

void	execute_fork(t_ASTNode *node, t_list *env_list);
void	execute_node(t_ASTNode *node, t_list *env_list);

void	redir_in(t_ASTNode *node);
void	redir_out(t_ASTNode *node);
void	redir_heredoc(t_ASTNode *node);
void	redir_out_append(t_ASTNode *node);

char	*is_valid_path(char **path, char *result, char *tmp);
void	execve_error(void);
void	set_parent_status(int status);


// execute_path
void	free_path(char **paths);
char	**get_path_value(t_list *env_list);
char	*find_path_by_env(char *cmd, t_list *env_list);
char	*get_cmd_path(char *cmd, t_list *env_list);
void	set_cmd_path(t_ASTNode *node, t_list *env_list);

#endif