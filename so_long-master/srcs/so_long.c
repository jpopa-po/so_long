/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpopa-po <jpopa-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 09:10:27 by juancarlosp       #+#    #+#             */
/*   Updated: 2022/03/22 20:15:48 by jpopa-po         ###   ########.fr       */
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
	exit (0);
}

int	ft_close(t_ptr *mlx)
{
	ft_free(mlx->map_ref, mlx->map.size / mlx->map.len);
	exit(0);
	return (0);
}

int	ft_key_event(int key, t_ptr *mlx)
{
	if (key == 123)
		ft_left(mlx);
	if (key == 124)
		ft_right(mlx);
	if (key == 125)
		ft_up(mlx);
	if (key == 126)
		ft_down(mlx);
	if (key == 53)
		ft_close(mlx);
	printf("moves = %d\n", mlx->moves);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_ptr	*mlx;

	if (argc != 2)
	{
		printf("Invalid arguments\n");
		return (1);
	}
	mlx = ft_calloc(sizeof(t_ptr), 1);
	mlx->map = ft_make(argv, mlx);
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, (mlx->map.len - 1) * 32,
			(mlx->map.size / mlx->map.len) * 32, "Hello world!");
	ft_print_img(mlx);
	mlx->moves = 0;
	mlx->cond = 1;
	mlx_hook(mlx->win, 17, 1L << 17, ft_close, mlx);
	mlx_key_hook(mlx->win, ft_key_event, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
