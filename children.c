/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 02:45:00 by dhendzel          #+#    #+#             */
/*   Updated: 2022/12/30 03:36:05 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	first_child(t_pipex *pipex, char **ag, char **envp)
{
	dup2(pipex->pipes[1], 1);
	close(pipex->pipes[0]);
	dup2(pipex->infile, 0);
	pipex->cmd_args = ft_split(ag[2], ' ');
	pipex->cmd = get_cmd(pipex->cmd_paths, pipex->cmd_args[0]);
	if (!pipex->cmd)
	{
		cmd_free(pipex);
		msg_error("Error\nCommand not found\n");
		exit(1);
	}
	execve(pipex->cmd, pipex->cmd_args, envp);
}

void	second_child(t_pipex *pipex, char **ag, char **envp)
{
	dup2(pipex->pipes[0], 0);
	close(pipex->pipes[1]);
	dup2(pipex->outfile, 1);
	pipex->cmd_args = ft_split(ag[3], ' ');
	pipex->cmd = get_cmd(pipex->cmd_paths, pipex->cmd_args[0]);
	if (!pipex->cmd)
	{
		cmd_free(pipex);
		msg_error("Error\nCommand not found\n");
		exit(1);
	}
	execve(pipex->cmd, pipex->cmd_args, envp);
}
