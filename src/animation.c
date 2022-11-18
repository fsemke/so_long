/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsemke <fsemke@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:00:48 by fsemke            #+#    #+#             */
/*   Updated: 2022/05/20 13:42:17 by fsemke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	animation(t_game *game)
{
	int			x;
	int			y;

	x = -1;
	y = -1;
	usleep(ANIM_SPEED);
	while (++y < game->size_y)
	{
		while (++x < game->size_x)
		{
			animate_sprites(game, &x, &y);
		}
		x = -1;
	}
	return (0);
}

void	animate_sprites(t_game *game, int *x, int *y)
{
	static int	l = 0;
	static int	m = 0;

	if (game->map[*y][*x] == 'M')
		draw_img(game, game->enemy[m], *x, *y);
	else if (game->map[*y][*x] == 'P')
		draw_img(game, game->lizard[l], *x, *y);
	if (*x == (game->size_x - 1) && *y == (game->size_y - 1))
	{
		if (++m > 2)
			m = 0;
		if (++l > 3)
			l = 0;
	}
}

void	open_chests(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < game->size_y)
	{
		while (++x < game->size_x)
		{
			if (game->map[y][x] == 'E')
				draw_img(game, game->chest[1], x, y);
		}
		x = -1;
	}
}
