/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42istanbul.com.tr     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:51:40 by eonen             #+#    #+#             */
/*   Updated: 2025/10/01 14:26:23 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*chomp_newline(char *s)
{
	size_t	n;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	if (n && (s[n - 1] == '\n' || s[n - 1] == '\r'))
		s[n - 1] = '\0';
	return (s);
}

int	append_line(char ***arr, int *h, char *line)
{
	char	**tmp;
	int		i;

	tmp = (char **)malloc(sizeof(char *) * (*h + 2));
	if (!tmp)
		return (0);
	i = 0;
	while (i < *h)
	{
		tmp[i] = (*arr)[i];
		i++;
	}
	tmp[i++] = line;
	tmp[i] = NULL;
	free(*arr);
	*arr = tmp;
	(*h)++;
	return (1);
}

int	post_process(t_map *m)
{
	int	w;
	int	i;

	if (m->height == 0 || !m->map)
		return (0);
	w = (int)ft_strlen(m->map[0]);
	if (w == 0)
		return (0);
	m->width = w;
	i = 1;
	while (i < m->height)
	{
		if ((int)ft_strlen(m->map[i]) != w)
			return (0);
		i++;
	}
	m->width = w;
	return (1);
}

void	read_map_line(int fd, t_map *m)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		chomp_newline(line);
		if (line[0] == '\0')
		{
			free(line);
			close(fd);
			free_all_and_exit(NULL, m);
		}
		if (!(append_line(&m->map, &m->height, line)))
		{
			free(line);
			close(fd);
			free_all_and_exit(NULL, m);
		}
		line = get_next_line(fd);
	}
}

void	validate_map(t_map *m)
{
	if (!post_process(m))
		free_all_and_exit(NULL, m);
	if (!check_rectangular(m) || !check_charset_and_counts(m)
		|| !check_walls_closed(m) || !check_path(m))
		free_all_and_exit(NULL, m);
}

// int	read_map(const char *path, t_map *m)
// {
// 	int		fd;
// 	char	*line;
// 	void	*mlx;

// 	init_maps(m);
// 	fd = open(path, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("Error");
// 		free_all_and_exit(NULL, m);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		chomp_newline(line);
// 		if (line[0] == '\0')
// 		{
// 			free(line);
// 			close(fd);
// 			free_all_and_exit(NULL, m);
// 		}
// 		if (!append_line(&m->map, &m->height, line))
// 		{
// 			free(line);
// 			close(fd);
// 			free_all_and_exit(NULL, m);
// 		}
// 	}
// 	close(fd);
// 	if (!post_process(m))
// 		free_all_and_exit(NULL, m);
// 	if (!check_rectangular(m) || !check_charset_and_counts(m)
// 		|| !check_walls_closed(m) || !check_path(m))
// 		free_all_and_exit(NULL, m);
// 	mlx = mlx_init();
// 	if (!mlx)
// 		free_all_and_exit(NULL, m);
// 	if (!check_map_fits_screen(mlx, m))
// 	{
// 		mlx_destroy_display(mlx);
// 		free(mlx);
// 		free_all_and_exit(NULL, m);
// 	}
// 	mlx_destroy_display(mlx);
// 	free(mlx);
// 	return (1);
// }
