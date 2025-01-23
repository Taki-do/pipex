/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:06:31 by taomalbe          #+#    #+#             */
/*   Updated: 2024/11/05 12:57:03 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			full_len;
	unsigned char	*calloc;

	if (!nmemb || !size)
		return ((void *)malloc(0));
	full_len = nmemb * size;
	if (size != 0 && full_len / size != nmemb)
		return (NULL);
	calloc = (unsigned char *)malloc(full_len);
	if (!calloc)
		return (NULL);
	ft_bzero(calloc, full_len);
	return ((void *)calloc);
}
