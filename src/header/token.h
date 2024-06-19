/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:23:29 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/19 17:55:43 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# define T_NULL 0
# define T_WORD 1
# define T_PIPE 2
# define T_REDIR_IN 3
# define T_REDIR_OUT 4
# define T_REDIR_HERE 5
# define T_REDIR_APPEND 6
# define T_REDIR_ERR 7

typedef struct s_token {
	int				type;
	char			*str;
	struct s_token	*next;
}	t_token;

#endif