/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_and_render.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/06 19:27:01 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/16 19:32:02 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

void			ft_background(t_cub *cub)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < cub->screen_w)
	{
		j = 0;
		while (j < cub->screen_h / 2)
		{
			my_mlx_pixel_put(&cub->mlx, (int)i, (int)j, cub->ceiling);
			j++;
		}
		while (j >= cub->screen_h / 2 && j < cub->screen_h)
		{
			my_mlx_pixel_put(&cub->mlx, (int)i, (int)j, cub->floor);
			j++;
		}
		i++;
	}
}

int				render_frames(t_cub *cub)
{
	cub->mlx.index_img = (cub->mlx.index_img == 0) ? 1 : 0;
	ft_movement(&cub->player, cub);
	ft_background(cub);
	ft_walls(cub, &cub->dda_wall);
	ft_sprites(cub, &cub->dda_sprites);
	if (cub->save)
		ft_bmp("screenshot.bmp", cub);
	mlx_put_image_to_window(cub->mlx.mlx_p, cub->mlx.win_p,
							cub->mlx.img_p[cub->mlx.index_img], 0, 0);
	return (1);
}
