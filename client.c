/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 02:09:32 by jjesberg          #+#    #+#             */
/*   Updated: 2022/10/15 02:11:54 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	error(int error)
{
	if (error == ARG_ERROR)
		write(1, "wrong number of arguments\n", 26);
	return (1);
}

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
}

int	main(int index, char *s[])
{
	int		pid;
	int		i;

	if (index != 3)
		return (error(ARG_ERROR));
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
