/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:52:36 by taomalbe          #+#    #+#             */
/*   Updated: 2025/02/08 16:17:13 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	parent_control(t_var *var)
{
	close(var->fd[0]);
	close(var->fd[1]);
	if (var->infile != -1)
		close(var->infile);
	close(var->outfile);
	free_split(var->args);
	var->args = NULL;
	free_split(var->args2);
	var->args2 = NULL;
	free(var->cmd1);
	var->cmd1 = NULL;
	free(var->cmd2);
	var->cmd2 = NULL;
}

void	second_child(t_var *var, char **envp)
{
	dup2(var->fd[0], STDIN_FILENO);
	dup2(var->outfile, STDOUT_FILENO);
	close(var->fd[0]);
	close(var->fd[1]);
	if (var->infile != -1)
		close(var->infile);
	close(var->outfile);
	execve(var->cmd2, var->args2, envp);
	perror("execve");
	exit(1);
}

void	first_child(t_var *var, char **envp)
{

	if (var->infile != -1)
	{
		dup2(var->infile, STDIN_FILENO);
		close(var->infile);	
	}
	dup2(var->fd[1], STDOUT_FILENO);
	close(var->fd[0]);
	close(var->fd[1]);
	close(var->outfile);
	if (var->infile != -1)
		execve(var->cmd1, var->args, envp);
	free_split(var->args);
	var->args = NULL;
	free_split(var->args2);
	var->args2 = NULL;
	free(var->cmd1);
	var->cmd1 = NULL;
	free(var->cmd2);
	var->cmd2 = NULL;
	perror("execve");
	exit(0);
}

int	main(int ac, char *av[], char *envp[])
{
	t_var	var;

	if (ac == 5)
	{
		var.infile = open(av[1], O_RDONLY);
		var.outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (var.infile == -1 || var.outfile == -1)
			perror("Can't open files");
		if (pipe(var.fd) == -1)
			return (perror("pipe error\n"), 1);
		var.args = ft_split(av[2], ' ');
		var.args2 = ft_split(av[3], ' ');
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
