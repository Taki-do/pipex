/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:43:57 by taomalbe          #+#    #+#             */
/*   Updated: 2024/10/29 17:39:02 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_charset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*trim;
	size_t			i;
	size_t			len;
	size_t			end;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_is_charset(s1[i], set))
		i++;
	end = ft_strlen(s1);
	while (end > i && ft_is_charset(s1[end - 1], set))
		end--;
	len = end - i;
	trim = ft_substr(s1, i, len);
	return (trim);
}
