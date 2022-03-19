/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:56:18 by vtasia            #+#    #+#             */
/*   Updated: 2021/09/07 19:56:20 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int	buff_size(char *str)
{
	char	buff[1];
	int		fd;
	int		size;

	size = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (read(fd, buff, 1) > 0)
		size++;
	close(fd);
	return (size + 1);
}

char	*read_map(char *map)
{
	int		fd;
	int		size;
	char	*buff;

	size = buff_size(map);
	if (size < 0)
		return (NULL);
	buff = malloc(sizeof(char *) * size);
	if (buff == NULL)
		return (NULL);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (read(fd, buff, size) > 0)
	{
	}
	close(fd);
	buff[size - 1] = '\0';
	return (buff);
}

int	buff_user_size(void)
{
	char	buff[1];
	int		fd;
	int		size;

	size = 0;
	fd = open("user_map", O_RDONLY);
	if (fd < 0)
		return (-1);
	while (read(fd, buff, 1) > 0)
		size++;
	close(fd);
	return (size + 1);
}

char	*read_user_map(void)
{
	int		fd;
	int		size;
	char	*buff;

	size = buff_user_size();
	if (size < 0)
		return (NULL);
	buff = malloc(sizeof(char *) * size);
	if (buff == NULL)
		return (NULL);
	fd = open("user_map", O_RDONLY);
	while (read(fd, buff, size) > 0 && fd > 0)
	{
	}
	close(fd);
	buff[size - 1] = '\0';
	return (buff);
}
