/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joudafke <joudafke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:09:57 by joudafke          #+#    #+#             */
/*   Updated: 2024/12/21 01:17:39 by joudafke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(const char spec, va_list args)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (spec == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (spec == 'p')
		count += ft_putptr(va_arg(args, unsigned long));
	else if (spec == 'd' || spec == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (spec == 'u')
		count += ft_putunbr(va_arg(args, unsigned int));
	else if (spec == 'x' || spec == 'X')
		count += ft_puthex(va_arg(args, unsigned int), spec);
	else if (spec == '%')
		count += ft_putchar('%');
	return (count);
}

/* declaration d'une va_list, definie dans <stdarg.h>, qui prend
un nombre d'arguments variable. elle va nous permettre de manipuler
et parcourir ces arguments. */
/* va_start initialise va_list avant de pouvoir lire les arguments.
elle est appelee en premier et prend en parametre args
(pour parcourir les arguments) et str qui est l'argument fixe
de la fonction. */
/* va _arg recupere les arguments un par un. elle prend en parametre va_list
et le type de l'argument que l'on veut reuperer (int, char*...) */
/* va_end libere les ressources associees au va_list apres tous les args */

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += check_format(str[i + 1], args);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
