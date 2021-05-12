/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dda_wall1.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/04 19:20:47 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/05 22:16:43 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	---------------------------------------------------------------------------
** calculate ray position and direction
** cameraX: x-coordinate in camera space
**	---------------------------------------------------------------------------
*/

void	ft_calc_ray(t_cub *cub, int x)
{
	double camera_x;

	camera_x = 2 * x / (double)cub->screen_w - 1;
	cub->dda_wall.ray_dx = cub->player.dx + cub->player.plane_x * camera_x;
	cub->dda_wall.ray_dy = cub->player.dy + cub->player.plane_y * camera_x;
}

/*
**	---------------------------------------------------------------------------
**	which box of the map we're in
**	---------------------------------------------------------------------------
*/

void	ft_which_box_player(t_dda_wall *dw, t_player *player)
{
	dw->map_box_x = (int)player->px;
	dw->map_box_y = (int)player->py;
}

/*
**	---------------------------------------------------------------------------
**	length of ray from one x or y-side to next x or y-side
**	fabs used instead of abs since where dealing with  floating points
**	---------------------------------------------------------------------------
*/

void	ft_calc_delta(t_dda_wall *dw)
{
	if (dw->ray_dy == 0)
		dw->delta_dist_x = 0;
	else if (dw->ray_dx == 0)
		dw->delta_dist_x = 1;
	else
		dw->delta_dist_x = fabs(1 / dw->ray_dx);
	if (dw->ray_dx == 0)
		dw->delta_dist_y = 0;
	else if (dw->ray_dy == 0)
		dw->delta_dist_y = 1;
	else
		dw->delta_dist_y = fabs(1 / dw->ray_dy);
}

/*
**	---------------------------------------------------------------------------
**	what direction to step in x or y-direction (either +1 or -1)
**	step_x;
**	step_y;
**	calculate step and initial sideDist
**	---------------------------------------------------------------------------
*/

void	ft_calc_steps_side_dist(t_dda_wall *dw, t_player *player)
{
	if (dw->ray_dx < 0)
	{
		dw->step_x = -1;
		dw->side_dist_x = (player->px - dw->map_box_x)
								* dw->delta_dist_x;
	}
	else
	{
		dw->step_x = 1;
		dw->side_dist_x = (dw->map_box_x + 1.0 - player->px)
								* dw->delta_dist_x;
	}
	if (dw->ray_dy < 0)
	{
		dw->step_y = -1;
		dw->side_dist_y = (player->py - dw->map_box_y)
								* dw->delta_dist_y;
	}
	else
	{
		dw->step_y = 1;
		dw->side_dist_y = (dw->map_box_y + 1.0 - player->py)
								* dw->delta_dist_y;
	}
}

/*
**	---------------------------------------------------------------------------
**	jump to next map square, OR in x-direction, OR in y-direction
**	---------------------------------------------------------------------------
*/

void	ft_jump_next_square(t_dda_wall *dw)
{
	if (dw->side_dist_x < dw->side_dist_y)
	{
		dw->side_dist_x += dw->delta_dist_x;
		dw->map_box_x += dw->step_x;
		dw->side = 0;
	}
	else
	{
		dw->side_dist_y += dw->delta_dist_y;
		dw->map_box_y += dw->step_y;
		dw->side = 1;
	}
}
