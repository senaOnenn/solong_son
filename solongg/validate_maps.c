/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42istanbul.com.tr     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:52:05 by eonen             #+#    #+#             */
/*   Updated: 2025/10/01 16:36:06 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_fits_screen(void *mlx, const t_map *m)
{
	int	screen_w;
	int	screen_h;
	int	map_w;
	int	map_h;

	if (!mlx || !m)
		return (0);
	mlx_get_screen_size(mlx, &screen_w, &screen_h);
	map_w = m->width * 64;
	map_h = m->height * 64;
	if (map_w > screen_w || map_h > screen_h)
	{
		write(2, "Error: map too large for screen\n", 32);
		return (0);
	}
	return (1);
}

int	check_rectangular(const t_map *m)
{
	int	i;

	if (!m || !m->map)
	{
		write(2, "Error : invalid map structure\n", 30);
		return (0);
	}
	if (m->height <= 0 || m->width <= 0)
	{
		write(2, "Error : map has invalid dimensions\n", 30);
		return (0);
	}
	i = 0;
	while (i < m->height)
	{
		if ((int)ft_strlen(m->map[i]) != m->width)
		{
			write(2, "Error : map is not rectangular\n", 30);
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_allowed_char(char c)
{
	return (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C');
}

int	count_tile(t_map *m, char c, int y, int x)
{
	if (c == 'P')
	{
		m->player_count++;
		m->player_x = x;
		m->player_y = y;
	}
	else if (c == 'E')
		m->exit_count++;
	else if (c == 'C')
		m->coin_count++;
	return (1);
}
