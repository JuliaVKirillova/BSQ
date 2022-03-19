/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:55:32 by vtasia            #+#    #+#             */
/*   Updated: 2021/09/07 19:55:34 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(char *map)
{
	int	i;
	int	len;
	int	res;

	i = 0;
	res = 0;
	len = ft_strlen(map) - 3;
	while (len > 0)
	{
		if (map[i] >= '0' && map[i] <= '9')
			res = res * 10 + (map[i] - '0');
		i++;
		len--;
	}
	return (res);
}
