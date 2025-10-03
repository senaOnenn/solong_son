/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42istanbul.com.tr     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:49:33 by eonen             #+#    #+#             */
/*   Updated: 2025/10/01 13:14:43 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_gfx	*init_gfx(t_map *m)
{
	t_gfx	*g;

	g = malloc(sizeof(t_gfx));
	if (!g)
		return (write(2, "Error: malloc t_gfx\n", 21), NULL);
	g->m = m;
	g->moves = 0;
	g->mlx = mlx_init();
	if (!g->mlx)
	{
		free(g);
		return(NULL);
	}
	g->win = mlx_new_window(g->mlx, m->width * TILE, m->height * TILE,
			"so_long");
	if (!g->win)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
		free(g);
		return (NULL);
	}
	return (g);
}

int	load_textures(t_gfx *g)
{
	g->img_floor = load_xpm(g->mlx, "images/floorresize.xpm");
	g->img_wall = load_xpm(g->mlx, "images/wall.xpm");
	g->img_coin = load_xpm(g->mlx, "images/coin.xpm");
	g->img_exit = load_xpm(g->mlx, "images/exit.xpm");
	g->img_player = load_xpm(g->mlx, "images/player.xpm");
	if (!g->img_floor || !g->img_wall || !g->img_coin || !g->img_exit
		|| !g->img_player)
		return (0);
	return (1);
}

int	run_game(t_map *m)
{
	t_gfx	*g;

	g = init_gfx(m);
	if (!g)
		return (0);

	if (!(load_textures(g)))
	{
		free_gfx_data(g);
		return (0);
	}

	redraw(g);
	mlx_hook(g->win, 2, 1L << 0, on_key, g);
	mlx_hook(g->win, 17, 0, on_destroy, g);
	mlx_loop(g->mlx);

	/* oyun bittikten sonra free et */
	free_all_and_exit(g, m);
	return (1);
}
