/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:10:02 by taomalbe          #+#    #+#             */
/*   Updated: 2024/12/14 11:54:44 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbsize(long nb)
{
	size_t	size;

	size = 0;
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

static char	*ft_zero(void)
{
	char	*itoa;

	itoa = (char *)malloc(2 * sizeof(char));
	if (!itoa)
		return (NULL);
	itoa[0] = '0';
	itoa[1] = '\0';
	return (itoa);
}

static	void	ft_negative(long *nb, int *negative)
{
	*nb = -*nb;
	*negative = 1;
}

char	*ft_itoa(int n)
{
	char	*itoa;
	size_t	i;
	int		negative;
	long	nb;

	i = 0;
	negative = 0;
	nb = (long)n;
	if (nb == 0)
		return (ft_zero());
	if (nb < 0)
		ft_negative(&nb, &negative);
	itoa = (char *)malloc((ft_nbsize(nb) + negative + 1) * sizeof(char));
	if (!itoa)
		return (NULL);
	while (nb > 0)
	{
		itoa[i++] = nb % 10 + '0';
		nb /= 10;
	}
	if (negative == 1)
		itoa[i++] = '-';
	itoa[i] = '\0';
	return (ft_strrev(itoa));
}
