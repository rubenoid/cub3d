/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement_utils2.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/05 22:56:37 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/05 23:02:53 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_rot_left(t_player *player)
{
	double old_dx;
	double old_plane_x;

	old_dx = player->dx;
	old_plane_x = player->plane_x;
	player->dx = player->dx * cos(player->rot_speed)
					- player->dy * sin(player->rot_speed);
	player->dy = old_dx * sin(player->rot_speed)
					+ player->dy * cos(player->rot_speed);
	player->plane_x = player->plane_x * cos(player->rot_speed)
					- player->plane_y * sin(player->rot_speed);
	player->plane_y = old_plane_x * sin(player->rot_speed) + player->plane_y
					* cos(player->rot_speed);
}

void	ft_rot_right(t_player *player)
{
	double old_dx;
	double old_plane_x;

	old_dx = player->dx;
	old_plane_x = player->plane_x;
	player->dx = player->dx * cos(-player->rot_speed)
					- player->dy * sin(-player->rot_speed);
	player->dy = old_dx * sin(-player->rot_speed)
					+ player->dy * cos(-player->rot_speed);
	player->plane_x = player->plane_x * cos(-player->rot_speed)
					- player->plane_y * sin(-player->rot_speed);
	player->plane_y = old_plane_x * sin(-player->rot_speed) + player->plane_y
					* cos(-player->rot_speed);
}
