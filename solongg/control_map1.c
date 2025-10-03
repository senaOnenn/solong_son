/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_map1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eonen <eonen@student.42istanbul.com.tr     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:50:56 by eonen             #+#    #+#             */
/*   Updated: 2025/10/01 13:59:51 by eonen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	control_extension(char *argv)
{
	int	len;

	if (!argv)
		return (0);
	len = ft_strlen(argv);
	if (len <= 4)
		return (0);
	if (argv[len - 5] && argv[len - 5] != '/' && argv[len - 4] == '.'
		&& argv[len - 3] == 'b' && argv[len - 2] == 'e' && argv[len - 1] == 'r')
		return (1);
	return (0);
}

int	is_directory(const char *path)
{
	int	directory_fd;

	directory_fd = open(path, O_DIRECTORY);
	if (directory_fd >= 0)
	{
		close(directory_fd);
		return (1);
	}
	return (0);
}

int	write_error(int mode)
{
	if (mode == 0)
		write(2, "Error\n", 6);
	else if (mode == 1)
		write(2, "Error: cannot read (is a directory)\n", 37);
	else if (mode == 2)
		write(2, "Error: empty file or file is not \n", 35);
	return (0);
}

int	check_file_readable(const char *path, int has_content)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return(write_error(0));
	if (is_directory(path))
	{
		close(fd);
		return(write_error(1));
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		has_content = 1;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!has_content)
		return(write_error(2));
	return (1);
}
