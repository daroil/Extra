/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:08:28 by dhendzel          #+#    #+#             */
/*   Updated: 2022/10/16 14:55:14 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_1;
	size_t	size_2;
	size_t	total_size;
	char	*s_joined;

	size_1 = ft_strlen(s1);
	size_2 = ft_strlen(s2);
	total_size = size_1 + size_2;
	s_joined = malloc(total_size + 1);
	if (!s_joined)
		return (NULL);
	ft_strlcpy(s_joined, s1, size_1 + 1);
	ft_strlcat(s_joined, s2, total_size + 1);
	return (s_joined);
}
