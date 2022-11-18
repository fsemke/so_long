/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsemke <fsemke@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:51:49 by fsemke            #+#    #+#             */
/*   Updated: 2022/05/23 13:46:52 by fsemke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move(t_game *game, int keycode)
{
	if (keycode == KEY_W)
		check_field_go(game, game->pc_pos[0], game->pc_pos[1] - 1);
	else if (keycode == KEY_A)
		check_field_go(game, game->pc_pos[0] - 1, game->pc_pos[1]);
	else if (keycode == KEY_S)
		check_field_go(game, game->pc_pos[0], game->pc_pos[1] + 1);
	else if (keycode == KEY_D)
		check_field_go(game, game->pc_pos[0] + 1, game->pc_pos[1]);
}

void	check_field_go(t_game *game, int x, int y)
{
	int	pushed_all_b;

	if (game->map[y][x] == '1')
		return ;
	else if (game->map[y][x] == '0' || game->map[y][x] == 'C'
			|| game->map[y][x] == 'Z')
		change_player_pos(game, x, y);
	else if (game->map[y][x] == 'E')
	{
		pushed_all_b = check_pushed_buttons(game);
		if (pushed_all_b == 0)
			ft_printf("You need to push all buttons!\n");
		else if (pushed_all_b == 1)
		{
			ft_printf("\n!!!You won!!!\nYou used %d steps\n", ++game->counter);
			close_cleanup(game);
		}
	}
	else if (game->map[y][x] == 'M')
		died(game);
}

void	change_player_pos(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = 'Z';
		if (check_pushed_buttons(game) == 1)
			open_chests(game);
	}
	game->map[game->pc_pos[1]][game->pc_pos[0]] = game->last_pos;
	if (game->last_pos == '0')
		draw_img(game, game->ground, game->pc_pos[0], game->pc_pos[1]);
	else if (game->last_pos == 'C' || game->last_pos == 'Z')
		draw_img(game, game->button[1], game->pc_pos[0], game->pc_pos[1]);
	game->last_pos = game->map[y][x];
	game->map[y][x] = 'P';
	draw_img(game, game->lizard[0], x, y);
	game->pc_pos[0] = x;
	game->pc_pos[1] = y;
	game->counter++;
	print_steps(game);
}

int	check_pushed_buttons(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->size_y)
	{
		while (x < game->size_x)
		{
			if (game->map[y][x] == 'C')
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

void	died(t_game *game)
{
	ft_printf("\nYou died!!!\nNever cuddle with monsters.\n");
	ft_printf("You used %d steps.\n", ++game->counter);
	close_cleanup(game);
}
