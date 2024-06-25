/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:14:14 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/25 18:37:46 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	free_double_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

char	**make_execute_env(t_list **env_list)
{
	int		i;
	int		size;
	t_list	*tmp;
	char	**result;

	size = ft_lstsize(*env_list);
	result = ft_calloc(size + 1, sizeof(char *));
	if (!result)
		memory_error();
	i = 0;
	tmp = *env_list;
	while (tmp)
	{
		result[i] = ft_strdup(((t_env *)(tmp->content))->data);
		if (!result[i])
		{
			free_double_arr(result);
			memory_error();
		}
		tmp = tmp->next;
		i++;
	}
	return (result);
}

void	execute_user_defined(t_ASTNode *node, t_list *env_list)
{
	char	**execute_env;

	execute_env = make_execute_env(&env_list);
	if (execve(node->cmd->path, node->cmd->argv, execute_env) == -1)
	{
		execve_error();
	}
}

void	execute_fork(t_ASTNode *node, t_list *env_list)
{
	pid_t	pid;
	pid_t	child_pid;
	int		status;

	pid = fork();
	if (pid == -1)
		ft_putendl_fd("error pid\n", STDERR_FILENO);
	else if (pid == 0)
	{
		set_signal(DEFAULT, DEFAULT);
		if (built_in(node, env_list) == 0)
			return ;
		else
			execute_user_defined(node, env_list);
	}
	else
	{
		child_pid = waitpid(pid, &status, WUNTRACED);
		if (status != 0)
			close(STDIN_FILENO);
		set_parent_status(status);
	}
}
