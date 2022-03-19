/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:55:24 by vtasia            #+#    #+#             */
/*   Updated: 2021/09/07 19:55:25 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void	launch(char **split_map, int **int_map)
{
	int		width;
	int		height;

	map_trans(split_map);
	map_to_int(int_map, split_map);
	width = ft_strlen(split_map[1]);
	height = ft_atoi(split_map[0]);
	int_map = fill_box(int_map, height, width);
	ft_int_to_char(int_map, split_map, height, width);
	free_int(int_map, height);
	ft_switch(split_map);
	print_map(split_map);
	free_char(split_map);
}

char	*user_out(void)
{
	char	*str_map;

	term_read();
	str_map = read_user_map();
	return (str_map);
}

char	**to_main(int argc, char **argv, int i)
{
	char	*str_map;
	char	**split_map;

	if (argc == 1)
		str_map = user_out();
	else
		str_map = read_map(argv[i]);
	if (str_map == NULL || str_map[0] == '\0')
	{
		free(str_map);
		return (NULL);
	}
	split_map = ft_split(str_map, argc);
	if (split_map == NULL || split_map[1] == NULL)
	{
		free(str_map);
		free_char(split_map);
		return (NULL);
	}
	free(str_map);
	return (split_map);
}

int	main(int argc, char **argv)
{
	int		i;
	char	**split_map;
	int		**int_map;

	i = 1;
	if (argc == 1)
		i = 0;
	while (i < argc)
	{
		split_map = to_main(argc, argv, i);
		if (split_map != NULL)
			int_map = malloc_map(split_map);
		if (check_map(split_map, int_map))
			ft_putstr("map error\n");
		else
			launch(split_map, int_map);
		if (i != argc - 1 && argc != 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
