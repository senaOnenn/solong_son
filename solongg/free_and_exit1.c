/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42istanbul.com.tr     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:01:12 by eonen             #+#    #+#             */
/*   Updated: 2025/10/01 14:02:07 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_rr(char *rd, char *rt)
{
	if (rd)
	{
		free(rd);
		rd= NULL;
	}
	if (rt)
	{
		free(rt);
		rt = NULL;
	}
}

void	ft_close_and_free(char *rd, char *rt, t_map *map, t_gfx *gfx)
{
	ft_free_rr(rd, rt);
	error_code(-10, gfx, map);
}
