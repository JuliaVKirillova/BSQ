/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 18:46:42 by vtasia            #+#    #+#             */
/*   Updated: 2021/09/04 15:17:04 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int	ft_isspace(char c)
{
	return (c == '\n');
}

int	count_words(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if ((*str && !ft_isspace(*str)) || (*str && ft_isspace(*str)))
		{
			count++;
			while (*str && !ft_isspace(*str))
				str++;
		}
		str++;
	}
	return (count);
}

char	*malloc_word(char *str)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (str[i] && !ft_isspace(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

int	atoi_plus(char *str)
{
	int	i;
	int	num;
	int	k;

	i = 0;
	k = 0;
	num = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	while (i - 3 > 0)
	{
		if (str[k] >= '0' && str[k] <= '9')
			num = num * 10 + (str[k] - '0');
		k++;
		i--;
	}
	return (num);
}

char	**ft_split(char *str, int argc)
{
	char	**arr;
	int		i;
	int		count;

	count = count_words(str);
	if (argc == 1)
		count--;
	if (atoi_plus(str) != count - 1 || str == NULL)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str && !ft_isspace(*str))
		{
			arr[i++] = malloc_word(str);
			while (*str && !ft_isspace(*str))
				str++;
		}
		str++;
	}
	arr[i] = NULL;
	return (arr);
}
