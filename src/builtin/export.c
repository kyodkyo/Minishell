/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:30:15 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/22 17:19:51 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export(t_cmd *cmd_list, t_list *env_list, t_io *io_handler)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	if (!cmd_list->str[1])
		export_no_argv(env_list, io_handler);
	while (cmd_list->str[++i])
	{
		key = NULL;
		value = NULL;
		export_split_key_value(cmd_list->str[i], &key, &value);
		if (is_valid_key(key))
			printf("error\n");
		else
			add_env(&env_list, key, value);
		free(key);
		free(value);
	}
}
