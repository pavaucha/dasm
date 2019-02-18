/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:01:02 by lezhang           #+#    #+#             */
/*   Updated: 2017/12/04 12:44:13 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putendl_fd(char const *s, int fd)
{
	int		i;
	char	endl;

	i = 0;
	endl = '\n';
	if (s == NULL)
		return ;
	while (*(s + i) != '\0')
		i++;
	write(fd, s, i);
	write(fd, &endl, 1);
}
