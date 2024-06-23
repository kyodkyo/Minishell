/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 07:41:28 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/23 15:52:52 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTREE_H
# define ASTREE_H
# include "token.h"
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
	struct s_ASTNode	*next;
	char				*path;
	t_cmd				*cmd;
}	t_ASTNode;

t_ASTNode	*astree(t_token *tokens);
void		print_ast(t_ASTNode *node, int level);
void		free_ast(t_ASTNode *node);

// utiles
int			is_redirect(t_token *token);
t_ASTNode	*create_node(int type, char *value);
void		add_redirection(t_ASTNode *command_node, t_token **token);
void		add_argument(t_ASTNode *command_node, t_token *token, int *cmd_set);
void		free_ast(t_ASTNode *node);

// cmd
void	new_cmd(t_ASTNode *node);

#endif