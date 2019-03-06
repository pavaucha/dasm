/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavaucha <pavaucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:32:20 by pavaucha          #+#    #+#             */
/*   Updated: 2019/03/06 14:56:15 by pavaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reverse.h"

static char		*open_file(char *name)
{
	int		i;
	char	*str;

	i = 0;
	while (name[i])
		i++;
	while (name[i] != '.' && i > 0)
		i--;
	if ((str = ft_strnew((size_t)i + 2)) == NULL)
		return (NULL);
	str = ft_strncpy(str, name, (size_t)i);
	str = ft_strcat(str, ".su");
	return (str);
}

int				main(int ac, char **av)
{
	t_champ		champ;
	char		*str;

	if (ac != 2)
	{
		ft_printf("Please enter a champ to this format\n");
		ft_printf("		./reverse_cor <#####.cor>\n");
		return (1);
	}
	if (parsing_champ(av[1], &champ) != 1)
		return (1);
	if ((str = (open_file(av[1]))) == NULL)
	{
		ft_strdel(&str);
		return (ft_error(7));
	}
	if (complete_file(open(str, O_WRONLY
		| O_TRUNC | O_CREAT, 0600), champ) != 0)
	{
		ft_strdel(&str);
		return (-1);
	}
	ft_printf("Writing output program to %s\n", str);
	ft_strdel(&str);
	return (1);
}
