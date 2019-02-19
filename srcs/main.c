#include "reverse.h"

int 	main(int ac, char **av)
{
	t_champ		champ;

	if (ac != 2)
	{
		ft_printf("Please enter a champ to this format\n		./reverse_cor <#####.cor>\n");
		return (1);
	}
	if (parsing_champ(av[1], &champ) != 0)
		return (1);
	ft_printf("name = %s\n", champ.name);
	ft_printf("comment = %s\n", champ.comment);
	for(int i = 0;i < champ.len;i++)
	{
		printf("%.2x ", champ.instructions[i]);
	}
}
