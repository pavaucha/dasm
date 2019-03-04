#include "reverse.h"
#include "libft.h"


static int  write_dir(int fd, t_champ champ, int i)
{
	write(fd, "%", 1);
	write(fd, ft_itoa(champ.instructions[i]), ft_strlen(ft_itoa(champ.instructions[i])));
	i++;
	write(fd, ft_itoa(champ.instructions[i]), ft_strlen(ft_itoa(champ.instructions[i])));
	i++;
    write(fd, ft_itoa(champ.instructions[i]), ft_strlen(ft_itoa(champ.instructions[i])));
	i++;
    write(fd, ft_itoa(champ.instructions[i]), ft_strlen(ft_itoa(champ.instructions[i])));
    return (i + 1);
}

static int  write_reg(int fd, t_champ champ, int i)
{
	write(fd, "r", 1);
    write(fd, ft_itoa(champ.instructions[i]), ft_strlen(ft_itoa(champ.instructions[i])));
    return (i + 1);    
}

static int  write_ind(int fd,  t_champ champ, int i, int d)
{
	if (d == 9 || d == 10 || d == 11 || d == 12 || d == 14 || d == 15)
		write(fd, "%", 1);
    write(fd, ft_itoa(champ.instructions[i]), ft_strlen(ft_itoa(champ.instructions[i])));
	i++;
    write(fd, ft_itoa(champ.instructions[i]), ft_strlen(ft_itoa(champ.instructions[i])));
    return (i + 1);
}

int         get_ocp(int fd, t_champ champ, int *i)
{
	char	*ocp;
	int		j;
	int		d;
	char	*tmp;

	j = 0;
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
	if ((ocp = ft_itoa_base(champ.instructions[*i], 2, 1)) == NULL)
		return (-1);
	if (ft_strlen(ocp) < 8)
	{
		tmp = ocp;
		ocp = ft_strjoin("0", ocp);
		ft_strdel(&tmp);
	}
    *i = *i + 1;
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
