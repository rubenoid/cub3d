/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_and_exit.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/16 19:32:24 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/21 20:34:31 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_free_map(t_cub *cub)
{
	int i;

	i = 0;
	if (cub->map)
	{
		while (i < cub->map_h)
		{
			free(cub->map[i]);
			i++;
		}
		free(cub->map);
	}
}

int			ft_exit(t_cub *cub)
{
	if (cub->map)
		ft_free_map(cub);
	if (cub->sprite)
		free(cub->sprite);
	if (cub->z_buffer)
		free(cub->z_buffer);
	if (cub->mlx.mlx_p && cub->mlx.win_p)
		mlx_destroy_window(cub->mlx.mlx_p, cub->mlx.win_p);
	exit(0);
}

void		ft_error(char *s, t_cub *cub)
{
	ft_printf("Error\n%s: %s\n", s, strerror(errno));
	if (cub->map)
		ft_free_map(cub);
	if (cub->sprite)
		free(cub->sprite);
	if (cub->z_buffer)
		free(cub->z_buffer);
	if (!cub->save && cub->mlx.mlx_p && cub->mlx.win_p)
		mlx_destroy_window(cub->mlx.mlx_p, cub->mlx.win_p);
	exit(0);
}
