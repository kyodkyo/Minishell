/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:01:55 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/23 12:06:42 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

void	free_path(char **paths);
char	**get_path_value(t_list *env_list);
char	*find_path_by_env(char *cmd, t_list *env_list);
char	*get_cmd_path(char *cmd, t_list *env_list);
void	set_cmd_path(t_ASTNode *node, t_list *env_list);

#endif
