/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:47:11 by lezhang           #+#    #+#             */
/*   Updated: 2017/12/04 12:43:13 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*p_dst;
	int				found;

	i = 0;
	found = 0;
	p_dst = (unsigned char*)dst;
	c = (unsigned char)c;
	while (i < n)
	{
		*(p_dst + i) = *(unsigned char*)(src + i);
		if (*(unsigned char*)(src + i) == c)
		{
			found = 1;
			break ;
		}
		i++;
	}
	if (found == 0)
		return (0);
	return (p_dst + i + 1);
}
