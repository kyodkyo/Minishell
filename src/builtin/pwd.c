/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:32:46 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/22 17:19:51 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(t_io *io_handler)
{
	char	*current;

	current = getcwd(NULL, 0);
	if (current)
	{
		write(io_handler->output_fd, current, ft_strlen(current));
		write(io_handler->output_fd, "\n", 1);
	}
	else
		printf("error\n");
	free(current);
}
