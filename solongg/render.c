/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42istanbul.com.tr     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:50:36 by eonen             #+#    #+#             */
/*   Updated: 2025/10/01 13:06:57 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*load_xpm(void *mlx, char *path)
{
	int	w;
	int	h;

	return (mlx_xpm_file_to_image(mlx, path, &w, &h));
}

void	put_img(t_gfx *g, void *img, int x, int y)
{
	if (img)
		mlx_put_image_to_window(g->mlx, g->win, img, x * TILE, y * TILE);
}

void	draw_cell(t_gfx *g, int y, int x)
{
	char	c;

	c = g->m->map[y][x];
	put_img(g, g->img_floor, x, y);
	if (c == '1')
		put_img(g, g->img_wall, x, y);
	else if (c == 'C')
		put_img(g, g->img_coin, x, y);
	else if (c == 'E')
		put_img(g, g->img_exit, x, y);
	else if (c == 'P')
		put_img(g, g->img_player, x, y);
}

void	redraw(t_gfx *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->m->height)
	{
		j = 0;
		while (j < g->m->width)
		{
			draw_cell(g, i, j);
			j++;
		}
		i++;
	}
}
