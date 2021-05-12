/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dda_floor_ceiling0.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/05 21:35:09 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/05 22:42:02 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	ft_camera_fc(t_cub *cub, t_dda_fc *fc, int y)
{
	fc->p = fc->is_floor ? (y - (int)cub->screen_h / 2 - cub->pitch) :
				((int)cub->screen_h / 2 - y + cub->pitch);
	fc->cam_z = fc->is_floor ? (0.5 * (int)cub->screen_h + cub->pos_z) :
				(0.5 * (int)cub->screen_h - cub->pos_z);
	fc->row_dist = fc->cam_z / fc->p;
}

void	ft_calc_rays(t_cub *cub, t_dda_fc *fc)
{
	fc->raydx0 = cub->player.dx - cub->player.plane_x;
	fc->raydy0 = cub->player.dy - cub->player.plane_y;
	fc->raydx1 = cub->player.dx + cub->player.plane_x;
	fc->raydy1 = cub->player.dy + cub->player.plane_y;
}

void	calc_position_fc(t_dda_fc *fc)
{
	fc->cell_x = (int)(fc->fl_x);
	fc->cell_y = (int)(fc->fl_y);
	fc->fl_x += fc->fl_step_x;
	fc->fl_y += fc->fl_step_y;
}

void	ft_draw_floor_ceiling(t_cub *cub, t_dda_fc *fc, int x, int y)
{
	unsigned int	color;
	int				tex_index;
	int				tex_width;
	int				tex_height;

	if (fc->is_floor)
		tex_index = 6;
	else
		tex_index = 5;
	tex_width = cub->mlx.tex_width[tex_index];
	tex_height = cub->mlx.tex_height[tex_index];
	fc->tx = (int)(tex_width * (fc->fl_x - fc->cell_x)) & (tex_width - 1);
	fc->ty = (int)(tex_height * (fc->fl_y - fc->cell_y)) & (tex_height - 1);
	color = my_mlx_pixel_read(&cub->mlx, fc->tx, fc->ty, tex_index);
	my_mlx_pixel_put(&cub->mlx, x, y, color);
}

void	ft_floor_and_ceiling(t_cub *cub, t_dda_fc *fc)
{
	int y;
	int x;

	y = 0;
	while (y < (int)cub->screen_h)
	{
		fc->is_floor = y > (int)cub->screen_h / 2 + cub->pitch;
		ft_calc_rays(cub, fc);
		ft_camera_fc(cub, fc, y);
		ft_calc_steps_fc(cub, fc);
		x = 0;
		while (x < (int)cub->screen_w)
		{
			calc_position_fc(fc);
			ft_draw_floor_ceiling(cub, fc, x, y);
			x++;
		}
		y++;
	}
}
