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
	//check_screen_fit(m);
	return (1);
}
