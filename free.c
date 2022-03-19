/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:55:46 by vtasia            #+#    #+#             */
/*   Updated: 2021/09/07 19:55:48 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void	free_int(int **int_map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(int_map[i]);
		int_map[i] = NULL;
		i++;
	}
	free(int_map);
	int_map = NULL;
}

void	free_char(char **split_map)
{
	int	i;

	i = 0;
	if (split_map == NULL)
		return ;
	while (split_map[i] != NULL)
	{
		free(split_map[i]);
		split_map[i] = NULL;
		i++;
	}
	free(split_map);
	split_map = NULL;
}
