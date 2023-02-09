/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aen-naas <aen-naas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:03:35 by aen-naas          #+#    #+#             */
/*   Updated: 2023/02/09 20:04:59 by aen-naas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitlk.h"

char	g_word = 0;

int	power(int a, int power)
{
	int	time;

	time = a;
	if (power == -1)
		return (a);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		a *= time;
		power--;
	}
	return (a);
}

void	send(int *i, int pid)
{
	if (g_word == 0)
		kill(pid, SIGUSR2);
	else
	{
		ft_printf("%c", g_word);
		(*i) = 7;
		g_word = 0;
	}
}

void	signalhandler(int signalnum, siginfo_t *info, void *walo)
{
	static int	curpid;
	static int	i = 7;

	(void)walo;
	if (!curpid)
		curpid = info->si_pid;
	if (curpid != info->si_pid)
	{
		g_word = 0;
		i = 7;
		curpid = 0;
	}
	if (signalnum == SIGUSR1)
		g_word += power(2, i);
	else if (signalnum == SIGUSR2)
		g_word = power(g_word, -1);
	if (i == 0)
		send(&i, curpid);
	else
		i--;
}

int	main(void)
{
	struct sigaction	action;

	action.sa_flags = SIGINFO;
	action.sa_sigaction = &signalhandler;
	ft_printf("\n");
	ft_printf(BOLD KHDER" ▄▀▀█▄   ▄▀▀▀▀▄      ▄▀▀█▄   ▄▀▀█▄▄▄▄ \n");
	ft_printf(KHDER"▐ ▄▀ ▀▄ █    █      ▐ ▄▀ ▀▄ ▐  ▄▀   ▐ \n");
	ft_printf(KHDER"  █▄▄▄█ ▐    █        █▄▄▄█   █▄▄▄▄▄  \n");
	ft_printf(KHDER" ▄▀   █     █        ▄▀   █   █    ▌  \n");
	ft_printf(KHDER"█   ▄▀    ▄▀▄▄▄▄▄▄▀ █   ▄▀   ▄▀▄▄▄▄   \n");
	ft_printf(KHDER"▐   ▐     █         ▐   ▐    █    ▐   \n");
	ft_printf(KHDER"          ▐                  ▐        \n"BYED);
	ft_printf("\n");
	ft_printf(BOLD"\t\tPID: %d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		pause();
	}
}
