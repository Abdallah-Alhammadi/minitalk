/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalhamm <abalhamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:09:24 by abalhamm          #+#    #+#             */
/*   Updated: 2023/04/06 17:39:33 by abalhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_check_error(const char *string, int flags)
{
	while (*string)
	{
		if (*string != 32)
		{
			write(1, "Error: Write the correct <PID> \n", 33);
			exit(1);
		}
		string++;
	}
	if (flags == -1)
	{
		write(1, "Error: Write the correct <PID> \n", 33);
		exit(1);
	}
}

int	ft_atoi(const char *string)
{
	unsigned int	sum;
	int				s;

	s = 1;
	sum = 0;
	while (*string == 32 || *string == '\n'
		|| *string == '\t' || *string == '\f'
		|| *string == '\r' || *string == '\v')
		string++;
	while (*string >= 48 && *string <= 57)
	{
		sum = sum * 10 + (*string - 48);
		string++;
	}
	ft_check_error(string, 0);
	return (sum * s);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	num = n;
	if (n < 0)
	{
		ft_putnbr_fd('-', fd);
		num = -n;
	}
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd(num % 10 + 48, fd);
}
