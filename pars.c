/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:48:12 by asyani            #+#    #+#             */
/*   Updated: 2025/02/07 11:47:47 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * check_map _ function to check map for valid map
 *@matrix: a struct that contains map and other elements
*/
void	check_map(t_pos *matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < matrix->col - 1)
	{
		if (matrix->map[0][j] != '1' || matrix->map[matrix->row - 1][j] != '1')
			ft_error(matrix);
		j++;
	}
	while (i < matrix->row)
	{
		if (matrix->map[i][0] != '1' || matrix->map[i][matrix->col - 2] != '1')
			ft_error(matrix);
		i++;
	}
	check_inside(matrix);
}

/**
 * fill_map _ a function that fill the map from a file
 * @matrix:  the struct that contains map and other elem
 * @av: line argument to fitch the map from a file
 */
void	fill_map(t_pos *matrix, char **av)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (!fd)
		perror("fail to open file");
	line = get_next_line(fd);
	while (line && i < matrix->row)
	{
		j = 0;
		while (line[j] && j < matrix->col - 1)
		{
			matrix->map[i][j] = line[j];
			j++;
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	check_map(matrix);
}

/**
 * allocation _  function to allocate memory for a map
 * @matrix:  struct that contains all elem
 */
void	allocation(t_pos *matrix)
{
	int	i;

	matrix->map = (char **)malloc(sizeof(char *) * (matrix->row + 1));
	if (!matrix->map)
		free_map(matrix->map);
	i = 0;
	while (i < matrix->row)
	{
		matrix->map[i] = (char *)malloc(sizeof(char) * (matrix->col - 1));
		if (!matrix->map[i])
			free_map(matrix->map);
		i++;
	}
	matrix->map[matrix->row] = NULL;
}

/**
 * pars_map _ fucntion to start parsing the map
 * @fd: the file descriptor to open
 * @av: the argument that I should pars
 */
void	pars_map(int fd, char **av)
{
	char	*line;
	t_pos	*matrix;
	int		i;

	i = 0;
	matrix = malloc(sizeof(t_pos));
	if (!matrix)
	{
		perror("Memory allocation failed");
		return ;
	}
	matrix->map = NULL;
	matrix->row = 0;
	matrix->col = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		while (line[i])
		{
			i++;
			matrix->col++;
		}
		matrix->row++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	allocation(matrix);
	fill_map(matrix, av);
	so_long(matrix);
}

int	main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		ft_putstr_fd("❌ The game must take 2 argument!!\n", 2);
		return (1);
	}
	// check for .ber file they should not eneter if a file just .ber
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		perror("fail to open file");
		exit(1);
	}
	pars_map(fd, av);
	return (0);
}
