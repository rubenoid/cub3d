/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement_utils0.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/05 22:53:02 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/05 22:55:30 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	ft_move_forward(t_player *player, t_cub *cub)
{
	if (cub->map[(int)(player->px + player->dx * 1.1 * player->move_speed)]
		[(int)player->py] != 1)
		player->px += player->dx * player->move_speed;
	if (cub->map[(int)player->px]
		[(int)(player->py + player->dy * 1.1 * player->move_speed)] != 1)
		player->py += player->dy * player->move_speed;
}

void	ft_move_backwards(t_player *player, t_cub *cub)
{
	if (cub->map[(int)(player->px - player->dx * 1.1 * player->move_speed)]
		[(int)(player->py)] != 1)
		player->px -= player->dx * player->move_speed;
	if (cub->map[(int)(player->px)]
		[(int)(player->py - player->dy * 1.1 * player->move_speed)] != 1)
		player->py -= player->dy * player->move_speed;
}

void	ft_strafe_left(t_player *player, t_cub *cub)
{
	if (cub->map[(int)(player->px - player->dy * 1.1 * player->move_speed)]
		[(int)player->py] != 1)
		player->px -= player->dy * player->move_speed;
	if (cub->map[(int)player->px]
		[(int)(player->py + player->dx * 1.1 * player->move_speed)] != 1)
		player->py += player->dx * player->move_speed;
}

void	ft_strafe_right(t_player *player, t_cub *cub)
{
	if (cub->map[(int)(player->px + player->dy * 1.1 * player->move_speed)]
		[(int)player->py] != 1)
		player->px += player->dy * player->move_speed;
	if (cub->map[(int)player->px]
		[(int)(player->py - player->dx * 1.1 * player->move_speed)] != 1)
		player->py -= player->dx * player->move_speed;
}
