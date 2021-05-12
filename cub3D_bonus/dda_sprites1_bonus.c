/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dda_sprites1.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/30 19:28:20 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/05 22:00:56 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

static void	ft_bubble_sort_sprites(int amount_sprites, t_sprite *sprite)
{
	t_sprite	swap;
	int			i;
	int			j;

	i = 0;
	while (i < amount_sprites - 1)
	{
		j = 0;
		while (j < amount_sprites - i - 1)
		{
			if (sprite[j].dist < sprite[j + 1].dist)
			{
				swap = sprite[j];
				sprite[j] = sprite[j + 1];
				sprite[j + 1] = swap;
			}
			j++;
		}
		i++;
	}
}

void		ft_sprite_order(int amount_sprites, t_sprite *sprite,
		t_player *player)
{
	int			i;

	i = 0;
	while (i < amount_sprites)
	{
		sprite[i].dist = ((player->px - sprite[i].x)
						* (player->px - sprite[i].x)
						+ (player->py - sprite[i].y)
						* (player->py - sprite[i].y));
		i++;
	}
	ft_bubble_sort_sprites(amount_sprites, sprite);
}

/*
** ---------------------------------------------------------------------------
**	translate sprite position to relative to camera
** ---------------------------------------------------------------------------
*/

void		ft_relative_pos(t_cub *cub, t_dda_sprites *ds,
								t_player *player, const int *i)
{
	ds->sprite_x = cub->sprite[*i].x - player->px;
	ds->sprite_y = cub->sprite[*i].y - player->py;
}

/*
** ---------------------------------------------------------------------------
**	transform sprite with the inverse camera matrix
**	inv_det: required for correct matrix multiplication
** ---------------------------------------------------------------------------
*/

void		ft_transform_sprite(t_cub *cub, t_dda_sprites *ds)
{
	double inv_det;

	inv_det = 1.0 / (cub->player.plane_x * cub->player.dy
						- cub->player.dx * cub->player.plane_y);
	ds->transform_x = inv_det * (cub->player.dy
						* ds->sprite_x - cub->player.dx * ds->sprite_y);
	ds->transform_y = inv_det * (-cub->player.plane_y
						* ds->sprite_x + cub->player.plane_x * ds->sprite_y);
	ds->sprite_screen_x = (int)((cub->screen_w / 2)
						* (1 + ds->transform_x / ds->transform_y));
	ds->v_move_screen = (int)(VMOVE / ds->transform_y)
						+ cub->pitch + cub->pos_z / ds->transform_y;
}

/*
** ---------------------------------------------------------------------------
**	using transform_y instead of the real distance prevents fisheye
** ---------------------------------------------------------------------------
*/

void		ft_calc_draw_start_end_spr(t_cub *cub, t_dda_sprites *ds)
{
	ds->sprite_height = abs((int)(cub->screen_h / (ds->transform_y))) / VDIV;
	ds->draw_start_y = -ds->sprite_height / 2
						+ cub->screen_h / 2 + ds->v_move_screen;
	if (ds->draw_start_y < 0)
		ds->draw_start_y = 0;
	ds->draw_end_y = ds->sprite_height / 2
						+ cub->screen_h / 2 + ds->v_move_screen;
	if (ds->draw_end_y >= (int)cub->screen_h)
		ds->draw_end_y = (int)cub->screen_h - 1;
}
