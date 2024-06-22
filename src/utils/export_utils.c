/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:26:22 by dakyo             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/06/22 17:42:23 by dakyo            ###   ########.fr       */
=======
/*   Updated: 2024/06/22 17:10:52 by woonshin         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_split_key_value(char *data, char **key, char **value)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(data);
	while (data[i] && data[i] != '=')
		i++;
	*key = get_substr(data, 0, i);
	if (len - i)
		*value = get_substr(data, i + 1, len - i);
	else
		*value = NULL;
}

void	export_no_argv(t_list *env_list, t_io *io_handler)
{
	int		i;
	int		size;
	char	*prev_key;
	char	*cur_key;

	i = 0;
	size = ft_lstsize(env_list);
	prev_key = NULL;
	cur_key = NULL;
	while (i < size)
	{
		cur_key = get_next_key(env_list, prev_key);
		combine_declare_x(env_list, cur_key, io_handler);
		prev_key = cur_key;
		i++;
	}
}

void	combine_declare_x(t_list *env_list, char *key, t_io *io_handler)
{
	char	*res;
	t_env	*env;

	res = NULL;
	env = find_by_key(env_list, key);
	write(io_handler->output_fd, "declare -x ", 11);
	write(io_handler->output_fd, key, ft_strlen(key));
	if (env->value)
	{
		write(io_handler->output_fd, "=\"", 2);
		write(io_handler->output_fd, env->value, ft_strlen(env->value));
		write(io_handler->output_fd, "\"", 1);
	}
	write(io_handler->output_fd, "\n", 1);
}
