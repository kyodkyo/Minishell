/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:33:59 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/06 01:59:41 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_env
{
	char	*data;
	char	*key;
	char	*value;
}	t_env;

int		built_in(int argc, char **argv, char **envp);
void	cd(int argc, char **argv, char **envp, t_list *env_list);
void	echo(int argc, char **argv, char **envp);
void	env(int argc, char **argv, char **envp, t_list *env_list);
void	built_in_exit(int argc, char **argv, char **envp);
t_env	*ft_envnew(void);
void	init_split_key_value(char *data, char **key, char **value);
t_list	*init_envp(char **envp);
void	export_split_key_value(char *data, char **key, char **value);
int		ft_strcmp(char *s1, char *s2);
char	*get_next_key(t_list *env_list, char *prev);
t_env	*find_by_key(t_list *env_list, char *target_key);
void	combine_declare_x(t_list *env_list, char *key);
void	export_no_argv(t_list *env_list);
void	update_env(t_env *env, char *key, char *value);
void	add_new_env(t_list **env_list, char *key, char *value);
void	add_env(t_list **env_list, char *key, char *value);
void	export(int argc, char **argv, char **envp, t_list *env_list);
void	pwd(int argc, char **argv, char **envp);
void	free_env_node(t_list **node);
void	remove_key_value(t_list **env_list, t_list *list, t_list *cur);
void	unset_env(t_list **env_list, char *target_key);
int		is_valid_key(char *key);
void	unset(int argc, char **argv, char **envp, t_list *env_list);
void	error();

#endif