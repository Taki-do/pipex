/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:41:39 by taomalbe          #+#    #+#             */
/*   Updated: 2024/12/03 14:27:49 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_len(int nb)
{
	int	count;

	count = 0;
	ft_putnbr(nb);
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		count++;
		nb = -nb;
	}
	while (nb)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

int	ft_putchar_len(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_len(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr_len("(null)"));
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int	ft_printhex(unsigned long print)
{
	size_t	i;
	char	stock[20];
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	if (print == 0)
		return (ft_putchar_len('0'));
	while (print)
	{
		stock[i] = hex[print % 16];
		print /= 16;
		i++;
	}
	stock[i] = '\0';
	return (ft_putstr_len(ft_strrev(stock)));
}

int	ft_printaddr(void *addr)
{
	int				count;
	unsigned long	print;

	count = 0;
	print = (unsigned long)addr;
	if (print == 0)
		return (count + ft_putstr_len("(nil)"));
	count = ft_putstr_len("0x");
	return (count + ft_printhex(print));
}
