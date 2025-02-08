/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:38:46 by taomalbe          #+#    #+#             */
/*   Updated: 2025/02/08 16:26:34 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

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
		free_split(args);
		exit(1);
	}
	execve(path, args, envp);
	perror("execve");
	free(path);
	free_split(args);
	exit(1);
}

void	exec_pipes(char **envp, char **argv, int ac)
{
	int		i;
	int		fd[2];
	int		infile;
	int		outfile;
	int		prev_pipe;
	pid_t	pid;
	pid_t	pids[ac - 3];
	int		j;

	i = 2;
	j = 0;
	prev_pipe = -1;
	if ()
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (infile == -1 || outfile == -1)
			perror("Can't open files");
	while (argv[i] && i < ac - 1)
	{
		if (i < ac - 2 && pipe(fd) == -1)
			return (perror("pipe"));
		pid = fork();
		if (pid == 0)
		{
			if (i == 2) //premiere commande
			{
				dup2(infile, STDIN_FILENO); //envoyer stdin dans infile
				close(infile);
			}
			else if (prev_pipe != -1)
			{
				dup2(prev_pipe, STDIN_FILENO);
				close(prev_pipe);
			}
			if (i < ac - 2) //jusqu'a l'avant derniere commande
			{
				dup2(fd[1], STDOUT_FILENO); //envoyer stdout sur tete d'ecriture du pipe
				close(fd[1]);
				close(fd[0]);
			}
			else //derniere commande
			{
				dup2(outfile, STDOUT_FILENO);
				close(outfile);
			}
			ft_cmd(argv[i], envp);
		}
		else
		{
			pids[j++] = pid; //stocker les pids
			if (prev_pipe != -1) //fermer prev pipe car utilise
				close(prev_pipe);
			if (i < ac - 2) //jusqu'a l'avant derniere commande
				close(fd[1]);
			prev_pipe = fd[0];
		}
		i++;
	}
	close(outfile);
	i = -1;
	while (++i < j)
		waitpid(pids[i], NULL, 0);
}

int	main(int ac, char **av, char **envp)
{
	if (ac >= 5)
	{
		if (ft_strcmp(av[1], "here_doc") == 0)
			here_main(ac, av, envp, av[2]);
		else
			exec_pipes(envp, av, ac);
	}
}

