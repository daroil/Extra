/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 01:54:55 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/11 01:54:57 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*repeat_line_n_times(char *str, int n)
{
	char	*res;
	char	*mid_res;

	n = n - 1;
	if (n <= 0)
		return ("");
	res = ft_strdup(str);
	n--;
	while (n)
	{
		mid_res = ft_strjoin(res, str);
		free(res);
		res = ft_strdup(mid_res);
		free(mid_res);
		n--;
	}
	return (res);
}

int	buf_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	read_from_to(char *delimimter, int in_fd, int out_fd, int n_of_pipes)
{
	char	*buf;
	char	*pipes;

	pipes = repeat_line_n_times("pipe ", n_of_pipes);
	ft_putstr_fd(pipes, in_fd);
	ft_putstr_fd("heredoc> ", in_fd);
	buf = get_next_line(in_fd);
	while (buf && (ft_strncmp(buf, delimimter, buf_max(ft_strlen(buf) - 1,
					ft_strlen(delimimter))) || ft_strlen(buf) == 1))
	{
		ft_putstr_fd(pipes, in_fd);
		ft_putstr_fd("heredoc> ", in_fd);
		ft_putstr_fd(buf, out_fd);
		free(buf);
		buf = get_next_line(in_fd);
	}
	free(pipes);
	free(buf);
}
