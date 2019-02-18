/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 09:59:04 by lezhang           #+#    #+#             */
/*   Updated: 2017/12/04 12:42:35 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (alst == NULL)
		return ;
	while ((*alst) != NULL)
	{
		temp = (*alst)->next;
		(*del)((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
		*alst = temp;
	}
}
