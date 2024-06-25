/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:29:18 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/25 20:29:07 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	memory_error(void)
{
	ft_putendl_fd("error: memory allocation error", STDERR_FILENO);
	g_status_code = 137;
	exit(137);
}

void	file_open_error(char *value)
{
	perror(value);
	g_status_code = 1;
}
