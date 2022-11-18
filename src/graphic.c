/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsemke <fsemke@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:27:00 by fsemke            #+#    #+#             */
/*   Updated: 2022/05/23 13:06:17 by fsemke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_cleanup(game);
	if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
		move(game, keycode);
	return (0);
}

void	graphic_part(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, IMAGE_SIZE * game->size_x,
			IMAGE_SIZE * game->size_y, "so_long - Have fun");
	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, 17, 0, close_cleanup, game);
	init_img(game);
	draw_map(game);
	game->last_pos = '0';
	game->counter = 0;
	print_steps(game);
	mlx_loop_hook(game->mlx, animation, game);
	mlx_loop(game->mlx);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < game->size_y)
	{
		while (++x < game->size_x)
		{
			if (game->map[y][x] == '1')
				draw_img(game, game->border, x, y);
			else if (game->map[y][x] == '0')
				draw_img(game, game->ground, x, y);
			else if (game->map[y][x] == 'M')
				draw_img(game, game->enemy[0], x, y);
			else if (game->map[y][x] == 'P')
				draw_img(game, game->lizard[0], x, y);
			else if (game->map[y][x] == 'C')
				draw_img(game, game->button[0], x, y);
			else if (game->map[y][x] == 'E')
				draw_img(game, game->chest[0], x, y);
		}
		x = -1;
	}
}

void	draw_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		img, x * IMAGE_SIZE, y * IMAGE_SIZE);
}

void	print_steps(t_game *game)
{
	char	*num;
	char	*joined;

	num = ft_itoa(game->counter);
	joined = ft_strjoin("Steps: ", num);
	ft_printf("%s\n", joined);
	draw_img(game, game->border, 0, game->size_y - 1);
	draw_img(game, game->border, 1, game->size_y - 1);
	mlx_string_put(game->mlx, game->win, 15, (game->size_y * IMAGE_SIZE) - 20,
		0xFFFFFF, joined);
	free (num);
	free (joined);
}
