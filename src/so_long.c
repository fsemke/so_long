/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsemke <fsemke@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:51:29 by fsemke            #+#    #+#             */
/*   Updated: 2022/05/23 13:06:07 by fsemke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_printf("Error: Specify a map as argument.\n");
		return (1);
	}
	game = malloc(sizeof(t_game));
	map(game, argv[1]);
	graphic_part(game);
	free_exit(game);
}

int	close_cleanup(t_game *game)
{
	if (game->border)
	{
		ft_destroy_imgs(game);
	}
	mlx_loop_end(game->mlx);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_exit(game);
	return (0);
}

void	ft_destroy_imgs(t_game *game)
{
	mlx_destroy_image(game->mlx, game->border);
	mlx_destroy_image(game->mlx, game->ground);
	mlx_destroy_image(game->mlx, game->button[0]);
	mlx_destroy_image(game->mlx, game->button[1]);
	mlx_destroy_image(game->mlx, game->enemy[0]);
	mlx_destroy_image(game->mlx, game->enemy[1]);
	mlx_destroy_image(game->mlx, game->enemy[2]);
	mlx_destroy_image(game->mlx, game->chest[0]);
	mlx_destroy_image(game->mlx, game->chest[1]);
	mlx_destroy_image(game->mlx, game->lizard[0]);
	mlx_destroy_image(game->mlx, game->lizard[1]);
	mlx_destroy_image(game->mlx, game->lizard[2]);
	mlx_destroy_image(game->mlx, game->lizard[3]);
}
