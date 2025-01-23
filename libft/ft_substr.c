/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:02:29 by taomalbe          #+#    #+#             */
/*   Updated: 2024/10/29 16:14:00 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		sub = (char *)malloc(sizeof(char));
		if (!sub)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	size = len;
	if (ft_strlen(s) - start < len)
		size = ft_strlen(s) - start;
	sub = (char *)malloc((size + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	ft_strncpy(sub, s + start, size);
	sub[size] = '\0';
	return (sub);
}
