/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42istanbul.com.tr     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:51:09 by eonen             #+#    #+#             */
/*   Updated: 2025/10/01 14:01:43 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Free map pointer’larını güvenli şekilde serbest bırak */
void	free_map_data(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->map)
	{
		i = 0;
		while (i < map->height)
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
		map->map = NULL;
	}
	free(map);
}

/* Free MLX ve img pointer’larını güvenli şekilde serbest bırak */
void	free_gfx_data(t_gfx *gfx)
{
	if (!gfx)
		return ;
	if (gfx->img_floor)
		mlx_destroy_image(gfx->mlx, gfx->img_floor);
	if (gfx->img_wall)
		mlx_destroy_image(gfx->mlx, gfx->img_wall);
	if (gfx->img_coin)
		mlx_destroy_image(gfx->mlx, gfx->img_coin);
	if (gfx->img_exit)
		mlx_destroy_image(gfx->mlx, gfx->img_exit);
	if (gfx->img_player)
		mlx_destroy_image(gfx->mlx, gfx->img_player);
	if (gfx->win)
		mlx_destroy_window(gfx->mlx, gfx->win);
	if (gfx->mlx)
	{
		mlx_destroy_display(gfx->mlx);
		free(gfx->mlx);
	}
	free(gfx);
}

void	free_all_and_exit(t_gfx *gfx, t_map *map)
{
	free_gfx_data(gfx);
	free_map_data(map);
	exit(EXIT_SUCCESS);
}

void	error_code(int code, t_gfx *gfx, t_map *map)
{
	if (code == -1)
		write(2, "Error: invalid extension\n", 26);
	else if (code == -2)
		write(2, "Error: map is not rectangular\n", 31);
	else if (code == -3)
		write(2, "Error: invalid component\n", 26);
	else if (code == -4)
		write(2, "Error: invalid component count\n", 32);
	else if (code == -5)
		write(2, "Error: invalid wall design\n", 28);
	else if (code == -6)
		write(2, "Error: unreachable component exist\n", 36);
	else if (code == -9)
		write(2, "Error: path is not a file\n", 27);
	else if (code == -10)
		write(2, "Error: empty file\n", 19);
	else if (code == -42)
		write(2, "Error: invalid argument count\n", 31);
	else if (code == -404)
		write(2, "Error: file not found\n", 23);
	else if (code == -500)
		write(2, "Error: malloc failed\n", 22);
	else
		write(1, "Exit Game\n", 11);
	free_all_and_exit(gfx, map);
}

