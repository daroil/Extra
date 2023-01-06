/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 03:35:59 by dhendzel          #+#    #+#             */
/*   Updated: 2022/12/30 03:36:17 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	msg(char *error)
{
	write(2, error, ft_strlen(error));
	return (1);
}

void	msg_error(char *error)
{
	perror(error);
	exit(1);
}
