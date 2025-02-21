/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:47:00 by asyani            #+#    #+#             */
/*   Updated: 2025/02/07 11:47:49 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * free_map _ fucntion t free map
 * @map: map to be frred
 */
void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

/**
 * free_map_copy _ teh function that free map_copy
 * @matrix: the struct that contains row
 * @map: the map that will be freed
 */
void	free_map_copy(t_pos *matrix, char **map)
{
	int	i;

	i = 0;
	while (i < matrix->row)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

/**
 * ft_error _ function to clean and prnt error message
 * @matrix: a struct that hold map with other elements
 */
void	ft_error(t_pos *matrix)
{
	free_map(matrix->map);
	free(matrix);
	perror("Map is not valid");
	exit(1);
}

/**
 * ft_putstr_fd _ the function that print to any side
 * @s: the strin g that will be printed
 * @fd: the file discriptor that will print to it
 */
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || fd == -1)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

/**
 * write_number _ function to write number
 * @n: the number that will be written
 */
void	write_number(int n)
{
	if (n > 9)
	{
		write_number(n / 10);
	}
	n = n % 10 + '0';
	write(1, &n, 1);
}
