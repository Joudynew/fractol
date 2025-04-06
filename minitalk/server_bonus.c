/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joudafke <joudafke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:16:21 by joudafke          #+#    #+#             */
/*   Updated: 2025/04/06 17:58:13 by joudafke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*strjoin;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(str1) + ft_strlen(str2) + 1;
	strjoin = malloc(sizeof(char) * (len));
	if (!strjoin)
		return (0);
	while (str1[i])
	{
		strjoin[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		strjoin[i + j] = str2[j];
		j++;
	}
	strjoin[i + j] = '\0';
	return (strjoin);
}

void	process_character(unsigned char c)
{
	static char	*str = NULL;
	char		*tmp;
	char		ch[2];

	ch[0] = c;
	ch[1] = '\0';
	if (c == '\0')
	{
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
		free(str);
		str = NULL;
	}
	else
	{
		tmp = str;
		if (!str)
			str = ft_strjoin("", ch);
		else
			str = ft_strjoin(tmp, ch);
		free(tmp);
	}
}

void	signal_to_handle(int signal)
{
	static unsigned char	c = 0;
	static int				number_of_bits = 0;

	if (signal == SIGUSR2)
		c = (c << 1) | 1;
	else if (signal == SIGUSR1)
		c = c << 1;
	number_of_bits++;
	if (number_of_bits == 8)
	{
		process_character(c);
		c = 0;
		number_of_bits = 0;
	}
}

int	main(void)
{
	ft_printf("PID : %d\n", getpid());
	write(1, "Waiting for signal...\n", 22);
	while (1)
	{
		signal(SIGUSR1, signal_to_handle);
		signal(SIGUSR2, signal_to_handle);
		pause();
	}
	write(1, "\n", 1);
	exit (0);
}
