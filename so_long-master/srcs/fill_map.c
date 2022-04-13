/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpopa-po <jpopa-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 09:10:05 by juancarlosp       #+#    #+#             */
/*   Updated: 2022/04/13 19:52:36 by jpopa-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

t_img	ft_init_img(void *mlx_ptr)
{
	t_img	img;

	img.wall = mlx_xpm_file_to_image(mlx_ptr, "imgs/wall.xpm",
			&img.width, &img.height);
	img.character = mlx_xpm_file_to_image(mlx_ptr, "imgs/PJ.xpm",
			&img.width, &img.height);
	img.background = mlx_xpm_file_to_image(mlx_ptr, "imgs/BKG.xpm",
			&img.width, &img.height);
	img.collect = mlx_xpm_file_to_image(mlx_ptr, "imgs/pickable.xpm",
			&img.width, &img.height);
	img.door = mlx_xpm_file_to_image(mlx_ptr, "imgs/portal.xpm", &img.width,
			&img.height);
	img.enemy = mlx_xpm_file_to_image(mlx_ptr, "imgs/PJ.xpm",
			&img.width, &img.height);
	return (img);
}

void	ft_entity(t_ptr *mlx, t_img img, int i, int j)
{
	if (mlx->map_ref[i][j] == '1')
		mlx_put_image_to_window(mlx->ptr, mlx->win, img.wall, j * 32, i * 32);
	if (mlx->map_ref[i][j] == '0')
		mlx_put_image_to_window(mlx->ptr, mlx->win,
			img.background, j * 32, i * 32);
	if (mlx->map_ref[i][j] == 'P')
	{
		mlx_put_image_to_window(mlx->ptr, mlx->win,
			img.character, j * 32, i * 32);
		mlx->player_x = j;
		mlx->player_y = i;
	}
	if (mlx->map_ref[i][j] == 'E')
		mlx_put_image_to_window(mlx->ptr, mlx->win,
			img.door, j * 32, i * 32);
	if (mlx->map_ref[i][j] == 'C')
		mlx_put_image_to_window(mlx->ptr, mlx->win,
			img.collect, j * 32, i * 32);
}

void	ft_print_img(t_ptr *mlx)
{
	int			i;
	int			j;
	t_img		img;

	img = ft_init_img(mlx->ptr);
	i = 0;
	while (i < (mlx->map.size / mlx->map.len))
	{
		j = 0;
		while (j < mlx->map.len)
		{
			ft_entity(mlx, img, i, j);
			j++;
		}
		i++;
	}
}
