/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_expend.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonshin <woonshin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 06:13:12 by woonshin          #+#    #+#             */
/*   Updated: 2024/06/18 01:42:19 by woonshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"


/**
 * return 0 -> 변경 없음.
 * return 1 -> 변경 있음.
*/
int	tokenize_expend(t_token **token_lst, t_token *token)
{
	t_token	*back;
	char	*new_line;

	back = token_lst_back(*token_lst);
	if (back && back->type == T_REDIR_HERE)
		return (0);
	
	// new_line = dollar 함수 호출, 새로운 문자열 받기
	// spliter_blank 함수 호출하고
	// 연결리스트 순차적으로 추가. 기존 token free

	// 변경 없을시 return 0
	return (0);
}
