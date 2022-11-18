/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsemke <fsemke@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:21:45 by fsemke            #+#    #+#             */
/*   Updated: 2022/05/23 13:08:52 by fsemke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./mlx/mlx.h"
# include "./mlx/mlx_int.h"
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "./libft/libft.h"

# define IMAGE_SIZE 64
# define ANIM_SPEED 150000
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_game
{
	char	**map;
	int		size_x;
	int		size_y;
	int		count_c;
	int		count_e;
	int		count_p;
	int		pc_pos[2];
	void	*mlx;
	void	*win;
	int		img_size;
	void	*lizard[4];
	void	*chest[2];
	void	*enemy[3];
	void	*button[2];
	void	*ground;
	void	*border;
	char	last_pos;
	int		counter;
}	t_game;

//so_long
int		close_cleanup(t_game *game);
void	ft_destroy_imgs(t_game *game);
//read.c
char	*ft_read(int fd);
//map.c
int		map(t_game *game, char *file);
int		load_map(t_game *game, char *file);
void	check_rules(t_game *game);
void	free_exit(t_game *game);
//map_rules.c
void	check_rectangle(t_game *game, char *str);
void	count_specials(t_game *game, int x, int y);
void	check_specials_num(t_game *game);
void	check_wall(t_game *game);

//Graphic
//graphic.c
void	graphic_part(t_game *game);
int		key_hook(int keycode, t_game *game);
void	draw_map(t_game *game);
void	draw_img(t_game *game, void *img, int x, int y);
void	print_steps(t_game *game);

//xpm_init.c
void	init_img(t_game *game);
void	init_lizard_chest(t_game *game);
void	init_else(t_game *game);

//animation.c
int		animation(t_game *game);
void	animate_sprites(t_game *game, int *x, int *y);
void	open_chests(t_game *game);

//move.c
void	move(t_game *game, int keycode);
void	check_field_go(t_game *game, int x, int y);
void	change_player_pos(t_game *game, int x, int y);
/**
 * @brief check if a 'C' is in the map
 * 
 * @param game 
 * @return 1, if no C was found (all buttons are pushed), else 0.
 */
int		check_pushed_buttons(t_game *game);
void	died(t_game *game);

#endif