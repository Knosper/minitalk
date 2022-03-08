
#include "minitalk.h"

void	send_tserver(char c, int pid)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		usleep(5500);
		if (c & 1)
			kill(pid, SIGUSR1);
		if (!(c & 1))
			kill(pid, SIGUSR2);
		c = c >> 1;
		i++;
	}
	return ;
}

int	main(int index, char *s[])
{
	int		pid;
	int		i;

	if (index != 3)
	{
		ft_putstr("number of args = ");
		ft_putnbr(index);
		ft_putstr("\nwrong number of arguments\n");
		return (0);
	}
	i = 0;
	pid = ft_atoi(s[1]);
	while (s[2][i])
	{
		send_tserver(s[2][i], pid);
		i++;
	}
	send_tserver(s[2][i], pid);
	return (0);
}
