/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42istanbul.com.tr     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:53:08 by eonen             #+#    #+#             */
/*   Updated: 2025/10/01 13:04:38 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_move(t_map *m, int ny, int nx)
{
	char	target;

	if (ny < 0 || ny >= m->height || nx < 0 || nx >= m->width)
		return (0);
	target = m->map[ny][nx];
	if (target == 1)
		return (0);
	if (target == 'E' && m->coin_count > 0)
		return (0);
	return (1);
}

int	handle_exit(t_gfx *g, char target)
{
	if (target == 'E' && g->m->coin_count == 0)
	{
		g->moves++;
		redraw(g);
		write(1, "Congrats! You win.\n", 19);
		mlx_loop_end(g->mlx);
		return (1);
	}
	return (0);
}

void	move_player(t_gfx *g, int dy, int dx)
{
	int		ny;
	int		nx;
	char	target;

	ny = g->m->player_y + dy;
	nx = g->m->player_x + dx;
	if (!can_move(g->m, ny, nx))
		return ;
	target = g->m->map[ny][nx];
	if (target == 'C')
		g->m->coin_count--;
	g->m->map[g->m->player_y][g->m->player_x] = '0';
	g->m->player_y = ny;
	g->m->player_x = nx;
	if (handle_exit(g, target))
		return ;
	g->m->map[ny][nx] = 'P';
	g->moves++;
	redraw(g);
}

int	on_key(int key, void *param)
{
	t_gfx	*g;

	g = (t_gfx *)param;
	if (key == KEY_ESC)
	{
		mlx_loop_end(g->mlx);
		return (0);
	}
	if (key == KEY_W || key == ARROW_UP)
		move_player(g, -1, 0);
	else if (key == KEY_S || key == ARROW_DOWN)
		move_player(g, 1, 0);
	else if (key == KEY_A || key == ARROW_LEFT)
		move_player(g, 0, -1);
	else if (key == KEY_D || key == ARROW_RIGHT)
		move_player(g, 0, 1);
	return (0);
}

int	on_destroy(void *param)
{
	t_gfx	*g;

	g = (t_gfx *)param;
	if (g)
		free_all_and_exit(g, g->m);
	else
		exit(EXIT_SUCCESS);
	return (0);
}
