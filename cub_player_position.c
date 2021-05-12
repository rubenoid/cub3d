/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub_player_position.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/04 19:08:13 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/04 19:08:16 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_player_north(t_player *player, double x, double y)
{
	player->px = x + 0.5;
	player->py = y + 0.5;
	player->dx = -1;
	player->dy = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
}

static void	ft_player_south(t_player *player, double x, double y)
{
	player->px = x + 0.5;
	player->py = y + 0.5;
	player->dx = 1;
	player->dy = 0;
	player->plane_x = 0;
	player->plane_y = -0.66;
}

static void	ft_player_west(t_player *player, double x, double y)
{
	player->px = x + 0.5;
	player->py = y + 0.5;
	player->dx = 0;
	player->dy = -1;
	player->plane_x = -0.66;
	player->plane_y = 0;
}

static void	ft_player_east(t_player *player, double x, double y)
{
	player->px = x + 0.5;
	player->py = y + 0.5;
	player->dx = 0;
	player->dy = 1;
	player->plane_x = 0.66;
	player->plane_y = 0;
}

void		ft_set_player_position(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	while (i < cub->map_h)
	{
		j = 0;
		while (j < cub->map_w)
		{
			if (cub->map[i][j] == 6)
				ft_player_north(&cub->player, i, j);
			if (cub->map[i][j] == 7)
				ft_player_south(&cub->player, i, j);
			if (cub->map[i][j] == 8)
				ft_player_west(&cub->player, i, j);
			if (cub->map[i][j] == 9)
				ft_player_east(&cub->player, i, j);
			j++;
		}
		i++;
	}
}
