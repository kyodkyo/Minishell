/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakyo <dakyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 06:13:46 by dakyo             #+#    #+#             */
/*   Updated: 2024/06/15 06:23:44 by dakyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

void	list_add_back(t_list **lst, t_list *new)
{
	t_list	*prev;

	prev = *lst;
	if (prev == NULL)
	{
		*lst = new;
	}
	else
	{
		while (prev->next != NULL)
			prev = prev->next;
		prev->next = new;
	}
}

t_list	*list_find_last(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst -> next;
	}
	return (lst);
}

t_list	*make_new_node(void *content)
{
	t_list	*res;

	res = (t_list *)malloc(sizeof(t_list));
	if (res == NULL)
		return (NULL);
	res -> content = content;
	res -> next = NULL;
	return (res);
}

int	count_list_size(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst -> next;
		count++;
	}
	return (count);
}

void	*join_str(void *dst, const void *src, size_t len)
{
	size_t	index;

	index = 0;
	if (!dst && !src)
		return (dst);
	while (index < len)
	{
		((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
		index++;
	}
	return (dst);
}
