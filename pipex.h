/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 23:50:57 by dhendzel          #+#    #+#             */
/*   Updated: 2022/12/30 03:08:07 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct pipex_s
{
	int		infile;
    int		outfile;
	char	*path;
	char	**cmd_paths;
	pid_t	child1;
    pid_t	child2;
	int		pipes[2];
	char	**cmd_args;
	char	*cmd;
}	t_pipex;

void	first_child(t_pipex *pipex, char **ag, char **envp);
void	second_child(t_pipex *pipex, char **ag, char **envp);
void	cmd_free(t_pipex *pipex);
void	free_paths(t_pipex *pipex);
void	msg_error(char *error);
int		msg(char *error);


#endif
