/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_t.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 02:19:23 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 21:38:00 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_T_H
# define MINISHELL_T_H
# include "astree.h"

typedef struct s_env
{
	char	*data;
	char	*key;
	char	*value;
}	t_env;

typedef struct s_minishit
{
	t_list		*env_list;
	t_ASTNode	*astree_root;
}	t_mini;

#endif