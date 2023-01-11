/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:08:46 by dhendzel          #+#    #+#             */
/*   Updated: 2022/10/15 16:23:10 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*s1;
	const char	*s2;

	i = 0;
	s1 = (char *)dst;
	s2 = (const char *)src;
	if (dst < src)
	{
		while (i < len)
		{
			s1[i] = s2[i];
			i++;
		}
	}
	else if (dst > src)
	{
		while (len > 0)
		{
			len--;
			s1[len] = s2[len];
		}
	}
	return (s1);
}
