/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dda_sprites0.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/30 19:23:19 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/05 22:04:17 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_calc_width_sprite(t_cub *cub, t_dda_sprites *ds)
{
	ds->sprite_width = abs((int)(cub->screen_h
								/ (ds->transform_y))) / UDIV;
	ds->draw_start_x = -ds->sprite_width
						/ 2 + ds->sprite_screen_x;
	if (ds->draw_start_x < 0)
		ds->draw_start_x = 0;
	ds->draw_end_x = ds->sprite_width / 2 + ds->sprite_screen_x;
	if (ds->draw_end_x > (int)cub->screen_w)
		ds->draw_end_x = (int)cub->screen_w;
}

/*
**	----------------------------------------------------------------------------
**	about the first if statement:
**	sometimes tex_x and/or tex_y is negative and this results in a segfault
**	----------------------------------------------------------------------------
*/

static void	ft_draw_sprite_y(t_cub *cub, t_dda_sprites *ds, int x)
{
	int				d;
	int				tex_y;
	unsigned int	color;
	int				y;

	y = ds->draw_start_y;
	while (y < ds->draw_end_y)
	{
		d = (y - ds->v_move_screen) * 256 - cub->screen_h
				* 128 + ds->sprite_height * 128;
		tex_y = ((d * ds->tex_height) / ds->sprite_height) / 256;
		if (ds->tex_x < cub->mlx.tex_width[4] && tex_y < cub->mlx.tex_height[4]
			&& ds->tex_x >= 0 && tex_y >= 0)
			color = my_mlx_pixel_read(&cub->mlx, ds->tex_x, tex_y, 4);
		else
			color = BLACK;
		if ((color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(&cub->mlx, x, y, color);
		y++;
	}
}

static void	ft_sprite_math(t_cub *cub, t_dda_sprites *ds, int *i)
{
	ds->draw_start_x = 0;
	ds->draw_start_y = 0;
	ds->draw_end_x = 0;
	ds->draw_end_y = 0;
	ft_relative_pos(cub, ds, &cub->player, i);
	ft_transform_sprite(cub, ds);
	ft_calc_draw_start_end_spr(cub, ds);
	ft_calc_width_sprite(cub, ds);
}

/*
**	----------------------------------------------------------------------------
**	the conditions in the if statement are:
**	1) it is in front of camera plane so you do not see things behind you
**	2) it is on the lefthand side of the screen
**	3) it is on the righthand side of the screen
**	4) z_buffer, with perpendicular distance
**	----------------------------------------------------------------------------
*/

void		ft_sprites(t_cub *cub, t_dda_sprites *ds)
{
	int i;
	int x;

	ft_sprite_order(cub->amount_sprites, cub->sprite, &cub->player);
	i = 0;
	while (i < cub->amount_sprites)
	{
		ft_sprite_math(cub, ds, &i);
		x = ds->draw_start_x;
		while (x < ds->draw_end_x)
		{
			ds->tex_x = (int)(256 * (x - (-ds->sprite_width / 2
			+ ds->sprite_screen_x)) * ds->tex_width / ds->sprite_width) / 256;
			if (ds->transform_y > 0 && x > 0 && x < (int)cub->screen_w
				&& ds->transform_y < cub->z_buffer[x])
				ft_draw_sprite_y(cub, ds, x);
			x++;
		}
		i++;
	}
}
