/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dda_wall2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/06 17:41:07 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/06 17:41:10 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
**	---------------------------------------------------------------------------
**	Calculate distance projected on camera direction
**	(Euclidean distance will give fisheye effect)
**	divide by 2.0 instead of 2 to keep float
**	---------------------------------------------------------------------------
*/

void	ft_calc_dist_projection(t_dda_wall *dw, t_player *player)
{
	if (dw->side == 0)
		dw->perp_wall_dist = (dw->map_box_x - player->px
							+ (1 - dw->step_x) / 2.0) / dw->ray_dx;
	else
		dw->perp_wall_dist = (dw->map_box_y - player->py
							+ (1 - dw->step_y) / 2.0) / dw->ray_dy;
}

/*
**	---------------------------------------------------------------------------
**	Calculate lowest and highest pixel to fill in current stripe
**	---------------------------------------------------------------------------
*/

void	ft_calc_draw_start_end(t_cub *cub, t_dda_wall *dw)
{
	dw->draw_start = -dw->line_height / 2
					+ cub->screen_h / 2 + cub->pitch
					+ (cub->pos_z / dw->perp_wall_dist);
	if (dw->draw_start < 0)
		dw->draw_start = 0;
	dw->draw_end = dw->line_height / 2
					+ cub->screen_h / 2 + cub->pitch
					+ (cub->pos_z / dw->perp_wall_dist);
	if (dw->draw_end >= (int)cub->screen_h)
		dw->draw_end = (int)cub->screen_h;
}

/*
**	---------------------------------------------------------------------------
**	calculate value of wall_hit_x
**	wall_hit_x: where exactly the wall was hit
**	---------------------------------------------------------------------------
*/

void	ft_calc_wall_x(t_dda_wall *dw, t_player *player)
{
	if (dw->side == 0)
		dw->wall_hit_x = player->py + dw->perp_wall_dist * dw->ray_dy;
	else
		dw->wall_hit_x = player->px + dw->perp_wall_dist * dw->ray_dx;
	dw->wall_hit_x -= floor((dw->wall_hit_x));
}

void	ft_calc_tex_width_height(t_dda_wall *dw, t_player *player, t_mlx *mlx)
{
	if (dw->side == 0 && dw->map_box_x > player->px)
	{
		dw->tex_width = mlx->tex_width[NORTH];
		dw->tex_height = mlx->tex_height[NORTH];
	}
	if (dw->side == 0 && dw->map_box_x < player->px)
	{
		dw->tex_width = mlx->tex_width[SOUTH];
		dw->tex_height = mlx->tex_height[SOUTH];
	}
	if (dw->side == 1 && dw->map_box_y > player->py)
	{
		dw->tex_width = mlx->tex_width[WEST];
		dw->tex_height = mlx->tex_height[WEST];
	}
	if (dw->side == 1 && dw->map_box_y < player->py)
	{
		dw->tex_width = mlx->tex_width[EAST];
		dw->tex_height = mlx->tex_height[EAST];
	}
}

void	ft_calc_x_coord_tex(t_dda_wall *dw)
{
	dw->tex_x = (int)(dw->wall_hit_x * (double)(dw->tex_width));
	if (dw->side == 0 && dw->ray_dx > 0)
		dw->tex_x = dw->tex_width - dw->tex_x - 1;
	if (dw->side == 1 && dw->ray_dy < 0)
		dw->tex_x = dw->tex_width - dw->tex_x - 1;
}
