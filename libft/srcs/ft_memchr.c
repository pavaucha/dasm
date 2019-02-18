/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:09:53 by lezhang           #+#    #+#             */
/*   Updated: 2017/12/04 12:43:19 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	int					found;
	const unsigned char	*str;

	str = s;
	i = 0;
	found = 0;
	c = (unsigned char)c;
	while (i < n)
	{
		if (*(unsigned char*)(str + i) == c)
		{
			found = 1;
			break ;
		}
		i++;
	}
	if (found == 0)
		return (0);
	return ((unsigned char*)(str + i));
}
