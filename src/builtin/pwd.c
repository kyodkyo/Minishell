/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:32:46 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/25 18:58:24 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	pwd(void)
{
	char	*current;

	current = getcwd(NULL, 0);
	if (current)
	{
		write(STDOUT_FILENO, current, ft_strlen(current));
		write(STDOUT_FILENO, "\n", 1);
	}
	else
		perror("pwd");
	free(current);
}
