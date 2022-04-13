/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpopa-po <jpopa-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 09:09:11 by juancarlosp       #+#    #+#             */
/*   Updated: 2022/04/13 19:32:36 by jpopa-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_img
{
	void	*character;
	void	*background;
	void	*wall;
	void	*collect;
	void	*door;
	void	*enemy;
	int		width;
	int		height;
}			t_img;

typedef struct s_ent
{
	int	player;
	int	exit;
	int	collect;
}				t_ent;

typedef struct s_map
{
	int		size;
	int		len;
	int		height;
	char	*line;
	int		fd;
}				t_map;

typedef struct s_ptr
{
	void		*win;
	void		*ptr;
	char		**map_ref;
	int			player_y;
	int			player_x;
	int			enem_y;
	int			enem_x;
	int			cond;
	int			moves;
	t_map		map;
	t_ent		*ent;
	t_img		img;
}				t_ptr;
void		ft_valid_map(char **map, int num, int len);
void		ft_free(char **map, int i);
t_map		ft_make(char **argv, t_ptr *mlx);
void		ft_check(t_ptr *mlx);
int			ft_bool(t_ptr *mlx, char c);
void		ft_print_in(t_ptr *mlx);
int			ft_size(char **argv);
void		ft_free(char **map, int i);
void		ft_print_img(t_ptr *mlx);
void		ft_entity(t_ptr *mlx, t_img img, int i, int j);
t_img		ft_init_img(void *mlx_ptr);
int			ft_close(t_ptr *mlx);
int			ft_vent(int key, t_ptr *mlx);
void		ft_left(t_ptr *mlx);
void		ft_right(t_ptr *mlx);
void		ft_up(t_ptr *mlx);
void		ft_down(t_ptr *mlx);
size_t		max_len(char *s1, char *s2);
void		ft_error(char *str);
void		ft_check_args(int argc, char **argv);
int			ft_close2(t_ptr *mlx);
void		ft_free2(char **map, int i);
#endif
