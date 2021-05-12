/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_and_render.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/06 19:27:01 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/24 18:43:17 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void			my_mlx_pixel_put(t_mlx *mlx, int x, int y, unsigned int color)
{
	char	*dst;
	int		i;

	i = mlx->index_img;
	dst = mlx->win_add[i] + (y * mlx->win_ll + x * (mlx->win_bpp / 8));
	*(unsigned int*)dst = color;
}

unsigned int	my_mlx_pixel_read(t_mlx *mlx, int x, int y, int n)
{
	char	*dst;

	if (x < 0 || y < 0)
		dst = BLACK;
	else
		dst = mlx->tex_add[n] + (y * mlx->tex_ll[n]
				+ x * (mlx->tex_bpp[n] / 8));
	return (*(unsigned int*)dst);
}

void			ft_shoot(t_cub *cub)
{
	unsigned int i;
	unsigned int j;

	i = cub->screen_w / 2;
	j = cub->screen_h / 2;
	while (i < cub->screen_w && j < cub->screen_h)
	{
		my_mlx_pixel_put(&cub->mlx, (int)i, (int)j, 0x00FF0000);
		my_mlx_pixel_put(&cub->mlx, (int)i - 1, (int)j, 0x00FF0000);
		my_mlx_pixel_put(&cub->mlx, (int)i - 2, (int)j, 0x00FF0000);
		my_mlx_pixel_put(&cub->mlx, (int)i - 3, (int)j, 0x00FF0000);
		j++;
		i++;
	}
}

void			ft_crosshair(t_cub *cub)
{
	unsigned int i;
	unsigned int x;
	unsigned int y;

	i = 0;
	x = cub->screen_w / 2;
	y = cub->screen_h / 2;
	while (i < 9)
	{
		my_mlx_pixel_put(&cub->mlx, (int)(x - 10 - i), (int)(y), WHITE);
		my_mlx_pixel_put(&cub->mlx, (int)(x - 10 - i), (int)(y - 1), WHITE);
		my_mlx_pixel_put(&cub->mlx, (int)(x - 10 - i), (int)(y + 1), WHITE);
		my_mlx_pixel_put(&cub->mlx, (int)(x + 10 + i), (int)(y), WHITE);
		my_mlx_pixel_put(&cub->mlx, (int)(x + 10 + i), (int)(y - 1), WHITE);
		my_mlx_pixel_put(&cub->mlx, (int)(x + 10 + i), (int)(y + 1), WHITE);
		my_mlx_pixel_put(&cub->mlx, (int)(x), (int)(y - 10 - i), WHITE);
		my_mlx_pixel_put(&cub->mlx, (int)(x - 1), (int)(y - 10 - i), WHITE);
		my_mlx_pixel_put(&cub->mlx, (int)(x + 1), (int)(y - 10 - i), WHITE);
		my_mlx_pixel_put(&cub->mlx, (int)(x), (int)(y + 10 + i), WHITE);
		my_mlx_pixel_put(&cub->mlx, (int)(x - 1), (int)(y + 10 + i), WHITE);
		my_mlx_pixel_put(&cub->mlx, (int)(x + 1), (int)(y + 10 + i), WHITE);
		i++;
	}
}

int				render_frames(t_cub *cub)
{
	cub->mlx.index_img = (cub->mlx.index_img == 0) ? 1 : 0;
	ft_movement(&cub->player, cub);
	ft_floor_and_ceiling(cub, &cub->fc);
	ft_walls(cub, &cub->dda_wall);
	ft_sprites(cub, &cub->dda_sprites);
	if (cub->save)
		ft_bmp("screenshot.bmp", cub);
	if (cub->player.shoot)
		ft_shoot(cub);
	if ((int)cub->map_w > 100 && (int)cub->map_h > 100)
		ft_crosshair(cub);
	mlx_put_image_to_window(cub->mlx.mlx_p, cub->mlx.win_p,
							cub->mlx.img_p[cub->mlx.index_img], 0, 0);
	return (1);
}
