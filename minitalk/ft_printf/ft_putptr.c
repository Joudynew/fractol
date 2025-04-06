/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joudafke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:24:43 by joudafke          #+#    #+#             */
/*   Updated: 2024/12/10 21:36:28 by joudafke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long nb)
{
	int	count;

	count = 0;
	if (!nb)
		return (write(1, "(nil)", 5));
	count += ft_putstr("0x");
	count += ft_puthex(nb, 'x');
	return (count);
}
