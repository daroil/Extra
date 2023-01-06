/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:19:59 by sbritani          #+#    #+#             */
/*   Updated: 2023/01/06 17:19:09 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
char	**get_paths(char **env)
{
	int		i;
	char	**mid_res;

	i = -1;
	mid_res = NULL;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "PATH", 4))
			mid_res = ft_split(&env[i][5], ":");
	}
	return (mid_res);
}

char	*valid_path(char **paths, char *filename)
{
	char	*full_path;
	char	*path_with_slash;
	int		i;

	i = -1;
	if (!access(filename, X_OK))
		return(filename);
	while(paths[++i])
	{
		path_with_slash = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(path_with_slash, filename);
		free(path_with_slash);
		if (!access(full_path, X_OK))
			return(full_path);
		free(full_path);
	}
	return(NULL);
}
// input "cmd1 arg1 arg2" cmd2 cmd3 output

void checkleaks()
{
	system("leaks pipex");
}

//dup2(new value, old variable)

int **make_truby(int n)
{
	int **res;
	int	i;

	res = malloc(sizeof(int *) * (n + 1));
	i = 0;
	while(i < n)
	{
		res[i] = malloc(sizeof(int) * 2);
		pipe(res[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

void close_truby(int **truby, int cur, int len)
{
	int i;

	i = 0;
	if (cur == 0)
		close(truby[0][0]);
	else if (cur == len)
		close(truby[len - 1][1]);
	else
	{
		close(truby[cur - 1][1]);
		close(truby[cur][0]);
	}
	while (truby[i])
	{
		if (cur < i || cur > i + 1)
		{
			close(truby[i][0]);
			close(truby[i][1]);
		}
		i++;
	}
}

void plumber(int **truby)
{
	int	i;
	i = 0;
	while(truby[i])
	{
		close(truby[i][1]);
		close(truby[i][0]);
		free(truby[i]);
		i++;
	}
	free(truby);
}

pid_t	*make_pids(int n)
{
	pid_t *res;
	res = malloc(sizeof(pid_t) * n);
	return (res);
}

int	main(int argc, char **argv, char **env)
{
	char **paths;
	int **truby;
	int fd;
	int fd2;
	int fd3;
	int number_of_children;
	int number_of_pipes;
	pid_t *pids;
	int i;

	// atexit(&checkleaks);
	if (argc < 5)
		return (0);
	number_of_children = argc - 3;
	number_of_pipes = number_of_children - 1;
	truby = make_truby(number_of_pipes);
	pids = make_pids(number_of_children);
	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	fd3 = open("logs", O_RDWR | O_TRUNC | O_CREAT, 0644);
	fd3 = fd3 - 1;
	paths = get_paths(env);
	i = 0;
	while (i <= number_of_pipes)
	{
		pids[i] = fork();
		if (!pids[i])
		{
			if (i == 0)
			{
				dup2(fd, STDIN_FILENO);
				// dup2(truby[0][1], STDOUT_FILENO); 
			}
			else if (i == number_of_children - 1)
			{
				dup2(truby[i-1][0], STDIN_FILENO);
				// dup2(fd2, STDOUT_FILENO); 
			}
			else
			{
				dup2(truby[i - 1][0], STDIN_FILENO);
				// dup2(truby[i][1], STDOUT_FILENO); 
			}
			close_truby(truby, i, number_of_pipes);
			char **args = ft_resplit(argv[i + 2], " ");
			int j = 0;
			while(args[j])
			{
				printf("args%d %s\n",j,args[j]);
				j++;
			}
			char *path = valid_path(paths, args[0]); 
			execve(path, args, env);
		}
		i++;
	}
	plumber(truby);
	waitpid(pids[0], NULL, 0);
	waitpid(pids[1], NULL, 0);
	waitpid(pids[2], NULL, 0);
	close(fd);
	close(fd2);
	free(valid_path(paths, "ls"));
	ft_split_clear(paths);
	return (0);
}

