/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:32:46 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/06 02:46:03 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

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
		error();
}
