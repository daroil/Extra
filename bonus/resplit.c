/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resplit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:44:30 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/06 17:38:18 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	count_words(char const *s, char *c)
{
	int		counter;
	int		i;
	int		prev;
	int		flag;
	char	*tmp;
	
	prev = 0;
	counter = 0;
	i = 0;
	flag = 0;
	while (s[i])
	{
		if(s[i] == 39 && flag == 0)
		{
			flag = 1;
			tmp = c;
			char *smth = "'";
			c = smth;
		}
		if (ft_strchr(c, s[i]))
		{
			counter += prev;
			prev = 0;
		}
		else
			prev = 1;
		i++;
		if(s[i] == 39 && flag == 1)
			c = tmp;
	}
	if (i == 0)
		return (0);
	return (counter + (!ft_strchr(c, s[i - 1])));
}

// static int	count_words(char const *s, char *c)
// {
// 	int		counter;
// 	int		i;
// 	int		prev;

// 	prev = 0;
// 	counter = 0;
// 	i = 0;
// 	while (s[i])
// 	{
// 		if (ft_strchr(c, s[i]))
// 		{
// 			counter += prev;
// 			prev = 0;
// 		}
// 		else
// 			prev = 1;
// 		i++;
// 	}
// 	if (i == 0)
// 		return (0);
// 	return (counter + (!ft_strchr(c, s[i - 1])));
// }

// static void	*ft_split_clear(char **res)
// {
// 	int	i;

// 	i = 0;
// 	while (res[i])
// 		free(res[i++]);
// 	free(res);
// 	return (NULL);
// }

static char	**ft_split_word(char **res, int i, char *c, char const *s)
{
	int	word;
	int	j;
	int	counter;
	char *tmp;
	int	flag;
	
	flag = 0;
	j = 0;
	word = -1;
	while (++word < count_words(s, c))
	{
		while (ft_strchr(c, s[i]) && s[i])
			i = i + 1;
		if(s[i] == 39 && flag == 1)
		{
			printf("flag back i%d\n",i);
			c = tmp;
		}
		j = i;
		printf("character %c i %d\n",s[i],i);
		printf("character int %d i %d\n",s[i],i);
		if(s[i] == 39 && flag == 0)
		{
			flag = 1;
			tmp = c;
			char *smth = "'";
			c = smth;
		}
		printf("string %s\n",c);
		while (s[i] && !ft_strchr(c, s[i]))
			i += 1;
		res[word] = malloc(sizeof(char) * (i - j + 1));
		if (!res[word])
			return (ft_split_clear(res));
		counter = 0;
		while (j < i)
			res[word][counter++] = s[j++];
		res[word][counter] = '\0';
	}
	res[word] = NULL;
	return (res);
}

char	**ft_resplit(char const *s, char *c)
{
	int		i;
	char	**res;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (count_words(s, c) + 1));
	printf("words%d\n",count_words(s, c));
	if (!res)
		return (NULL);
	i = 0;
	res = ft_split_word(res, i, c, s);
	return (res);
}
