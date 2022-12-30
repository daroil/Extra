/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:38:01 by dhendzel          #+#    #+#             */
/*   Updated: 2022/12/30 03:25:19 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

int	main(int ac, char **ag, char **envp)
{	
	t_pipex	pipex;

	if (ac != 5)
		return (msg("Wrong arguments\n"));
	pipex.infile = open(ag[1], O_RDONLY);
	pipex.outfile = open(ag[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex.infile < 0 || pipex.outfile < 0)
		msg_error("Input error\n");
	pipe(pipex.pipes);
	pipex.path = find_path(envp);
	pipex.cmd_paths = ft_split(pipex.path, ':');
	pipex.child1 = fork();
	if (pipex.child1 == 0)
		first_child(&pipex, ag, envp);
	pipex.child2 = fork();
	if (pipex.child2 == 0)
		second_child(&pipex, ag, envp);
	close(pipex.pipes[0]);
	close(pipex.pipes[1]);
	waitpid(pipex.child1, NULL, 0);
	waitpid(pipex.child2, NULL, 0);
	close(pipex.infile);
	close(pipex.outfile);
	free_paths(&pipex);
	return (0);
}

//atexit(chckleaks);
// void	chckleaks(void)
// {
// 	system("leaks pipex");
// }