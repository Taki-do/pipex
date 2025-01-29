/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:52:36 by taomalbe          #+#    #+#             */
/*   Updated: 2025/01/29 17:49:36 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char *envp[])
{
	int		i;
	int		**fd;
	int		infile;
	int		outfile;
	pid_t	pid;
	char	**args;
	char	**args2;
	char	*cmd1;
	char	*cmd2;
	int		all_pipes;

	if (ac >= 5)
	{
		i = 0;
		while (av[i + 1])
			i++;
		fd = init_fd(ac, all_pipes);
		infile = open(av[1], O_RDONLY); //Read infile
		outfile = open(av[i], O_WRONLY | O_CREAT | O_TRUNC, 0644); //Read outfile
		if (infile == -1 || outfile == -1)
			return (perror("Can't open files"), 1);
		if (pipe(fd) == -1)
			return (perror("pipe error\n"), 1);
		
		args = ft_split(av[2], ' ');
		args2 = ft_split(av[3], ' ');
		cmd1 = get_cmd_path(args[0], envp);
		cmd2 = get_cmd_path(args2[0], envp);
		pid = fork();
		if (pid == 0) //pid 0 correspond a l'enfant
		{
			dup2(infile, STDIN_FILENO); //l'entree standard pointe vers le meme fichier que infile
			dup2(fd[1], STDOUT_FILENO);
			close(fd[0]);
			close(fd[1]);
			close(infile);
			close(outfile);
			execve(cmd1, args, envp);	
		}
		close(fd[1]);
		pid = fork();
		if (pid == 0)
		{
			dup2(fd[0], STDIN_FILENO);
			dup2(outfile, STDOUT_FILENO);
			close(fd[0]);
			close(fd[1]);
			close(infile);
			close(outfile);
			execve(cmd2, args2, envp);	
			//code parent
		}
		close(fd[0]);
		close(fd[1]);
		close(infile);
		close(outfile);
		free_split(args);
		free_split(args2);
		free(cmd1);
		free(cmd2);
		wait(NULL);
		wait(NULL);
	}
	return (0);
}
