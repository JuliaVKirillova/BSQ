/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:55:39 by vtasia            #+#    #+#             */
/*   Updated: 2021/09/07 19:55:40 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int	check_xline(char *map, int len)
{
	int	i;

	i = 0;
	len -= 3;
	while (len > 0)
	{
		if (map[i] < '0' || map[i] > '9')
			return (1);
		i++;
		len--;
	}
	return (0);
}

int	check_fline(char *map)
{
	char	full;
	char	empty;
	char	obj;
	int		len;

	len = ft_strlen(map);
	if (check_xline(map, len))
		return (1);
	full = map[len - 1];
	obj = map[len - 2];
	empty = map[len - 3];
	if (full < 32 || empty < 32 || obj < 32)
		return (1);
	if (full == obj || full == empty || obj == empty)
		return (1);
	return (0);
}

int	check_numstr(char **map)
{
	int	i;
	int	size;

	i = 0;
	while (map[i + 1] != NULL)
		i++;
	size = ft_atoi(map[0]);
	if (size != i)
		return (1);
	return (0);
}

int	check_ch(char **map)
{
	char	empty;
	char	obj;
	int		len;
	int		i;
	int		k;

	len = ft_strlen(map[0]);
	obj = map[0][len - 2];
	empty = map[0][len - 3];
	i = 1;
	while (map[i] != NULL)
	{
		k = 0;
		while (map[i][k] != '\0')
		{
			if (map[i][k] != obj && map[i][k] != empty)
				return (1);
			k++;
		}
		i++;
	}
	if (check_numstr(map))
		return (1);
	return (0);
}

int	check_map(char **map, int **int_map)
{
	int	len;
	int	st_len;
	int	i;

	i = 2;
	if (map == NULL || int_map == NULL || map[1] == NULL)
		return (1);
	st_len = ft_strlen(map[1]);
	if (st_len < 1)
		return (1);
	if (check_ch(map))
		return (1);
	if (check_fline(map[0]))
		return (1);
	while (map[i] != NULL)
	{
		len = ft_strlen(map[i]);
		if (st_len != len)
			return (1);
		i++;
	}
	return (0);
}
