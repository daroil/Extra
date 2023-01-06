/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:14:03 by dhendzel          #+#    #+#             */
/*   Updated: 2022/10/20 13:50:41 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_set(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s_trim;
	size_t	i;
	size_t	end;
	size_t	start;

	i = 0;
	start = 0;
	while (ft_char_in_set(set, s1[start]) && s1[start] != '\0')
		start++;
	end = ft_strlen(s1);
	while (ft_char_in_set(set, s1[end - 1]) && end > start)
		end--;
	s_trim = malloc(end - start + 1);
	if (!s_trim)
		return (NULL);
	while (start < end)
	{
		s_trim[i] = s1[start];
		i++;
		start++;
	}
	s_trim[i] = '\0';
	return (s_trim);
}
