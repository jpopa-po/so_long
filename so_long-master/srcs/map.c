/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpopa-po <jpopa-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 09:10:11 by juancarlosp       #+#    #+#             */
/*   Updated: 2022/03/22 20:12:35 by jpopa-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **map, int i)
{
	while (i >= 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
	printf("ERROR\n");
	exit (0);
}

int	ft_size(char **argv)
{
	char	*buff;
	int		i;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	buff = malloc(sizeof(char));
	i = 0;
	while (read(fd, buff, 1))
		i++;
	free(buff);
	close(fd);
	return (i);
}

void	ft_print_in(t_ptr *mlx)
{
	int	i;

	i = 0;
	mlx->map_ref[i] = mlx->map.line;
	while (mlx->map_ref[i])
	{
		if (ft_strlen(mlx->map_ref[i]) != (size_t)mlx->map.len)
			ft_free(mlx->map_ref, i);
		else
		{
			i++;
			mlx->map_ref[i] = get_next_line(mlx->map.fd);
		}
	}
}

void	ft_printmap(char **map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		printf("%s", map[i]);
		i++;
	}
}

void	ft_valid_map(char **map, int num, int len)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (j < len - 1)
			{
				if (map[0][j] != '1' || map[num - 1][j] != '1'
				|| map[i][0] != '1' || map[i][len - 2] != '1')
					ft_free(map, num);
			}
			j++;
		}
		i++;
	}
}
