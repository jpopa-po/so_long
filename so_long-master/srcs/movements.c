/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancarlospopapopa <juancarlospopapopa@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 09:10:19 by juancarlosp       #+#    #+#             */
/*   Updated: 2022/03/18 09:10:20 by juancarlosp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_left_move(t_pointers *mlx)
{
	if (mlx->map_ref[mlx->player_y][mlx->player_x - 1] == '1')
		return ;
	if (mlx->map_ref[mlx->player_y][mlx->player_x - 1] == 'C')
		mlx->elem->collect--;
	if (mlx->map_ref[mlx->player_y][mlx->player_x - 1] == 'E'
		&& mlx->elem->collect == 0)
		exit(0);
	if (mlx->map_ref[mlx->player_y][mlx->player_x - 1] == 'E'
		&& mlx->elem->collect != 0)
		return ;
	mlx->player_x--;
	mlx->moves++;
	mlx->map_ref[mlx->player_y][mlx->player_x] = 'P';
	mlx->map_ref[mlx->player_y][mlx->player_x + 1] = '0';
	ft_fill_map_with_images(mlx);
}

void	ft_right_move(t_pointers *mlx)
{
	if (mlx->map_ref[mlx->player_y][mlx->player_x + 1] == '1')
		return ;
	if (mlx->map_ref[mlx->player_y][mlx->player_x + 1] == 'C')
		mlx->elem->collect--;
	if (mlx->map_ref[mlx->player_y][mlx->player_x + 1] == 'E'
		&& mlx->elem->collect == 0)
		exit (0);
	if (mlx->map_ref[mlx->player_y][mlx->player_x + 1] == 'E'
		&& mlx->elem->collect != 0)
		return ;
	mlx->player_x++;
	mlx->moves++;
	mlx->map_ref[mlx->player_y][mlx->player_x] = 'P';
	mlx->map_ref[mlx->player_y][mlx->player_x - 1] = '0';
	ft_fill_map_with_images(mlx);
}

void	ft_up_move(t_pointers *mlx)
{
	if (mlx->map_ref[mlx->player_y + 1][mlx->player_x] == '1')
		return ;
	if (mlx->map_ref[mlx->player_y + 1][mlx->player_x] == 'C')
		mlx->elem->collect--;
	if (mlx->map_ref[mlx->player_y + 1][mlx->player_x] == 'E'
		&& mlx->elem->collect == 0)
		exit (0);
	if (mlx->map_ref[mlx->player_y + 1][mlx->player_x] == 'E'
		&& mlx->elem->collect != 0)
		return ;
	mlx->player_y++;
	mlx->moves++;
	mlx->map_ref[mlx->player_y][mlx->player_x] = 'P';
	mlx->map_ref[mlx->player_y - 1][mlx->player_x] = '0';
	ft_fill_map_with_images(mlx);
}

void	ft_down_move(t_pointers *mlx)
{
	if (mlx->map_ref[mlx->player_y - 1][mlx->player_x] == '1')
		return ;
	if (mlx->map_ref[mlx->player_y - 1][mlx->player_x] == 'C')
		mlx->elem->collect--;
	if (mlx->map_ref[mlx->player_y - 1][mlx->player_x] == 'E'
		&& mlx->elem->collect == 0)
		exit (0);
	if (mlx->map_ref[mlx->player_y - 1][mlx->player_x] == 'E'
		&& mlx->elem->collect != 0)
		return ;
	mlx->player_y--;
	mlx->moves++;
	mlx->map_ref[mlx->player_y][mlx->player_x] = 'P';
	mlx->map_ref[mlx->player_y + 1][mlx->player_x] = '0';
	ft_fill_map_with_images(mlx);
}
