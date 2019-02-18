/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:40:47 by lezhang           #+#    #+#             */
/*   Updated: 2017/12/04 12:44:43 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		found;

	i = 0;
	found = 0;
	c = (char)c;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
		{
			found = 1;
			break ;
		}
		i++;
	}
	if (c == '\0')
		found = 1;
	if (found == 0)
		return (NULL);
	return ((char*)s + i);
}
