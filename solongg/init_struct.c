/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42istanbul.com.tr     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:51:21 by eonen             #+#    #+#             */
/*   Updated: 2025/09/30 14:51:24 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_maps(t_map *m)
{
	m->map = NULL;
	m->width = 0;
	m->height = 0;
	m->player_x = -1;
	m->player_y = -1;
	m->player_count = 0;
	m->exit_count = 0;
	m->coin_count = 0;
}
