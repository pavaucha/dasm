/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 07:04:05 by mavui             #+#    #+#             */
/*   Updated: 2019/02/11 07:04:06 by mavui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strndup(const char *s1, int size)
{
	int		i;
	int		len;
	char	*s2;

	i = 0;
	len = 0;
	while (*(s1 + len) != '\0' && len < size)
		len++;
	s2 = (char*)malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	while (*(s1 + i) != '\0' && i < size)
	{
		*(s2 + i) = *(s1 + i);
		i++;
	}
	*(s2 + i) = '\0';
	return (s2);
}
