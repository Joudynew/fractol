/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joudafke <joudafke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:16:30 by joudafke          #+#    #+#             */
/*   Updated: 2025/04/06 18:01:41 by joudafke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int	check_pid(const char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (pid[i] < '0' || pid[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (sign * nb);
}

void	ft_errors(char **av, int pid)
{
	if (check_pid(av[1]))
	{
		write(2, "Invalid PID\n", 12);
		exit(1);
	}
	if (pid < 1)
	{
		write(2, "Invalid PID\n", 12);
		exit(1);
	}
	if (kill(pid, 0) == -1)
	{
		write(2, "Invalid PID\n", 12);
		exit(1);
	}
	if (!av[2][0])
	{
		write(2, "Empty message\n", 14);
		exit(1);
	}
}

void	signal_to_send(int pid, unsigned char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if ((c >> i & 1) == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
	{
		write (2, "Usage: ./client <PID> <message>\n", 31);
		exit(1);
	}
	pid = ft_atoi(av[1]);
	ft_errors(av, pid);
	i = 0;
	while (av[2][i])
	{
		signal_to_send(pid, av[2][i]);
		i++;
	}
	signal_to_send(pid, '\0');
	if (!av[2][0])
		ft_errors(av, pid);
	exit (0);
}
