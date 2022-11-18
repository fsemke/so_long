/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsemke <fsemke@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:26:46 by fsemke            #+#    #+#             */
/*   Updated: 2022/05/23 13:54:45 by fsemke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map(t_game *game, char *file)
{
	if (load_map(game, file) != 0)
	{
		ft_printf("Error\nMap could not be loaded.\n");
		free_exit(game);
	}
	check_rules(game);
	return (0);
}

int	load_map(t_game *game, char *file)
{
	int		fd;
	char	*str;

	str = ft_strrchr(file, '.');
	if (ft_strlen(str) != 4 || ft_strncmp(str, ".ber", 4) != 0)
	{
		ft_printf("Error\nThe given file does'nt exist, or isn't a .ber file.\n");
		free_exit(game);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	str = ft_read(fd);
	if (!str)
		return (1);
	close(fd);
	game->map = ft_split(str, '\n');
	free (str);
	return (0);
}

void	check_rules(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	game->count_c = 0;
	game->count_e = 0;
	game->count_p = 0;
	while (game->map[y] && game->map[y][x])
	{
		while (game->map[y][x])
		{
			if (x == 0)
				check_rectangle(game, game->map[y]);
			count_specials(game, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	check_specials_num(game);
	check_wall(game);
}

void	free_exit(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
	}
	free(game);
	exit(0);
}
