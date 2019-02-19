/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:09:17 by lezhang           #+#    #+#             */
/*   Updated: 2017/12/04 12:42:29 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst == NULL)
		new->next = NULL;
	else
	{
		new->next = *alst;
		(*alst) = new;
	}
}