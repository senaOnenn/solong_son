/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_maps2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42istanbul.com.tr     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:36:48 by eonen             #+#    #+#             */
/*   Updated: 2025/10/01 21:04:13 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**dup_grid(const t_map *m, t_gfx *gfx)
{
	char	**d;
	int		i;

	if (!m)
		return (NULL);
	d = (char **)malloc(sizeof(char *) * m->height);
	if (!d)
		free_all_and_exit(gfx, (t_map *)m);
	i = 0;
	while (i < m->height)
	{
		d[i] = ft_strdup(m->map[i]);
		if (!d[i])
		{
			while (--i >= 0)
				free(d[i]);
			free(d);
			free_all_and_exit(gfx, (t_map *)m);
		}
		i++;
	}
	return (d);
}


void	free_grid(char **d, int h)
{
	int	i;

	if (!d)
		return ;
	for (i = 0; i < h; i++)
		free(d[i]);
	free(d);
}

int reachable_coins_and_exit(t_map *m, char **map_copy)
{
    int y, x;
    int reachable_coins = 0;
    int exit_reachable = 0;

    for (y = 0; y < m->height; y++)
    {
        for (x = 0; x < m->width; x++)
        {
            if (m->map[y][x] == 'C')
            {
                if (map_copy[y][x] == 'V')
                    reachable_coins++;
                else
                    return 0; // Ulaşılamayan coin
            }
            if (m->map[y][x] == 'E' && map_copy[y][x] == 'V')
                exit_reachable = 1;
        }
    }
    // Coin sayısı ve exit kontrolü
    if (reachable_coins != m->coin_count || !exit_reachable)
        return 0;

    return 1;
}

int check_path(t_map *m)
{
    char **map_copy;
    int result;

    if (!m || m->player_x < 0 || m->player_y < 0)
        return 0;

    // Map'i kopyala
    map_copy = dup_grid(m, NULL);
    if (!map_copy)
        return 0;

    // Flood fill sadece kopya üzerinde
    ff_visit_flag(map_copy, m->height, m->width, m->player_y, m->player_x);

    // Coin ve exit kontrolü
    result = reachable_coins_and_exit(m, map_copy);

    free_grid(map_copy, m->height);
    return result;
}