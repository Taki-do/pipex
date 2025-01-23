/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:25:43 by taomalbe          #+#    #+#             */
/*   Updated: 2025/01/23 14:11:02 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

char	*get_path(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*get_cmd_path(char *cmd, char *envp[])
{
	int		i;
	char	**split;
	char	*temp;
	char	*path_cmd;

	i = 0;
	split = ft_split(get_path(envp), ':');
	while (split[i])
	{
		temp = ft_strjoin(split[i], "/");
		path_cmd = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path_cmd, X_OK) == -1)
			free(path_cmd);
		else
			return (free_split(split), path_cmd);
		i++;
	}
	free(path_cmd);
	free_split(split);
	return (NULL);
}
