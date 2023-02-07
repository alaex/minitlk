/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aen-naas <aen-naas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:20:18 by aen-naas          #+#    #+#             */
/*   Updated: 2023/02/06 22:20:09 by aen-naas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char word;
int i = 7;

int power(int a, int power)
{
    int time = a;
    if (power == -1)
        return a;
    if (power == 0)
        return 1;
    while (power > 1)
    {
        a *= time;
        power--;
    }
    return a;
}

void signalHandler(int signalNum, siginfo_t *info, void *walo) {
    static int old_pid;
    (void)walo;
    if (!old_pid)
        old_pid = info->si_pid;
    if (old_pid != info->si_pid)
    {
        i = 7;
        old_pid = 0;
        word = 0;
    }
    if (signalNum == SIGUSR1)
        word += power(2,i);
    else if (signalNum == SIGUSR2)
        word = power(word,-1);
    if (i == 0)
    {
        ft_printf("%c",word);
        i = 7;
        word = 0;
    }
    else 
        i--;
}


int main()
{
    struct  sigaction action;
    action.sa_flags = SIGINFO;
    action.sa_sigaction = &signalHandler;
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
    while(i >= 0)
    {
        sigaction(SIGUSR1, &action, NULL);
        sigaction(SIGUSR2, &action, NULL);
        // signal(SIGUSR1, signalHandler);
        // signal(SIGUSR2, signalHandler);
        // signal(SIGINT, signalHandler);
        // i--;
        // printf("%d",i);
    }
}