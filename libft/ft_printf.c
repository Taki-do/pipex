/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:19:28 by taomalbe          #+#    #+#             */
/*   Updated: 2024/12/03 14:26:07 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_parse_input(const char format, va_list args)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar_len((char)va_arg(args, int));
	else if (format == 's')
		count += ft_putstr_len((char *)va_arg(args, char *));
	else if (format == 'p')
		count += ft_printaddr((void *)va_arg(args, unsigned char *));
	else if (format == 'd' || format == 'i')
		count += ft_putnbr_len((int)va_arg(args, int));
	else if (format == 'u')
		count += ft_putunbr_len((unsigned int)va_arg(args, unsigned int));
	else if (format == 'x')
		count += ft_hexa_len((unsigned int)va_arg(args, unsigned int), 0);
	else if (format == 'X')
		count += ft_hexa_len((unsigned int)va_arg(args, unsigned int), 1);
	else if (format == '%')
		count += ft_putchar_len('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			count += ft_parse_input(format[++i], args);
		else
			count += ft_putchar_len(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
