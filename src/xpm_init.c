/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsemke <fsemke@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:51:20 by fsemke            #+#    #+#             */
/*   Updated: 2022/05/19 13:26:13 by fsemke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_img(t_game *game)
{
	init_lizard_chest(game);
	init_else(game);
}

void	init_lizard_chest(t_game *game)
{
	game->lizard[0] = mlx_xpm_file_to_image(game->mlx,
			"imgs/char/lizard_idle_f0.xpm", &game->img_size, &game->img_size);
	game->lizard[1] = mlx_xpm_file_to_image(game->mlx,
			"imgs/char/lizard_idle_f1.xpm", &game->img_size, &game->img_size);
	game->lizard[2] = mlx_xpm_file_to_image(game->mlx,
			"imgs/char/lizard_idle_f2.xpm", &game->img_size, &game->img_size);
	game->lizard[3] = mlx_xpm_file_to_image(game->mlx,
			"imgs/char/lizard_idle_f3.xpm", &game->img_size, &game->img_size);
	game->chest[0] = mlx_xpm_file_to_image(game->mlx,
			"imgs/chest/chest_f0.xpm", &game->img_size, &game->img_size);
	game->chest[1] = mlx_xpm_file_to_image(game->mlx,
			"imgs/chest/chest_f2.xpm", &game->img_size, &game->img_size);
}

void	init_else(t_game *game)
{
	game->enemy[0] = mlx_xpm_file_to_image(game->mlx,
			"imgs/enemy/enemy_f0.xpm", &game->img_size, &game->img_size);
	game->enemy[1] = mlx_xpm_file_to_image(game->mlx,
			"imgs/enemy/enemy_f1.xpm", &game->img_size, &game->img_size);
	game->enemy[2] = mlx_xpm_file_to_image(game->mlx,
			"imgs/enemy/enemy_f2.xpm", &game->img_size, &game->img_size);
	game->button[0] = mlx_xpm_file_to_image(game->mlx,
			"imgs/button.xpm", &game->img_size, &game->img_size);
	game->button[1] = mlx_xpm_file_to_image(game->mlx,
			"imgs/button_pushed.xpm", &game->img_size, &game->img_size);
	game->ground = mlx_xpm_file_to_image(game->mlx,
			"imgs/ground.xpm", &game->img_size, &game->img_size);
	game->border = mlx_xpm_file_to_image(game->mlx,
			"imgs/wall_mid.xpm", &game->img_size, &game->img_size);
}
