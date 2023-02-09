/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitlk.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aen-naas <aen-naas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:37:53 by aen-naas          #+#    #+#             */
/*   Updated: 2023/02/10 00:21:32 by aen-naas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MINITLK_H
# define MINITLK_H
# define KHDER "\033[32m"
# define BYED "\033[0m"
# define BOLD "\033[1m"
# include <signal.h>
# include <unistd.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "ft_printf/ft_printf.h"

void	ft_error(char *msg);
int		ft_atoi(char *nptr);
void	ft_send(char c, char *av);
#endif