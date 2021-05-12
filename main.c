/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/07 20:38:23 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/24 19:51:00 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_start_mlx(t_cub *cub, t_mlx *mlx)
{
	mlx->mlx_p = mlx_init();
	if (mlx->mlx_p == NULL)
		ft_error("mlx->mlx_p count not be initialized", cub);
	if (cub->save == 0)
	{
		mlx->win_p = mlx_new_window(mlx->mlx_p, cub->screen_w,
				cub->screen_h, "RvS");
		if (mlx->win_p == NULL)
			ft_error("mlx->win_p count not be initialized", cub);
	}
	mlx->img_p[0] = mlx_new_image(mlx->mlx_p, cub->screen_w, cub->screen_h);
	mlx->img_p[1] = mlx_new_image(mlx->mlx_p, cub->screen_w, cub->screen_h);
	if (mlx->img_p[0] == NULL || mlx->img_p[1] == NULL)
		ft_error("mlx->img_p count not be initialized", cub);
	mlx->win_add[0] = mlx_get_data_addr(mlx->img_p[0], &mlx->win_bpp,
			&mlx->win_ll, &mlx->win_end);
	mlx->win_add[1] = mlx_get_data_addr(mlx->img_p[1], &mlx->win_bpp,
			&mlx->win_ll, &mlx->win_end);
	if (mlx->win_add[0] == NULL || mlx->win_add[1] == NULL)
		ft_error("mlx->addr not set", cub);
}

void	ft_get_texture_info(t_cub *cub, t_mlx *mlx)
{
	int i;

	i = 0;
	while (i < 5)
	{
		mlx->tex_p[i] = mlx_png_file_to_image(mlx->mlx_p, mlx->tex_path[i],
				&mlx->tex_width[i], &mlx->tex_height[i]);
		if (mlx->tex_p[i] == NULL)
		{
			mlx->tex_p[i] = mlx_xpm_file_to_image(mlx->mlx_p, mlx->tex_path[i],
					&mlx->tex_width[i], &mlx->tex_height[i]);
			if (mlx->tex_p[i] == NULL)
				ft_error(">Warning: texture could not be loaded", cub);
		}
		mlx->tex_add[i] = mlx_get_data_addr(mlx->tex_p[i], &mlx->tex_bpp[i],
				&mlx->tex_ll[i], &mlx->tex_end[i]);
		if (mlx->tex_add[i] == NULL)
			ft_error("Warning: texture_add could not be found", cub);
		i++;
	}
}

int		ft_init_mlx(t_mlx *mlx, t_cub *cub)
{
	ft_start_mlx(cub, mlx);
	ft_get_texture_info(cub, mlx);
	if (mlx->tex_width[4] != mlx->tex_height[4])
		perror("Warning: sprite is not square,"
				"this might result in undefined behaviour");
	cub->dda_sprites.tex_width = cub->mlx.tex_width[4];
	cub->dda_sprites.tex_height = cub->mlx.tex_height[4];
	return (0);
}

void	ft_init(t_cub *cub, char *av)
{
	cub->player.move_speed = 0.09999999;
	cub->player.rot_speed = 0.08;
	ft_init_map(cub, av);
	cub->pitch = 0;
	cub->pos_z = 0;
	ft_init_mlx(&cub->mlx, cub);
	ft_reset_keys(&cub->player);
	cub->z_buffer = (double *)malloc(cub->screen_w * sizeof(double));
	if (cub->z_buffer == NULL)
		ft_error("Can not malloc z_buffer", cub);
}

int		main(int ac, char **av)
{
	t_cub cub;

	cub.map = NULL;
	cub.sprite = NULL;
	cub.z_buffer = NULL;
	cub.mlx.mlx_p = NULL;
	cub.mlx.win_p = NULL;
	cub.save = 0;
	if (ac == 1 || ac > 3)
		ft_error("Too few or too much arguments\nUse:\n"
			"./cub3d [path-to-map]\nor\n./cub3d [path-to-map] --save", &cub);
	if (ac == 3)
		ft_check_argument(&cub, av[2]);
	ft_init(&cub, av[1]);
	mlx_loop_hook(cub.mlx.mlx_p, render_frames, &cub);
	if (cub.save == 0)
	{
		mlx_hook(cub.mlx.win_p, 2, 1L << 0, ft_keypress, &cub);
		mlx_hook(cub.mlx.win_p, 3, 1L << 1, ft_key_release, &cub.player);
		mlx_hook(cub.mlx.win_p, 17, 0, ft_exit, &cub);
	}
	mlx_loop(cub.mlx.mlx_p);
}
