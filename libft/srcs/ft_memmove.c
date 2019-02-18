/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:44:58 by lezhang           #+#    #+#             */
/*   Updated: 2017/12/04 13:29:20 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*p_dst;

	p_dst = dst;
	i = 0;
	if ((dst - src) < 0)
	{
		while (i < len)
		{
			*(p_dst + i) = *(char*)(src + i);
			i++;
		}
	}
	else if ((dst - src) > 0)
	{
		while (i < len)
		{
			*(p_dst + len - i - 1) = *(char*)(src + len - i - 1);
			i++;
		}
	}
	return (p_dst);
}
