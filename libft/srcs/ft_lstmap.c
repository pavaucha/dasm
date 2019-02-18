/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:15:03 by lezhang           #+#    #+#             */
/*   Updated: 2017/12/04 12:42:54 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*result;
	t_list	*t;

	if (lst == NULL || f == NULL)
		return (NULL);
	t = (*f)(lst);
	if ((new = ft_lstnew(t->content, t->content_size)) == NULL)
		return (NULL);
	result = new;
	while (lst->next != NULL)
	{
		t = (*f)(lst->next);
		if ((result->next = ft_lstnew(t->content, t->content_size)) == NULL)
			return (NULL);
		result = result->next;
		lst = lst->next;
	}
	return (new);
}
