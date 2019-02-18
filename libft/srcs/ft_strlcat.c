/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:59:51 by lezhang           #+#    #+#             */
/*   Updated: 2018/04/11 15:20:23 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	max;
	size_t	len_dst;
	size_t	len_src;

	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	max = size - len_dst - 1;
	if (len_dst >= size)
		return (size + len_src);
	while (*(src + i) != '\0' && i < max)
	{
		*(dst + len_dst + i) = *(src + i);
		i++;
	}
	*(dst + len_dst + i) = '\0';
	return (len_dst + len_src);
}
