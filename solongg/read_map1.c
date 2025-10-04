/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42istanbul.com.tr     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:22:56 by eonen             #+#    #+#             */
/*   Updated: 2025/10/01 15:24:00 by eonen            ###   ########.fr       */
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

int	read_map(const char *path, t_map *m)
{
	int	fd;

	init_maps(m);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		free_all_and_exit(NULL, m);
	}
	read_map_line(fd, m);
	close(fd);
	validate_map(m);
	return (1);
}
