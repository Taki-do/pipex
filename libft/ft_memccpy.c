/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:48:36 by taomalbe          #+#    #+#             */
/*   Updated: 2024/10/29 09:57:30 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*dest_cpy;
	const unsigned char	*src_cpy;

	i = 0;
	dest_cpy = (unsigned char *)dest;
	src_cpy = (const unsigned char *)src;
	while (i < n)
	{
		dest_cpy[i] = src_cpy[i];
		if (src_cpy[i] == (unsigned char)c)
			return ((void *)&dest_cpy[i + 1]);
		i++;
	}
	return (NULL);
}
