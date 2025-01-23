/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:30:56 by taomalbe          #+#    #+#             */
/*   Updated: 2024/10/29 12:38:53 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*chr;

	i = 0;
	chr = (const unsigned char *)s;
	while (i < n)
	{
		if (chr[i] == (unsigned char)c)
			return ((void *)&chr[i]);
		i++;
	}
	return (NULL);
}
