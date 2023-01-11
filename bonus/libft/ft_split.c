/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:42:22 by dhendzel          #+#    #+#             */
/*   Updated: 2023/01/11 02:00:43 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	new_word;
	int	i;

	i = 0;
	count = 0;
	new_word = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c && new_word == 0)
		{
				new_word = 1;
				count++;
		}
		else if (s[i] == c)
			new_word = 0;
		i++;
	}
	return (count);
}

static char	*ft_copy_word(const char *src, int new_word_pos, int pos)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (pos - new_word_pos + 1));
	if (!word)
		return (NULL);
	while (new_word_pos < pos)
	{
		word[i] = src[new_word_pos];
		new_word_pos++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_split_word(char **s_array, char c, char const *s, int new)
{
	size_t		j;
	size_t		i;

	i = -1;
	j = 0;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && new == -1)
			new = i;
		else if ((s[i] == c || i == ft_strlen(s)) && new >= 0)
		{
			s_array[j] = ft_copy_word(s, new, i);
			if (!s_array[j++])
			{
				while (s_array)
				{
					free(s_array);
					return (NULL);
				}
			}
			new = -1;
		}
	}
	s_array[j] = NULL;
	return (s_array);
}

void	*ft_split_clear(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**s_array;
	int			new_word_pos;

	new_word_pos = -1;
	s_array = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!s_array)
		return (NULL);
	s_array = ft_split_word(s_array, c, s, new_word_pos);
	return (s_array);
}
