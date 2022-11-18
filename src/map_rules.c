/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsemke <fsemke@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:32:06 by fsemke            #+#    #+#             */
/*   Updated: 2022/05/20 14:20:00 by fsemke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_rectangle(t_game *game, char *str)
{
	int			length;
	static int	first_run = 1;

	length = ft_strlen(str);
	if (first_run == 1)
	{
		game->size_x = length;
		game->size_y = 0;
		first_run = 0;
	}
	else if (game->size_x != length)
	{
		ft_printf("Error\nThe map needs to be a rectangle!\n");
		free_exit(game);
	}
	game->size_y++;
}

void	count_specials(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
		game->count_c++;
	else if (game->map[y][x] == 'E')
		game->count_e++;
	else if (game->map[y][x] == 'P')
	{
		game->count_p++;
		game->pc_pos[0] = x;
		game->pc_pos[1] = y;
	}
	else if (game->map[y][x] != 'M' && game->map[y][x] != '1'
		&& game->map[y][x] != '0')
	{
		ft_printf("Error\nUnknown character found in the map.\n");
		free_exit(game);
	}
}

void	check_specials_num(t_game *game)
{
	if (game->count_e < 1 || game->count_c < 1 || game->count_p != 1)
	{
		ft_printf("Error\nThe map needs P==1, E>=1, C>=1\n");
		free_exit(game);
	}
}

void	check_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->size_x)
	{
		if (game->map[0][i] != '1' || game->map[game->size_y - 1][i] != '1')
		{
			ft_printf("Error\nThe wall around the map needs to be closed.\n");
			free_exit(game);
		}
		i++;
	}
	i = 0;
	while (i < game->size_y)
	{
		if (game->map[i][0] != '1' || game->map[i][game->size_x - 1] != '1')
		{
			ft_printf("Error\nThe wall around the map needs to be closed.\n");
			free_exit(game);
		}
		i++;
	}
}
