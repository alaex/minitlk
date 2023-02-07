/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aen-naas <aen-naas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:22:37 by aen-naas          #+#    #+#             */
/*   Updated: 2023/02/06 22:20:33 by aen-naas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	ft_atoi(char *nptr)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	// while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
	// 	i++;
	if (nptr[i] == '-')
	{
		write(2,"ENVALID PID",12);
        exit(1);
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (res);
}

int main(int ac, char **av)
{
    char *res;
    int i;
    int j;
    char byte;

    res = av[2];
    i = 0;
    // ft_printf("PID: %d\n", getpid());
    if (ac == 3)
    {
        while (res[i])
        {
            j = 7;
            while (j >= 0)
            {
                byte = ((1 << j) & res[i]);
                if (byte == 0)
                    kill(ft_atoi(av[1]), SIGUSR2);
                else
                    kill(ft_atoi(av[1]), SIGUSR1);
                usleep(800);
                j--;
            }
            i++;
        }
        
    }
    return 0;
}
