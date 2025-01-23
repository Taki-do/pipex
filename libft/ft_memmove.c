/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:02:10 by taomalbe          #+#    #+#             */
/*   Updated: 2024/10/29 15:01:54 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_cpy;
	const unsigned char	*src_cpy;

	dest_cpy = (unsigned char *)dest;
	src_cpy = (const unsigned char *)src;
	if (dest < src)
	{
		i = -1;
		while (++i < n)
			dest_cpy[i] = src_cpy[i];
	}
	else if (dest > src)
	{
		i = n + 1;
		while (--i > 0)
			dest_cpy[i - 1] = src_cpy[i - 1];
	}
	return (dest);
}
