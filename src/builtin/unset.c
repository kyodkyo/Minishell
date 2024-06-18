/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:32:56 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/18 14:55:39 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	unset(int argc, char **argv, char **envp, t_list *env_list)
{
	int		i;
	char	*target_key;

	i = 1;
	if (!argv[1])
		return ;
	while (argv[i])
	{
		target_key = argv[i];
		if (is_valid_key(argv[i]))
			write(2, "unset: invalid key", 18);
		else
			unset_env(&env_list, target_key);
		i++;
	}
}
