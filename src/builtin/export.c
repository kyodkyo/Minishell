/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:30:15 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/18 14:28:03 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	export(int argc, char **argv, char **envp, t_list *env_list)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	if (!argv[1])
		export_no_argv(env_list);
	while (argv[++i])
	{
		key = NULL;
		value = NULL;
		export_split_key_value(argv[i], &key, &value);
		if (is_valid_key(key))
			error();
		else
			add_env(&env_list, key, value);
		free(key);
		free(value);
	}
}