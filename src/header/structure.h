/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakang <dakang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:11:03 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/25 21:28:05 by dakang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H
# include "libft.h"

typedef struct s_command
{
	char	*name;
	char	*path;
	char	**argv;
	int		argc;
}	t_cmd;

typedef struct s_ASTNode
{
	int					type;
	char				*value;
	struct s_ASTNode	*left;
	struct s_ASTNode	*right;
	t_cmd				*cmd;
	struct s_ASTNode	*next;
	int					pipefd[2];
	pid_t				pid;
	int					status;
}	t_ASTNode;

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