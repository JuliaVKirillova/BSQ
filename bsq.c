/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 12:55:23 by vtasia            #+#    #+#             */
/*   Updated: 2021/09/06 17:06:46 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void	ft_int_to_char(int **int_map, char **split_map, int height, int width)
{
	int	x;
	int	y;
	int	max_num;
	int	i;
	int	k;

	max_num = find_max(int_map, height, width);
	x = find_x(int_map, height, width, max_num);
	y = find_y(int_map, height, width, max_num);
	i = x - max_num + 1;
	while (i <= x)
	{
		k = y - max_num;
		while (k < y)
		{
			split_map[i][k] = '*';
			k++;
		}
		i++;
	}
}

void	ft_switch(char **map)
{
	int		len;
	int		i;
	int		lenk;

	lenk = ft_strlen(map[0]);
	len = 1;
	while (map[len] != NULL)
	{
		i = 0;
		while (map[len][i] != '\0')
		{
			if (map[len][i] == '*')
				map[len][i] = map[0][lenk - 1];
			else if (map[len][i] == '0')
				map[len][i] = map[0][lenk - 2];
			else
				map[len][i] = map[0][lenk - 3];
			i++;
		}
		len++;
	}
}

void	print_map(char **split_map)
{
	int	k;

	k = 1;
	while (split_map[k] != NULL)
	{
		ft_putstr(split_map[k]);
		write(1, "\n", 1);
		k++;
	}
}

void	term_read(void)
{
	int		ret;
	int		fd;
	char	buf[1];

	fd = open("user_map", O_WRONLY | O_CREAT | O_TRUNC, 0755);
	while (1 && fd > 0)
	{
		ret = read(0, buf, 1);
		write(fd, buf, 1);
		if (!ret)
			break ;
	}
	close(fd);
}
