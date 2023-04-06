/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverB.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalhamm <abalhamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:05:51 by abalhamm          #+#    #+#             */
/*   Updated: 2023/04/06 17:40:09 by abalhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_data(int SIGNAL, siginfo_t *info, void *ptr)
{
	static int	x;
	static char	c;

	(void)ptr;
	if (SIGNAL == SIGUSR1)
		c = (c << 1) | 1;
	else if (SIGNAL == SIGUSR2)
		c = (c << 1) | 0;
	x++;
	if (x == 8)
	{
		ft_putchar_fd(c, 1);
		if (!c)
		{
			usleep(250);
			kill(info->si_pid, SIGUSR1);
		}
		x = 0;
		c = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	ser;

	pid = getpid();
	write(1, "Server Run the <PID> is: ", 26);
	ft_putnbr_fd(pid, 1);
	write(1, ". \n", 4);
	ser.sa_flags = SA_SIGINFO;
	ser.sa_sigaction = get_data;
	sigaction(SIGUSR1, &ser, NULL);
	sigaction(SIGUSR2, &ser, NULL);
	while (1)
		pause();
	return (0);
}
