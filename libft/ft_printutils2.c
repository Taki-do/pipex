/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printutils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:46:21 by taomalbe          #+#    #+#             */
/*   Updated: 2024/12/03 14:27:55 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_len(unsigned int nb)
{
	int	count;

	count = 0;
	ft_putunbr(nb);
	if (nb == 0)
		return (1);
	while (nb)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

int	ft_hexa_len(unsigned int dec, int ul)
{
	size_t	i;
	char	*hexa;
	char	stock[100];

	i = 0;
	if (ul == 0)
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	if (dec == 0)
		return (ft_putchar_len('0'));
	while (dec)
	{
		stock[i] = hexa[dec % 16];
		dec /= 16;
		i++;
	}
	stock[i] = '\0';
	return (ft_putstr_len(ft_strrev(stock)));
}
