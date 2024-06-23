/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:32:46 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 21:37:00 by woonshin         ###   ########.fr       */
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
		printf("error\n");
	free(current);
}
