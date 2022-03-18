/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancarlospopapopa <juancarlospopapopa@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 09:09:58 by juancarlosp       #+#    #+#             */
/*   Updated: 2022/03/18 09:26:44 by juancarlosp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_enem_right(t_pointers *mlx)
{
	mlx->enem_x--;
	mlx->map_ref[mlx->enem_y][mlx->enem_x] = 'N';
	mlx->map_ref[mlx->enem_y][mlx->enem_x + 1] = '0';
	return (0);
}

int	ft_enem_left(t_pointers *mlx)
{
	mlx->enem_x++;
	mlx->map_ref[mlx->enem_y][mlx->enem_x] = 'N';
	mlx->map_ref[mlx->enem_y][mlx->enem_x - 1] = '0';
	return (1);
}

void	ft_enemy_attack(t_pointers *mlx)
{
	if (mlx->map_ref[mlx->enem_y][mlx->enem_x + 1] == 'P')
	{
		printf("HOLAAAAAA\n");
		ft_closewin(mlx);
	}
}

int	ft_enemy_moves(int cond, t_pointers *mlx)
{
	if (cond == 1)
	{
		ft_enemy_attack(mlx);
		if (mlx->map_ref[mlx->enem_y][mlx->enem_x + 1] == '1' ||
		mlx->map_ref[mlx->enem_y][mlx->enem_x + 1] == 'C'||
		mlx->map_ref[mlx->enem_y][mlx->enem_x + 1] == 'E')
			return (ft_enem_right(mlx));
		else
			return (ft_enem_left(mlx));
	}
	if (cond == 0)
	{
		ft_enemy_attack(mlx);
		if (mlx->map_ref[mlx->enem_y][mlx->enem_x - 1] == '1' ||
		mlx->map_ref[mlx->enem_y][mlx->enem_x - 1] == 'C'||
		mlx->map_ref[mlx->enem_y][mlx->enem_x - 1] == 'E')
			return (ft_enem_left(mlx));
		else
			return (ft_enem_right(mlx));
	}
	return (1);
}
