/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:54:35 by taomalbe          #+#    #+#             */
/*   Updated: 2025/01/21 18:08:09 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_z(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

char	*ft_return_ln(char buf[BUFFER_SIZE + 1], char *line)
{
	int	i;

	i = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	line = ft_strnjoin(line, buf, i + 1);
	ft_strncpy(buf, buf + i + 1, BUFFER_SIZE - i);
	return (line);
}

char	*ft_read(int fd, char buf[BUFFER_SIZE + 1], char *line)
{
	int	rd;

	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
			return (ft_z(buf, BUFFER_SIZE + 1), free(line), line = NULL, NULL);
		buf[rd] = '\0';
		if (ft_is_ln(buf))
			return (ft_return_ln(buf, line));
		line = ft_strnjoin(line, buf, ft_strlen(buf));
	}
	if (rd == 0 && !line[0])
		return (free(line), line = NULL, NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		buf[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup("");
	if (!line)
		return (NULL);
	if (buf[0])
	{
		if (ft_is_ln(buf))
			return (ft_return_ln(buf, line));
		line = ft_strnjoin(line, buf, ft_strlen(buf));
	}
	return (ft_read(fd, buf, line));
}
