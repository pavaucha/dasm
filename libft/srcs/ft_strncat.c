/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:22:39 by lezhang           #+#    #+#             */
/*   Updated: 2017/12/04 13:28:14 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (*(s1 + len) != '\0')
		len++;
	while (*(s2 + i) != '\0' && i < n)
	{
		*(s1 + len + i) = *(s2 + i);
		i++;
	}
	*(s1 + len + i) = '\0';
	return (s1);
}