/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:22:28 by taomalbe          #+#    #+#             */
/*   Updated: 2025/02/08 16:23:10 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	parent_control(t_var *var)
{
	close(var->fd[0]);
	close(var->fd[1]);
	close(var->infile);
	close(var->outfile);
	free_split(var->args);
	free_split(var->args2);
	free(var->cmd1);
	free(var->cmd2);
}

void	second_child(t_var *var, char **envp)
{
	dup2(var->fd[0], STDIN_FILENO);
	dup2(var->outfile, STDOUT_FILENO);
	close(var->fd[0]);
	close(var->fd[1]);
	close(var->infile);
	close(var->outfile);
	execve(var->cmd2, var->args2, envp);
	perror("execve");
	exit(1);
}

void	first_child(t_var *var, char **envp)
{
	dup2(var->infile, STDIN_FILENO);
	dup2(var->fd[1], STDOUT_FILENO);
	close(var->fd[0]);
	close(var->fd[1]);
	close(var->infile);
	close(var->outfile);
	execve(var->cmd1, var->args, envp);
	perror("execve");
	exit(1);
}

void	ft_here_doc(char *limiter, int *fd)
{
	char	*line;

	close(fd[0]);
	while (1)
	{
		write(1, "pipe heredoc> ", 14);
		line = get_next_line(STDIN_FILENO);
		if (line[ft_strlen(limiter) - 1] == '\n')
			line[ft_strlen(limiter) - 1] = '\0';
		if (!line || ft_strcmp(line, limiter) == 0)
		{
			free(line);
			break ;
		}
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	close(fd[1]);
}

int	here_main(int ac, char *av[], char *envp[], char *limiter)
{
	t_var	var;

	if (ac == 6)
	{
		var.outfile = open(av[5], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (var.outfile == -1)
			return (perror("Can't open files"), 1);
		if (pipe(var.fd) == -1)
			return (perror("pipe error\n"), 1);
		ft_here_doc(limiter, var.fd);
		var.args = ft_split(av[3], ' ');
		var.args2 = ft_split(av[4], ' ');
		var.cmd1 = get_cmd_path(var.args[0], envp);
		var.cmd2 = get_cmd_path(var.args2[0], envp);
		var.pid = fork();
		if (var.pid == 0)
			first_child(&var, envp);
		var.pid = fork();
		if (var.pid == 0)
			second_child(&var, envp);
		parent_control(&var);
		wait(NULL);
		wait(NULL);
	}
	return (0);
}

