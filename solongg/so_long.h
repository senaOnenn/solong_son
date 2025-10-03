/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42istanbul.com.tr     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:51:55 by eonen             #+#    #+#             */
/*   Updated: 2025/10/01 16:02:46 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define ARROW_UP 65362
# define ARROW_LEFT 65361
# define ARROW_DOWN 65364
# define ARROW_RIGHT 65363

# ifndef TILE
#  define TILE 64
# endif

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		player_count;
	int		exit_count;
	int		coin_count;
}			t_map;

typedef struct s_gfx
{
	void	*mlx;
	void	*win;
	void	*img_floor;
	void	*img_wall;
	void	*img_coin;
	void	*img_exit;
	void	*img_player;
	int		moves;
	t_map	*m;
}			t_gfx;

int			control_extension(char *argv);
int			is_directory(const char *path);
int			check_file_readable(const char *path, int has_content);
void		free_map_data(t_map *map);
void		free_gfx_data(t_gfx *gfx);
void		free_all_and_exit(t_gfx *gfx, t_map *map);
void		error_code(int code, t_gfx *gfx, t_map *map);
void		ft_free_rr(char *rd, char *rt);
void		ft_close_and_free(char *rd, char *rt, t_map *map, t_gfx *gfx);
t_gfx		*init_gfx(t_map *m);
int		load_textures(t_gfx *g);
int			run_game(t_map *m);
void		init_maps(t_map *m);
int			can_move(t_map *m, int ny, int nx);
int			handle_exit(t_gfx *g, char target);
void		move_player(t_gfx *g, int dy, int dx);
int			on_key(int key, void *param);
int			on_destroy(void *param);
char		*chomp_newline(char *s);
int			append_line(char ***arr, int *h, char *line);
int			post_process(t_map *m);
int			read_map(const char *path, t_map *m);
void		*load_xpm(void *mlx, char *path);
void		put_img(t_gfx *g, void *img, int x, int y);
void		draw_cell(t_gfx *g, int y, int x);
void		redraw(t_gfx *g);
int			check_map_fits_screen(void *mlx, const t_map *m);
int			check_rectangular(const t_map *m);
int			is_allowed_char(char c);
int			check_charset_and_counts(t_map *m);
int			check_walls_closed(const t_map *m);
void ff_visit_flag(char **grid, int h, int w, int y, int x);
char		**dup_grid(const t_map *m, t_gfx *gfx);
void		free_grid(char **d, int h);
int reachable_coins_and_exit(t_map *m, char **map_copy);
int check_path(t_map *m);
int			validate_args(int argc, char **argv);
int			init_map_from_file(char *path, t_map *map);
int	count_tile(t_map *m, char c, int y, int x);
void	read_map_line(int fd, t_map *m);
void	validate_map(t_map *m);


#endif
