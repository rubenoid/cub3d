/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub_parse_map4.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/04 19:06:35 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/04 19:07:44 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_place_sprite(t_sprite *sprite, double x, double y)
{
	sprite->x = x + 0.5;
	sprite->y = y + 0.5;
	sprite->dist = 0;
}

void	ft_parse_sprites(t_cub *cub)
{
	int i;
	int j;
	int x;

	x = 0;
	i = 0;
	while (i < cub->map_h)
	{
		j = 0;
		while (j < cub->map_w)
		{
			if (cub->map[i][j] == 2)
			{
				ft_place_sprite(&cub->sprite[x], i, j);
				x += 1;
			}
			j++;
		}
		i++;
	}
}

void	ft_parse_map(t_cub *cub, const char *map_string)
{
	if (cub->mapval.hatefull_eight == 0 || cub->mapval.player_pos_found == 0)
		ft_error("Check your specifiers and/or player pos not found", cub);
	ft_put_map_in_array(cub, map_string);
	ft_count_sprites(cub);
	cub->sprite = (t_sprite *)malloc(sizeof(t_sprite) * cub->amount_sprites);
	if (cub->sprite == NULL)
		ft_error("Can not malloc sprite structures", cub);
	ft_parse_sprites(cub);
}

void	ft_check_bounds_map(t_cub *cub)
{
	int i;

	i = 0;
	while (i < cub->map_h)
	{
		if (cub->map[i][0] == 3)
			ft_error("Map: player not enclosed", cub);
		if (cub->map[i][cub->map_w - 1] == 3)
			ft_error("Map: player not enclosed", cub);
		i++;
	}
	i = 0;
	while (i < cub->map_w)
	{
		if (cub->map[0][i] == 3)
			ft_error("Map: player not enclosed", cub);
		if (cub->map[cub->map_h - 1][i] == 3)
			ft_error("Map: player not enclosed", cub);
		i++;
	}
}
