/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:56:12 by vtasia            #+#    #+#             */
/*   Updated: 2021/09/07 19:56:13 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void	map_trans(char **map)
{
	int		len;
	int		i;
	int		k;
	char	empty;
	char	obj;

	len = ft_strlen(map[0]);
	empty = map[0][len - 3];
	obj = map[0][len - 2];
	i = 1;
	while (map[i] != NULL)
	{
		k = 0;
		while (map[i][k] != '\0')
		{
			if (map[i][k] == empty)
				map[i][k] = '1';
			else if (map[i][k] == obj)
				map[i][k] = '0';
			k++;
		}
		i++;
	}
}

int	**malloc_map(char **map)
{
	int	i;
	int	**int_map;
	int	len;

	i = 1;
	len = ft_strlen(map[1]);
	while (map[i] != NULL)
		i++;
	int_map = (int **)malloc(sizeof(int *) * (i - 1));
	if (int_map == NULL)
		return (NULL);
	i = 1;
	while (map[i] != NULL)
	{
		int_map[i - 1] = (int *)malloc(sizeof(int) * len);
		if (int_map[i - 1] == NULL)
			return (NULL);
		i++;
	}
	return (int_map);
}

void	map_to_int(int **map_int, char **map)
{
	int	i;
	int	j;

	i = 1;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			map_int[i - 1][j] = map[i][j] - 48;
			j++;
		}
		i++;
	}
}
