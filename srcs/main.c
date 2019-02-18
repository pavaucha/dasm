#include "reverse.h"

int 	main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("Please enter a champ to this format\n		./reverse_cor <#####.cor>\n");
		return (1);
	}
	if (parsing_champ(av[1]) != 0)
		return (1);
}
