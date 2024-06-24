/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:40:10 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 22:35:54 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	free_path(char **paths)
{
	int	i;

	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
}

char	**get_path_value(t_list *env_list)
{
	char	*value;
	char	**paths;

	value = get_env_value(env_list, "PATH");
	paths = ft_split(value, ':');
	free(value);
	return (paths);
}

char	*find_path_by_env(char *cmd, t_list *env_list)
{
	int			i;
	char		*tmp;
	char		*result;
	char		**env_path;

	i = -1;
	result = NULL;
	env_path = get_path_value(env_list);
	while (env_path[++i])
	{
		tmp = ft_strjoin("/", cmd);
		result = ft_strjoin(ft_strdup(env_path[i]), tmp);
		free(tmp);
		if (access(result, F_OK) == -1)
		{
			free(result);
			result = NULL;
		}
		else
			break ;
	}
	if (env_path)
		free_path(env_path);
	return (result);
}

char	*get_cmd_path(char *cmd, t_list *env_list)
{
	char	*cur_path;
	char	*result;

	if (!cmd)
		return (NULL);
	if (ft_strncmp(cmd, "/", 1) == 0)
		result = ft_strdup(cmd);
	else if (ft_strncmp("./", cmd, 2) == 0)
	{
		cmd = ft_substr(cmd, 2, ft_strlen(cmd) - 2);
		cur_path = getcwd(NULL, 0);
		result = ft_strjoin(cur_path, ft_strdup("/"));
		result = ft_strjoin(result, cmd);
	}
	else
		result = find_path_by_env(cmd, env_list);
	return (result);
}

void	set_cmd_path(t_ASTNode *node, t_list *env_list)
{
	if (node->left != NULL)
		set_cmd_path(node->left, env_list);
	if (node->right != NULL)
		set_cmd_path(node->right, env_list);
	if (node->type == T_CMD)
		node->cmd->path = get_cmd_path(node->value, env_list);
}
