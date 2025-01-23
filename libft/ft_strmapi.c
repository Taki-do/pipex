/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:46:20 by taomalbe          #+#    #+#             */
/*   Updated: 2024/10/29 19:14:30 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mapi;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	mapi = ft_strdup(s);
	if (!mapi)
		return (NULL);
	while (mapi[i])
	{
		mapi[i] = f(i, mapi[i]);
		i++;
	}
	return (mapi);
}
