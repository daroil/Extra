/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:15:44 by dhendzel          #+#    #+#             */
/*   Updated: 2022/10/16 14:59:20 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*haystack1;

	i = 0;
	haystack1 = (char *) haystack;
	if (needle[i] == '\0')
		return (haystack1);
	while (haystack1[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack1[i + j] == needle[j]
			&& haystack1[i + j] != '\0' && i + j < len)
		{
			if (needle[j] == '\0')
				return (&haystack1[i]);
			j++;
		}
		if (needle[j] == '\0')
			return (&haystack1[i]);
		i++;
	}
	return (NULL);
}
