/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 02:19:23 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 02:39:19 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>
# include <termios.h>
# include <dirent.h>
# include "astree.h"
# include "minishell_t.h"
# include "libft.h"
# include "parse.h"


int	g_status_code;


// signal
# define HEREDOC 14

// redirect
# define R_IN 1
# define R_OUT 2
# define R_HEREDOC 3
# define R_OUT_APPEND 4

/** signal.c */
void	sig_shell(int sig);
void	sig_heredoc(int sig);
void	set_signal(int s_int, int s_quit);
void	init_signal(void);

/** execute_child.c */
void	execute_user_defined(t_ASTNode *node, t_list *env_list, t_io *io);
void	execute_fork(t_ASTNode *node, t_list *env_list, t_io *io);

/** execute_dup.c */
void	check_pipe_read(t_io *io);
void	set_process_io(t_io *io);
void	close_pipe(t_io *io);
void	close_file(t_io *io);

/** execute_redir.c */
void	redir_in(t_ASTNode *node, t_io *io);
void	redir_out(t_ASTNode *node, t_io *io);
void	redir_heredoc(t_ASTNode *node, t_io *io);
void	redir_out_append(t_ASTNode *node, t_io *io);
void	heredoc_child_process(char *delimiter, t_io *io);

/** execute_utils.c */
char	*is_valid_path(char **path, char *result, char *tmp);
void	check_slash_exist(char *cmd);
char	*get_execute_path(char **path, char *cmd);
void	execve_error(void);
void	set_parent_status(int status);

/** execute.c */
void	check_next_pipe(t_ASTNode *node, t_io *io);
void	execute_command(t_ASTNode *node, t_list *env_list, t_io *io);
void	execute_node(t_ASTNode *node, t_list *env_list, t_io *io);
void	execute_tree(t_ASTNode *node, t_list *env_list, t_io *io);

/** built_in.c */
int		built_in(t_ASTNode *node, t_list *env_list, t_io *io);
void	cd(t_ASTNode *node, t_list *env_list);
void	echo(t_ASTNode *node, t_io *io_handler);
void	env(t_list *env_list, t_io *io_handler);
void	built_in_exit(t_ASTNode *node);
void	export(t_ASTNode *node, t_list *env_list, t_io *io_handler);
void	pwd(t_io *io_handler);
void	unset(t_ASTNode *node, t_list *env_list);

void	error(void);

/** env_utils.c */
char	*get_next_key(t_list *env_list, char *prev);
t_env	*find_by_key(t_list *env_list, char *target_key);
void	update_env(t_env *env, char *key, char *value);
void	add_new_env(t_list **env_list, char *key, char *value);
void	add_env(t_list **env_list, char *key, char *value);

/** env_utils2.c */
void	free_env_node(t_list **node);
void	remove_key_value(t_list **env_list, t_list *list, t_list *cur);
void	unset_env(t_list **env_list, char *target_key);
void	init_split_key_value(char *data, char **key, char **value);
t_list	*init_envp(char **envp);

/** env_utils3.c */
void	to_lowercase(char *str);
int		is_valid_key(char *key);
t_env	*ft_envnew(void);
int		cmp_str(char *s1, char *s2);

/** expand_utils.c */
int		is_valid(char *s, int i);
int		find_start_pos(char *s);
int		find_end_pos(char *s, int i);
char	*get_value(t_list *env_list, char *key);

/** expand.c */
void	change_to_value(char *result, char *front, char *env_value, char *back);
char	*make_expand_data(t_list *env_list, char *origin, int start, int end);
char	*expand_env(t_list *env_list, char *origin);

/** export_utils.c */
void	export_split_key_value(char *data, char **key, char **value);
void	export_no_argv(t_list *env_list, t_io *io_handler);
void	combine_declare_x(t_list *env_list, char *key, t_io *io_handler);

/** ft_built_in.c */
void	*str_join_len(void *dst, const void *src, size_t len);
char	*combine_str(char const *s1, char const *s2);
int		copy_str_len(char *dst, const char *src, size_t dstsize);
int		compare_str(const char *s1, const char *s2, size_t n);
char	*get_substr(char const *s, unsigned int start, size_t len);

#endif
