/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:38:01 by dhendzel          #+#    #+#             */
/*   Updated: 2022/12/29 23:52:58 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	chckleaks(void)
{
	system("leaks pipex");
}

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

// void	child_free(t_pipex *pipex)
// {
// 	int	i;

// 	i = 0;
// 	while (pipex->cmd_args[i])
// 	{
// 		free(pipex->cmd_args[i]);
// 		i++;
// 	}
// 	free(pipex->cmd_args);
// 	free(pipex->cmd);
// }

int main(int ac, char **ag, char **envp)
{	
	int f1;
    int f2;
	char *path;
	char **cmd_paths;
	// pid_t child1;
    // pid_t child2;
	int i = 0;
	// int	tube[2];
	char	**cmd_args;
	char	*cmd;
	 
	atexit(chckleaks);
	if (ac != 5)
		return (printf("Error"));
    f1 = open(ag[1], O_RDONLY);
    f2 = open(ag[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (f1 < 0 || f2 < 0)
         return (-1);
	// pipe(tube);
    path = find_path(envp);
	cmd_paths = ft_split(path, ':');
	// child1 = fork();
	// if(child1 == 0)
	// {
		
	// dup2(tube[1], 1);
	// close(tube[0]);
	// dup2(f1, 0);
	cmd_args = ft_split(ag[2], ' ');
	cmd = get_cmd(cmd_paths, cmd_args[0]);
	// if (!cmd)
	// {
	// 	// child_free(&pipex);
	// 	exit(1);
	// }
	printf("cmd: %s\n",cmd);
	printf("cmd args: %s\n",cmd_args[0]);
	// execve(cmd, cmd_args, envp);
	// }
	// child2 = fork();
	// if(child2 == 0)
	// {
		
	// dup2(tube[0], 0);
	// close(tube[1]);
	// dup2(f2, 1);
	cmd_args = ft_split(ag[3], ' ');
	cmd = get_cmd(cmd_paths, cmd_args[0]);
	// if (!cmd)
	// {
	// 	// child_free(&pipex);
	// 	exit(1);
	// }
	printf("cmd: %s\n",cmd);
	printf("cmd args: %s\n",cmd_args[0]);
	// execve(cmd, cmd_args, envp);
	// }
	// close(tube[0]);
	// close(tube[1]);
	// waitpid(child1, NULL, 0);
	// waitpid(child2, NULL, 0);
	close(f1);
	close(f2);
	i = 0;
	while(cmd_paths[i])
	{
		free(cmd_paths[i]);
		i++;
	}
	free(cmd_paths);
	//  printf("%s",path);
	return (0);
}