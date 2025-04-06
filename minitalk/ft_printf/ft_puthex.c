/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joudafke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:18:34 by joudafke          #+#    #+#             */
/*   Updated: 2024/12/10 19:43:03 by joudafke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long nb, const char spec)
{
	char	*base;
	int		count;

	if (spec == 'x')
		base = "0123456789abcdef";
	else if (spec == 'X')
		base = "0123456789ABCDEF";
	count = 0;
	if (nb < 16)
		count += ft_putchar(base[nb]);
	if (nb >= 16)
	{
		count += ft_puthex(nb / 16, spec);
		count += ft_puthex(nb % 16, spec);
	}
	return (count);
}
