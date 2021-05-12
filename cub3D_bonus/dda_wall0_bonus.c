/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dda_wall0.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/04 19:14:34 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/05 22:21:28 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

/*
**	---------------------------------------------------------------------------
**	step: How much to increase the texture coordinate per screen pixel
**	tex_pos: Starting texture coordinate
**	---------------------------------------------------------------------------
*/

static void	ft_step_through_tex(t_dda_wall *dw, t_cub *cub)
{
	dw->step = 1.0 * dw->tex_height / dw->line_height;
	dw->tex_pos = (dw->draw_start - cub->pitch
					- (cub->pos_z / dw->perp_wall_dist)
					- cub->screen_h / 2 + dw->line_height / 2) * dw->step;
}

static void	ft_draw_wall(t_dda_wall *dw, t_cub *cub, int x)
{
	unsigned int color;

	while (dw->draw_start < dw->draw_end)
	{
		dw->tex_y = (int)dw->tex_pos;
		dw->tex_pos += dw->step;
		if (dw->box_num == 1)
		{
			if (dw->side == 0 && dw->map_box_x > cub->player.px)
				color = my_mlx_pixel_read(&cub->mlx, dw->tex_x,
										dw->tex_y, NORTH);
			if (dw->side == 0 && dw->map_box_x < cub->player.px)
				color = my_mlx_pixel_read(&cub->mlx, dw->tex_x,
										dw->tex_y, SOUTH);
			if (dw->side == 1 && dw->map_box_y > cub->player.py)
				color = my_mlx_pixel_read(&cub->mlx, dw->tex_x,
										dw->tex_y, WEST);
			if (dw->side == 1 && dw->map_box_y < cub->player.py)
				color = my_mlx_pixel_read(&cub->mlx, dw->tex_x,
										dw->tex_y, EAST);
			my_mlx_pixel_put(&cub->mlx, x, dw->draw_start, color);
		}
		dw->draw_start++;
	}
}

static void	ft_dda_walls(t_cub *cub, t_dda_wall *dw, t_player *player, int x)
{
	ft_jump_next_square(dw);
	if (cub->map[dw->map_box_x][dw->map_box_y] == 1)
		dw->hit = 1;
	ft_calc_dist_projection(dw, &cub->player);
	dw->line_height = (int)(cub->screen_h / dw->perp_wall_dist);
	ft_calc_draw_start_end(cub, dw);
	dw->box_num = cub->map[dw->map_box_x][dw->map_box_y];
	ft_calc_wall_x(dw, player);
	ft_calc_tex_width_height(dw, player, &cub->mlx);
	ft_calc_x_coord_tex(dw);
	ft_step_through_tex(dw, cub);
	if (dw->hit == 1)
		ft_draw_wall(dw, cub, x);
}

void		ft_walls(t_cub *cub, t_dda_wall *dw)
{
	int x;

	x = 0;
	while (x < (int)cub->screen_w)
	{
		dw->hit = 0;
		dw->side = 0;
		ft_calc_ray(cub, x);
		ft_which_box_player(dw, &cub->player);
		ft_calc_delta(dw);
		ft_calc_steps_side_dist(dw, &cub->player);
		ft_dda_walls(cub, dw, &cub->player, x);
		while (dw->hit == 0)
			ft_dda_walls(cub, dw, &cub->player, x);
		cub->z_buffer[x] = dw->perp_wall_dist;
		x++;
	}
}
