/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:02:52 by lezhang           #+#    #+#             */
/*   Updated: 2017/12/04 13:28:45 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim(char const *s)
{
	int		go;
	int		end;
	char	*str;

	end = 0;
	go = 0;
	if (s == NULL)
		return (NULL);
	while (*(s + end) != '\0')
		end++;
	end--;
	while (*(s + end) == ' ' || *(s + end) == '\t' || *(s + end) == '\n')
		end--;
	while (*(s + go) == ' ' || *(s + go) == '\t' || *(s + go) == '\n')
		go++;
	if (go > end)
		return (ft_strnew(0));
	if ((str = ft_strsub(s, go, (end - go + 1))) == NULL)
		return (NULL);
	return (str);
}
