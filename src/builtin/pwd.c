/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:32:46 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/19 16:26:18 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	pwd(int argc, char **argv, char **envp)
{
	char	*current;

	current = getcwd(NULL, 0);
	if (current)
	{
		write(1, current, ft_strlen(current));
		write(1, "\n", 1);
	}
	else
		printf("error\n");
}
