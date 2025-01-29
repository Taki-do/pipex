/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:38:46 by taomalbe          #+#    #+#             */
/*   Updated: 2025/01/29 18:14:15 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_cmd(char *cmd, char **envp)
{
	char	*path;
	char	**args;

	args = ft_split(cmd, ' ');
	if (!args)
	{
		perror("ft_split");
		exit(1);
	}
	path = get_cmd_path(args[0], envp);
	if (!path)
	{
		perror(args[0]);
		//free_split(args);
		exit(1);
	}
	execve(path, args, envp);
	perror("execve");
	free(path);
	//free_split(args);
	exit(1);
}

char	**skip_pipes(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_strcmp(args[i], "|") == 0)
		{
			if (!args[i + 1])
				exit(1); //Mais il faudrait ouvrir "pipe>"
			while (args[i + 1])
			{
				free(args[i]);
				args[i] = ft_strdup(args[i + 1]);
				i++;
			}
		}
		i++;
	}
	return (args);
}

void	exec_pipes(char **command, char **envp, int infile, int outfile)
{
	int		i;
	int		fd[2];
	int		prev_pipe;
	pid_t	pid;

	i = 1;
	prev_pipe = -1;
	while (command[i + 1])
	{
		if (command[i + 1])
		{
			if (pipe(fd) == -1)
				return (perror("pipes"));
		}
		pid = fork();
		if (pid == 0)
		{
			if (prev_pipe != -1)
			{
				dup2(infile, STDIN_FILENO);
				close(infile);
			}
			if (command[i + 1])
			{
				dup2(prev_pipe, STDIN_FILENO);
				dup2(fd[1], STDOUT_FILENO);
				close(prev_pipe);
				close(fd[1]);
				close(fd[0]);
			}
			ft_cmd(command[i], envp);
		}
		else
		{
			if (prev_pipe != -1)
				close(prev_pipe);
			if (command[i + 1])
				close(fd[1]);
			if (!command[i + 1])
				dup2(outfile, STDOUT_FILENO);
			prev_pipe = fd[0];
			wait(NULL);
		}
		i++;
	}
}

int	main(int ac, char **argv, char **envp)
{
	int	infile;
	int	outfile;

	if (ac >= 5)
	{
		infile = open(argv[1], O_RDONLY);
		outfile = open(argv[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		argv = skip_pipes(argv);
		exec_pipes(argv, envp, infile, outfile);
		close(infile);
		close(outfile);
	}	
}
