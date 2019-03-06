#include "reverse.h"
#include "libft.h"


static int  write_dir(int fd, t_champ champ, int i)
{
	char			*str;
	unsigned int	j;

	str = ft_strjoin(ft_itoa_base(champ.instructions[i], 2, 1), ft_itoa_base(champ.instructions[i + 1], 2, 1));
	str = ft_strjoin(str, ft_itoa_base(champ.instructions[i + 2], 2, 1));
	str = ft_strjoin(str, ft_itoa_base(champ.instructions[i + 3], 2, 1));
	j = ft_atoi_base(str, 2);
	str = ft_itoa(j);
	write(fd, "%", 1);
	write(fd, str, ft_strlen(str));
    return (i + 4);
}

static int  write_reg(int fd, t_champ champ, int i)
{
	unsigned int	j;
	char			*str;

	str = ft_itoa_base(champ.instructions[i], 2, 1);
	j = ft_atoi_base(str, 2);
	str = ft_itoa(j);
	write(fd, "r", 1);
	write(fd, str, ft_strlen(str));
    return (i + 1);    
}

static int  write_ind(int fd,  t_champ champ, int i, int d)
{
	unsigned int	j;
	char			*str;
	
	str = ft_strjoin(ft_itoa_base(champ.instructions[i], 2, 1), ft_itoa_base(champ.instructions[i + 1], 2, 1));
	j = ft_atoi_base(str, 2);
	if (d == 9 || d == 10 || d == 11 || d == 12 || d == 14 || d == 15)
		write(fd, "%", 1);
	str = ft_itoa(j);
	write(fd, str, ft_strlen(str));
    return (i + 2);
}

int				complete_ocp(t_champ champ, int fd, int *i)
{
	int		d;

	d = champ.instructions[*i - 1];
    if (d == 9 || d == 12 || d == 15)
    {
		*i = write_ind(fd, champ, *i, d);
        write(fd, "\n", 1);
    	return (1);
    }
    if (d == 1)
    {
		*i = write_dir(fd, champ, *i);
        write(fd, "\n", 1);
		return (1);
    }
	return (0);
}

int			write_instruction(t_champ champ, char *ocp, int *i, int fd)
{
	int				j;
	int				d;

	j = 0;
	d = champ.instructions[*i - 2];
	while (j < ft_strlen(ocp))
	{
		if (ocp[j] == '0' && ocp[j + 1] == '1')
			*i = write_reg(fd, champ, *i);
		else if (ocp[j] == '1' && ocp[j + 1] == '1')
			*i = write_ind(fd, champ, *i, d);
		else if (ocp[j] == '1' && ocp[j + 1] == '0' && (d == 9
				|| d == 10 || d == 11 || d == 12 || d == 14 || d == 15))
			*i = write_ind(fd, champ, *i, d);
		else if (ocp[j] == '1' && ocp[j + 1] == '0')
			*i = write_dir(fd, champ, *i);
		j += 2;
		if (j + 1 < ft_strlen(ocp) && ocp[j] == '0' && ocp[j + 1] == '0')
		{
            write(fd, "\n", 1);
			ft_strdel(&ocp);
			return (1);
		}
        if (j < 6)
            write(fd, ", ", 2);
	}
	return (1);
}