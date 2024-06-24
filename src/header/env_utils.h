/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:39:24 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/24 19:23:04 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H
# define ENV_UTILS_H
# include "libft.h"
# include "utils.h"
# include "struct.h"

// env_utils.c
char	*get_next_key(t_list *env_list, char *prev);
t_env	*find_by_key(t_list *env_list, char *target_key);
void	update_env(t_env *env, char *key, char *value);
void	add_new_env(t_list **env_list, char *key, char *value);
void	add_env(t_list **env_list, char *key, char *value);

// env_utils2.c
void	free_env_node(t_list **node);
void	remove_key_value(t_list **env_list, t_list *list, t_list *cur);
void	unset_env(t_list **env_list, char *target_key);
void	init_split_key_value(char *data, char **key, char **value);
t_list	*init_envp(char **envp);

// env_utils3.c
void	to_lowercase(char *str);
int		is_valid_key(char *key);
t_env	*ft_envnew(void);
int		cmp_str(char *s1, char *s2);

#endif