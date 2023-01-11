/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:51:14 by dhendzel          #+#    #+#             */
/*   Updated: 2022/10/14 13:14:30 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s_dup;

	len = ft_strlen (s1);
	s_dup = malloc (len + 1);
	if (!s_dup)
		return (NULL);
	ft_strlcpy (s_dup, s1, len + 1);
	return (s_dup);
}
