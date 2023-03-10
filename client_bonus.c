/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aen-naas <aen-naas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:03:15 by aen-naas          #+#    #+#             */
/*   Updated: 2023/02/10 00:36:18 by aen-naas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitlk.h"

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

	i = 0;
	signal(SIGUSR2, &handel);
	if (ac == 3)
	{
		while (av[2][i])
		{
			ft_send(av[2][i], av[1]);
			i++;
		}
		ft_send_zero(ft_atoi(av[1]));
	}
	else
	{
		ft_printf("ERROR\n LUCK OF ARGS");
		exit(1);
	}
}
