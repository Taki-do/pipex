/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:44:47 by taomalbe          #+#    #+#             */
/*   Updated: 2024/11/06 14:55:43 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	i;
	size_t	max;
	size_t	len;
	char	tmp;

	i = 0;
	len = ft_strlen(str);
	max = len - 1;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[max];
		str[max] = tmp;
		max--;
		i++;
	}
	return (str);
}
