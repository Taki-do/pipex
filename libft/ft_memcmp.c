/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:43:12 by taomalbe          #+#    #+#             */
/*   Updated: 2024/11/05 12:21:22 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*cmp1;
	const unsigned char	*cmp2;

	if (n == 0)
		return (0);
	i = 0;
	cmp1 = (const unsigned char *)s1;
	cmp2 = (const unsigned char *)s2;
	while (cmp1[i] == cmp2[i] && i < n - 1)
		i++;
	return (cmp1[i] - cmp2[i]);
}
