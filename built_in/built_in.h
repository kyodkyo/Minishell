/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:33:59 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/15 06:28:05 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_minishell
{
	int	status;
}	t_minishell;

typedef struct s_env
{
	char	*data;
	char	*key;
	char	*value;
}	t_env;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		built_in(int argc, char **argv, char **envp);
void	cd(int argc, char **argv, char **envp, t_list *env_list);
void	echo(int argc, char **argv, char **envp);
void	env(int argc, char **argv, char **envp, t_list *env_list);
void	pwd(int argc, char **argv, char **envp);
void	built_in_exit(int argc, char **argv, char **envp);

void	combine_declare_x(t_list *env_list, char *key);
char	*get_next_key(t_list *env_list, char *prev);
void	export_no_argv(t_list *env_list);
void	export_split_key_value(char *data, char **key, char **value);
void	export(int argc, char **argv, char **envp, t_list *env_list);

void	update_env(t_env *env, char *key, char *value);
void	add_new_env(t_list **env_list, char *key, char *value);
t_env	*find_by_key(t_list *env_list, char *target_key);
void	add_env(t_list **env_list, char *key, char *value);

void	free_env_node(t_list **node);
void	remove_key_value(t_list **env_list, t_list *list, t_list *cur);
void	unset_env(t_list **env_list, char *target_key);
int		is_valid_key(char *key);
void	unset(int argc, char **argv, char **envp, t_list *env_list);

void	to_lowercase(char *str);
t_env	*ft_envnew(void);
int		cmp_str(char *s1, char *s2);
void	init_split_key_value(char *data, char **key, char **value);
t_list	*init_envp(char **envp);

void	list_add_back(t_list **lst, t_list *new);
t_list	*list_find_last(t_list *lst);
t_list	*make_new_node(void *content);
int		count_list_size(t_list *lst);
void	*join_str(void *dst, const void *src, size_t len);

char	*dup_str(const char *s1);
char	*combine_str(char const *s1, char const *s2);
int		copy_str_len(char *dst, const char *src, size_t dstsize);
int		compare_str(const char *s1, const char *s2, size_t n);
char	*get_substring(char const *s, unsigned int start, size_t len);


void	error(void);

#endif