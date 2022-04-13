/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpopa-po <jpopa-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 09:10:27 by juancarlosp       #+#    #+#             */
/*   Updated: 2022/04/13 19:49:42 by jpopa-po         ###   ########.fr       */
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
	ft_error("Error, not valid map\n");
}

int	ft_key_event(int key, t_ptr *mlx)
{
	if (key == 0)
		ft_left(mlx);
	if (key == 2)
		ft_right(mlx);
	if (key == 1)
		ft_up(mlx);
	if (key == 13)
		ft_down(mlx);
	if (key == 53)
		ft_close2(mlx);
	printf("moves = %d\n", mlx->moves);
	return (0);
}

int	ft_close(t_ptr *mlx)
{
	ft_free(mlx->map_ref, mlx->map.size / mlx->map.len);
	return (0);
}

void	ft_check_args(int argc, char **argv)
{
	int		len;
	char	*line;

	if (argc == 1)
		ft_error("Error, no map found\n");
	if (argc != 2)
		ft_error("Error, too many arguments\n");
	len = ft_strlen(argv[1]);
	if (ft_strrchr(argv[1], '.'))
	{
		line = ft_strnstr(argv[1], ".ber", len);
		if (ft_strlen(line) != 4)
			ft_error("Error, bad extension, try with a file that ends .ber\n");
		if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", \
			max_len(ft_strrchr(argv[1], '.'), ".ber")) != 0)
			ft_error("Error, bad extension, try with a file that ends .ber\n");
	}
	else
		ft_error("Error, incorrect extension, try with a file ended in .ber\n");
}

int	main(int argc, char *argv[])
{
	t_ptr	*mlx;

	ft_check_args(argc, argv);
	mlx = ft_calloc(sizeof(t_ptr), 1);
	mlx->map = ft_make(argv, mlx);
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, (mlx->map.len - 1) * 32,
			(mlx->map.size / mlx->map.len) * 32, "So_long by Popitaxx");
	ft_print_img(mlx);
	mlx->moves = 0;
	mlx->cond = 1;
	mlx_hook(mlx->win, 17, 1L << 17, ft_close, mlx);
	mlx_key_hook(mlx->win, ft_key_event, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
