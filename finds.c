/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:54:58 by vtasia            #+#    #+#             */
/*   Updated: 2021/09/07 19:55:05 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int	find_min(int a, int b, int c)
{
	int	min_num;

	min_num = a;
	if (min_num > b)
		min_num = b;
	if (min_num > c)
		min_num = c;
	return (min_num);
}

int	**fill_box(int **int_map, int height, int width)
{
	int	i;
	int	j;
	int	min_num;

	i = 1;
	while (i < height)
	{
		j = 1;
		while (j < width)
		{
			if (int_map[i][j] == 0)
				j++;
			else
			{
				min_num = find_min(int_map[i - 1][j], int_map[i][j - 1], \
				int_map[i - 1][j - 1]);
				int_map[i][j] = int_map[i][j] + min_num;
				j++;
			}
		}
		i++;
	}
	return (int_map);
}

int	find_max(int **int_map, int height, int width)
{
	int	i;
	int	j;
	int	max_num;

	i = 0;
	max_num = int_map[0][0];
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (int_map[i][j] > max_num)
				max_num = int_map[i][j];
			j++;
		}
		i++;
	}
	return (max_num);
}

int	find_y(int **int_map, int height, int width, int max_num)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (int_map[i][j] == max_num)
				return (j + 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	find_x(int **int_map, int height, int width, int max_num)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (int_map[i][j] == max_num)
				return (i + 1);
			j++;
		}
		i++;
	}
	return (0);
}
