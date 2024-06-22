/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 02:19:23 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 01:24:04 by dakyo            ###   ########.fr       */
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

# include "libft.h"

int	g_status_code;

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

// redirect
# define R_IN 1
# define R_OUT 2
# define R_HEREDOC 3
# define R_OUT_APPEND 4

typedef struct s_ASTNode
{
	int					type;
	char				*value; // filename, cmd, arg, 등
	struct s_ASTNode	*left;
	struct s_ASTNode	*right;
	struct s_ASTNode	*next;
}	t_ASTNode;

typedef struct s_minishit
{
	t_list		*env_list;
	t_ASTNode	*astree_root;
}	t_mini;

typedef struct s_redirection {
	int						type;
	char					*filename;
	struct s_redirection	*next;
}	t_redir;

typedef struct s_iohandler {
	int	input_fd;
	int	output_fd;
	int	pipe[2];
	int	prev_pipe;
	int	next_pipe;
	int	pipe_read_fd;
	int	pipe_write_fd;
}	t_io;

typedef struct s_cmd{
	char			**str;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_command {
	char				**path;
	t_io				*io_handler;
	t_cmd				*cmd_lst;
	t_redir				*redir_lst;
	struct s_command	*next;
}	t_command;

# define T_NULL 0
# define T_WORD 1
# define T_CMD 2
# define T_ARG 3
# define T_PIPE 4
# define T_REDIR_IN 5
# define T_REDIR_OUT 6
# define T_REDIR_HERE 7
# define T_REDIR_APPEND 8
# define T_REDIR_ERR 9

typedef struct s_token {
	int				type;
	char			*str;
	struct s_token	*next;
}	t_token;

/** signal.c */
void	sig_shell(int sig);
void	sig_heredoc(int sig);
void	set_signal(int s_int, int s_quit);
void	init_signal(void);

void	tokenize(t_mini *mini, t_token **token_lst, char *line);

// token lst
void	add_token(t_token **token_lst, t_token *token);
t_token	*new_token(char *line, int l, int r);
t_token	*token_lst_back(t_token *token_lst);
void	token_lst_free(t_token **token_lst);
void	token_free(t_token *token);

// utils
int		is_quotation_str(char *str, int l, int r);
int		is_delimiter(char c);
int		ft_strcmp(const char *s1, char *s2);
int		get_token_type(const char *str);

// dollar 
int	tokenize_expend(t_mini *mini, t_token **token_lst, t_token *token);

t_ASTNode	*astree(t_token *tokens);
void 		print_ast(t_ASTNode *node, int level);
void 		free_ast(t_ASTNode *node);

t_token	*parse(t_mini *mini, char *input);

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