/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpopa-po <jpopa-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 09:09:47 by juancarlosp       #+#    #+#             */
/*   Updated: 2022/04/11 21:11:58 by jpopa-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_size(char **argv)
{
	char	*buff;
	int		i;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("Error, no file found\n");
	buff = malloc(sizeof(char));
	i = 0;
	while (read(fd, buff, 1))
		i++;
	free(buff);
	close(fd);
	return (i);
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

int	ft_bool(t_ptr *mlx, char c)
{
	if (c == 'P')
		mlx->ent->player += 1;
	if (c == 'E')
		mlx->ent->exit += 1;
	if (c == 'C')
		mlx->ent->collect += 1;
	if (c != 'P' && c != 'E' && c != 'C'
		&& c != '1' && c != '0' && c != '\n')
		ft_close(mlx);
	return (0);
}

void	ft_check(t_ptr *mlx)
{
	int		i;
	int		j;
	int		num;

	mlx->ent = ft_calloc(sizeof(t_ent), 1);
	mlx->ent->player = 0;
	mlx->ent->exit = 0;
	mlx->ent->collect = 0;
	i = 0;
	num = mlx->map.size / mlx->map.len;
	ft_valid_map(mlx->map_ref, num, mlx->map.len);
	while (mlx->map_ref[i])
	{
		j = 0;
		while (mlx->map_ref[i][j])
		{
			ft_bool(mlx, mlx->map_ref[i][j]);
			j++;
		}
		i++;
	}
	if (mlx->ent->player != 1 || mlx->ent->exit != 1)
		ft_free(mlx->map_ref, mlx->map.size / mlx->map.len);
}

t_map	ft_make(char **argv, t_ptr *mlx)
{
	mlx->map.size = ft_size(argv);
	if (mlx->map.size == 0)
		exit(0);
	mlx->map.fd = open(argv[1], O_RDONLY);
	mlx->map.line = get_next_line(mlx->map.fd);
	mlx->map.len = ft_strlen(mlx->map.line);
	mlx->map_ref = ft_calloc(sizeof(char *), mlx->map.size / mlx->map.len + 1);
	ft_print_in(mlx);
	ft_check(mlx);
	close(mlx->map.fd);
	return (mlx->map);
}
