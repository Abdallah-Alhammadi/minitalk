/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clientB.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalhamm <abalhamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:05:22 by abalhamm          #+#    #+#             */
/*   Updated: 2023/04/06 17:59:03 by abalhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_len;

void	send_data(char c, int PID)
{
	int	x;
	int	z;

	x = 128;
	z = 0;
	(void)PID;
	while (x > 0)
	{
		if ((c & x) == x)
			z = kill(PID, SIGUSR1);
		else
			z = kill(PID, SIGUSR2);
		x = x / 2;
		usleep(300);
	}
	ft_check_error("", z);
}

void	msg_received(int SIGNAL)
{
	if (SIGNAL == SIGUSR1)
	{
		write(1, "SERVER: Received ", 18);
		ft_putnbr_fd(g_len, 1);
		write(1, " character.\n", 13);
	}
	exit (1);
}

int	main(int ac, char **av)
{
	int	c;
	int	x;

	x = 0;
	if (ac == 3)
	{
		c = ft_atoi(av[1]);
		while (av[2][x])
			send_data(av[2][x++], c);
		send_data('\0', c);
		g_len = x;
		signal(SIGUSR1, msg_received);
		while (1)
			pause();
	}
	else
		write(1, "Format =  ./client <PID> <Massage>\n", 36);
}
