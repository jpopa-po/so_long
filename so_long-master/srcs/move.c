/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpopa-po <jpopa-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 09:10:19 by juancarlosp       #+#    #+#             */
/*   Updated: 2022/03/27 17:01:52 by jpopa-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_right(t_ptr *mlx)
{
	if (mlx->map_ref[mlx->player_y][mlx->player_x + 1] == '1')
		return ;
	if (mlx->map_ref[mlx->player_y][mlx->player_x + 1] == 'C')
		mlx->ent->collect--;
	if (mlx->map_ref[mlx->player_y][mlx->player_x + 1] == 'E'
		&& mlx->ent->collect == 0)
		exit (0);
	if (mlx->map_ref[mlx->player_y][mlx->player_x + 1] == 'E'
		&& mlx->ent->collect != 0)
		return ;
	mlx->player_x++;
	mlx->moves++;
	mlx->map_ref[mlx->player_y][mlx->player_x] = 'P';
	mlx->map_ref[mlx->player_y][mlx->player_x - 1] = '0';
	ft_print_img(mlx);
}

void	ft_left(t_ptr *mlx)
{
	if (mlx->map_ref[mlx->player_y][mlx->player_x - 1] == '1')
		return ;
	if (mlx->map_ref[mlx->player_y][mlx->player_x - 1] == 'C')
		mlx->ent->collect--;
	if (mlx->map_ref[mlx->player_y][mlx->player_x - 1] == 'E'
		&& mlx->ent->collect == 0)
		exit(0);
	if (mlx->map_ref[mlx->player_y][mlx->player_x - 1] == 'E'
		&& mlx->ent->collect != 0)
		return ;
	mlx->player_x--;
	mlx->moves++;
	mlx->map_ref[mlx->player_y][mlx->player_x] = 'P';
	mlx->map_ref[mlx->player_y][mlx->player_x + 1] = '0';
	ft_print_img(mlx);
}

void	ft_up(t_ptr *mlx)
{
	if (mlx->map_ref[mlx->player_y + 1][mlx->player_x] == '1')
		return ;
	if (mlx->map_ref[mlx->player_y + 1][mlx->player_x] == 'C')
		mlx->ent->collect--;
	if (mlx->map_ref[mlx->player_y + 1][mlx->player_x] == 'E'
		&& mlx->ent->collect == 0)
		exit (0);
	if (mlx->map_ref[mlx->player_y + 1][mlx->player_x] == 'E'
		&& mlx->ent->collect != 0)
		return ;
	mlx->player_y++;
	mlx->moves++;
	mlx->map_ref[mlx->player_y][mlx->player_x] = 'P';
	mlx->map_ref[mlx->player_y - 1][mlx->player_x] = '0';
	ft_print_img(mlx);
}

void	ft_down(t_ptr *mlx)
{
	if (mlx->map_ref[mlx->player_y - 1][mlx->player_x] == '1')
		return ;
	if (mlx->map_ref[mlx->player_y - 1][mlx->player_x] == 'C')
		mlx->ent->collect--;
	if (mlx->map_ref[mlx->player_y - 1][mlx->player_x] == 'E'
		&& mlx->ent->collect == 0)
		exit (0);
	if (mlx->map_ref[mlx->player_y - 1][mlx->player_x] == 'E'
		&& mlx->ent->collect != 0)
		return ;
	mlx->player_y--;
	mlx->moves++;
	mlx->map_ref[mlx->player_y][mlx->player_x] = 'P';
	mlx->map_ref[mlx->player_y + 1][mlx->player_x] = '0';
	ft_print_img(mlx);
}
