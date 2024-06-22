/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:32:56 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 01:30:25 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset(t_ASTNode *node, t_list *env_list)
{
	int		i;
	char	*target_key;

	i = 1;
	if (!node->value[1])
		return ;
	while (node->value[i])
	{
		target_key = &node->value[i];
		if (is_valid_key(&node->value[i]))
			write(1, "unset: invalid key", 18);
		else
			unset_env(&env_list, target_key);
		i++;
	}
}
