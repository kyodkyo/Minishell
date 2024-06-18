/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 00:35:44 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/18 14:43:32 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>

# include "parse.h"
# include "builtin.h"
# include "execute.h"
# include "utils.h"
# include "libft.h"

typedef struct s_env
{
	char	*data;
	char	*key;
	char	*value;
}	t_env;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

#endif