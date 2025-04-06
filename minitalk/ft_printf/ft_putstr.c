/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joudafke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:42:05 by joudafke          #+#    #+#             */
/*   Updated: 2024/12/10 18:48:57 by joudafke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
		count++;
	}
	return (count);
}
