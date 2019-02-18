/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:56:50 by lezhang           #+#    #+#             */
/*   Updated: 2017/12/04 13:28:33 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	int		found;

	i = 0;
	found = 0;
	if (*(needle + 0) == '\0')
		return ((char*)haystack);
	while (*(haystack + i) != '\0')
	{
		if (*(haystack + i) == *(needle + 0))
		{
			j = 0;
			while ((*(haystack + i + j) == *(needle + j)) &&
					*(haystack + i + j++) != '\0')
				if (*(needle + j) == '\0')
					found = 1;
		}
		if (found == 1)
			break ;
		i++;
	}
	if (found == 0)
		return (NULL);
	return ((char*)(haystack + i));
}
