/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lezhang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 10:38:32 by lezhang           #+#    #+#             */
/*   Updated: 2017/12/04 12:42:22 by lezhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static	int	ft_pow(int x, int y)
{
	if (y == 0)
		return (1);
	else if (y > 0)
		x *= ft_pow(x, y - 1);
	return (x);
}

static char	*ft_newstr_itoa(int n, int len, long save, char *str)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		*(str + i) = '-';
		i++;
	}
	len--;
	while (len >= 0)
	{
		*(str + i) = (save / ft_pow(10, len)) + '0';
		save %= ft_pow(10, len);
		len--;
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	int		len;
	long	temp;
	long	save;
	char	*str;

	len = 0;
	temp = n;
	if (temp < 0)
		temp *= -1;
	save = temp;
	while (temp > 0)
	{
		len++;
		temp /= 10;
	}
	if ((str = (char*)malloc(sizeof(char) * (len + 2))) == NULL)
		return (NULL);
	str = ft_newstr_itoa(n, len, save, str);
	if (n == 0)
	{
		*(str + 0) = '0';
		*(str + 1) = '\0';
	}
	return (str);
}
