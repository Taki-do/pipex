/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taomalbe <taomalbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:18:26 by taomalbe          #+#    #+#             */
/*   Updated: 2025/02/03 14:45:43 by taomalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_var
{
	int		fd[2];
	int		infile;
	int		outfile;
	pid_t	pid;
	char	**args;
	char	**args2;
	char	*cmd1;
	char	*cmd2;
	int		prev_pipe;
}   t_var;

typedef struct s_fd
{
	int **fd;
	int	track;
	int	index_cmd;
}	t_fd;

char	*get_cmd_path(char *cmd, char *envp[]);
int		here_main(int ac, char *av[], char *envp[], char *limiter);
void	free_split(char **split);

#endif