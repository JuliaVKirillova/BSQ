/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:55:16 by vtasia            #+#    #+#             */
/*   Updated: 2021/09/07 19:55:18 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

void	launch(char **split_map, int **int_map);
int		buff_size(char *str);
char	*read_map(char *map);
int		buff_user_size(void);
char	*read_user_map(void);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_atoi(char *map);
int		check_xline(char *map, int len);
int		check_fline(char *map);
int		check_numstr(char **map);
int		check_ch(char **map);
int		check_map(char **map, int **int_map);
void	map_trans(char **map);
int		**malloc_map(char **map);
void	map_to_int(int **map_int, char **map);
int		find_min(int a, int b, int c);
int		**fill_box(int **int_map, int height, int width);
int		find_max(int **int_map, int height, int width);
int		find_y(int **int_map, int height, int width, int max_num);
int		find_x(int **int_map, int height, int width, int max_num);
void	ft_int_to_char(int **int_map, char **split_map, int height, int width);
void	ft_switch(char **map);
void	print_map(char **split_map);
void	term_read(void);
void	free_int(int **int_map, int height);
void	free_char(char **split_map);
int		ft_isspace(char c);
int		count_words(char *str);
char	*malloc_word(char *str);
char	**ft_split(char *str, int argc);
char	*user_out(void);

#endif
