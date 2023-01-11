/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:46:53 by dhendzel          #+#    #+#             */
/*   Updated: 2022/10/20 13:44:40 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_num(int n)
{
	size_t	count;

	if (n > 0)
		count = 0;
	else
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*num;
	size_t	size;
	long	nbr;

	nbr = n;
	if (nbr < 0)
		nbr *= -1;
	size = ft_count_num(n);
	num = malloc (sizeof(char) * (size + 1));
	if (!num)
		return (NULL);
	num[size] = '\0';
	size--;
	while (nbr > 0)
	{
		num[size] = (nbr % 10) + '0';
		nbr /= 10;
		size--;
	}
	if (size == 0 && num[1] == '\0')
		num[0] = '0';
	else if (size == 0 && num[1] != '\0')
		num[0] = '-';
	return (num);
}
