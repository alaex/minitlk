/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comment_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aen-naas <aen-naas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 00:05:29 by aen-naas          #+#    #+#             */
/*   Updated: 2023/02/10 00:30:59 by aen-naas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitlk.h"

void	ft_error(char *msg)
{
	ft_printf("ERROR\n%s", msg);
	exit(1);
}

int	ft_atoi(char *nptr)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	if (nptr[i] == '0')
	{
		ft_printf("ERROR\nLACH KA TSIFET LI ??");
		exit(1);
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] && (nptr[i] <= '0' || nptr[i] >= '9'))
	{
		write(2, "ENVALID PID", 12);
		exit(1);
	}
	return (res);
}

void	ft_send(char c, char *av)
{
	int		j;
	char	byte;

	j = 7;
	while (j >= 0)
	{
		byte = ((1 << j) & c);
		if (byte == 0)
		{
			if (kill(ft_atoi(av), SIGUSR2) == -1)
				ft_error("NON EXESTING PID");
		}
		else
		{
			if (kill(ft_atoi(av), SIGUSR1) == -1)
				ft_error("NON EXESTING PID");
		}
		usleep(500);
		j--;
	}
}
