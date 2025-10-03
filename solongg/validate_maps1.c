/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_maps1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42istanbul.com.tr     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:12:21 by eonen             #+#    #+#             */
/*   Updated: 2025/10/01 21:02:47 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_count(t_map *m)
{
	if (m->player_count != 1)
		return (write(2, "Error: invalid player count\n", 29));
	if (m->exit_count != 1)
		return (write(2, "Error: invalid exit count\n", 27));
	if (m->coin_count < 1)
		return (write(2, "Error: invalid coins on map\n", 27));
	return (1);
}

void	init_counts(t_map *m)
{
	m->player_count = 0;
	m->exit_count = 0;
	m->coin_count = 0;
	m->player_x = -1;
	m->player_y = -1;
}

int	check_charset_and_counts(t_map *m)
{
	int		y;
	int		x;
	char	c;

	if (!m || !m->map)
		return (0);
	init_counts(m);
	y = 0;
	while (y < m->height)
	{
		x = 0;
		while (x < m->width)
		{
			c = m->map[y][x];
			if (!is_allowed_char(c))
				return (0);
			count_tile(m, c, y, x);
			x++;
		}
		y++;
	}
	return (validate_count(m));
}

int	check_walls_closed(const t_map *m)
{
	int	x;
	int	y;

	if (!m || !m->map)
		return (0);
	if (m->width <= 0 || m->height <= 0)
		return (0);
	x = 0;
	while (x < m->width)
	{
		if (m->map[0][x] != '1' || m->map[m->height - 1][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (y < m->height)
	{
		if (m->map[y][0] != '1' || m->map[y][m->width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

void ff_visit_flag(char **grid, int h, int w, int y, int x)
{
    if (y < 0 || y >= h || x < 0 || x >= w)
        return;
    if (grid[y][x] == '1' || grid[y][x] == 'V')
        return;
    if (grid[y][x] == 'E')
        return;
    grid[y][x] = 'V';
    ff_visit_flag(grid, h, w, y - 1, x);
    ff_visit_flag(grid, h, w, y + 1, x);
    ff_visit_flag(grid, h, w, y, x - 1);
    ff_visit_flag(grid, h, w, y, x + 1);
}
