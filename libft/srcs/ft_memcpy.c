/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:08:37 by lezhang           #+#    #+#             */
/*   Updated: 2017/12/04 12:43:26 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*p_dest;

	i = 0;
	p_dest = dest;
	while (i < n)
	{
		*(p_dest + i) = *(char*)(src + i);
		i++;
	}
	return (p_dest);
}
