/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42istanbul.com.tr     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:51:30 by eonen             #+#    #+#             */
/*   Updated: 2025/10/01 14:10:39 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_args(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Usage: ./so_long <map.ber>\n", 28);
		return (0);
	}
	if (!control_extension(argv[1]))
	{
		write(2, "Error: wrong extension (.ber required)\n", 39);
		return (0);
	}
	if (!check_file_readable(argv[1], 0))
		return (0);
	return (1);
}

int	init_map_from_file(char *path, t_map *map)
{
	if (!read_map(path, map))
		return (0);
	return (1);
}

int main(int argc, char **argv) 
{ 
	t_map *map; 
	map = malloc(sizeof(t_map)); 
	if (!map) 
		return (write(2, "Error: malloc\n", 14), 1); 
	if (!validate_args(argc, argv)) 
		return (free(map), 1); 
	if (!init_map_from_file(argv[1], map)) 
		return (free(map), 1); 
	run_game(map); 
	return (0); 
}

// int	main(int argc, char **argv)
// {
// 	t_map	*map;

// 	map = malloc(sizeof(t_map));
// 	if (!map)
// 		return (write(2, "Error: malloc\n", 14), 1);
// 	if (argc != 2)
// 	{
// 		write(2, "Usage: ./so_long <map.ber>\n", 28);
// 		free(map);
// 		return (1);
// 	}
// 	if (!control_extension(argv[1]))
// 	{
// 		write(2, "Error: wrong extension (.ber required)\n", 39);
// 		free(map);
// 		return (1);
// 	}
// 	if (!check_file_readable(argv[1], 0))
// 	{
// 		free(map);
// 		return (1);
// 	}
// 	if (!read_map(argv[1], map))
// 	{
// 		free(map);
// 		return (1);
// 	}
// 	if (!run_game(map))
// 	{
// 		free_all_and_exit(NULL, map); // run_game başarısızsa safe exit
// 	}
// 	free_all_and_exit(NULL, map); // normal exit
// 	return (0);
// }
