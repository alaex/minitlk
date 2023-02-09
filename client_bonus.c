/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aen-naas <aen-naas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:03:15 by aen-naas          #+#    #+#             */
/*   Updated: 2023/02/08 15:35:35 by aen-naas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitlk.h"

int	ft_atoi(char *nptr)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	if (nptr[i] == '-')
	{
		write(2, "ENVALID PID", 12);
		exit(1);
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (res);
}

void	handel(int signalNum)
{
	if (signalNum == SIGUSR2)
		ft_printf("SENDING IS DONE");
	exit(0);
}

void	ft_send_zero(int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		kill(pid, SIGUSR2);
		usleep(200);
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	byte;

	i = 0;
	signal(SIGUSR2, &handel);
	if (ac == 3)
	{
		while (av[2][i])
		{
			j = 7;
			while (j >= 0)
			{
				byte = ((1 << j) & av[2][i]);
				if (byte == 0)
					kill(ft_atoi(av[1]), SIGUSR2);
				else
					kill(ft_atoi(av[1]), SIGUSR1);
				usleep(800);
				j--;
			}
			i++;
		}
		ft_send_zero(ft_atoi(av[1]));
	}
}
