/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 06:42:41 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/18 14:56:54 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

/** env_utils.c */
char	*get_next_key(t_list *env_list, char *prev);
void	update_env(t_env *env, char *key, char *value);
void	add_new_env(t_list **env_list, char *key, char *value);
t_env	*find_by_key(t_list *env_list, char *target_key);
void	add_env(t_list **env_list, char *key, char *value);

/** env_utils2.c */
void	to_lowercase(char *str);
t_env	*ft_envnew(void);
int		cmp_str(char *s1, char *s2);
void	init_split_key_value(char *data, char **key, char **value);
t_list	*init_envp(char **envp);

/** env_utils3.c */
void	free_env_node(t_list **node);
void	remove_key_value(t_list **env_list, t_list *list, t_list *cur);
void	unset_env(t_list **env_list, char *target_key);
int		is_valid_key(char *key);

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
void	export_no_argv(t_list *env_list);
void	combine_declare_x(t_list *env_list, char *key);

/** ft_built_in.c */
void	list_add_back(t_list **lst, t_list *new);
t_list	*list_find_last(t_list *lst);
t_list	*make_new_node(void *content);
int		count_list_size(t_list *lst);
void	*join_str(void *dst, const void *src, size_t len);

/** ft_built_in2.c */
char	*dup_str(const char *s1);
char	*combine_str(char const *s1, char const *s2);
int		copy_str_len(char *dst, const char *src, size_t dstsize);
int		compare_str(const char *s1, const char *s2, size_t n);
char	*get_substring(char const *s, unsigned int start, size_t len);

#endif