/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub_parse_map3.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/04 19:05:03 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/04 19:06:16 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	ft_map_array_fillers(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	while (i < cub->map_h)
	{
		j = 0;
		while (j < cub->map_w)
		{
			cub->map[i][j] = -99;
			j++;
		}
		i++;
	}
}

void	ft_fill_map(t_cub *cub, char **map_strings)
{
	int i;
	int j;

	i = 0;
	while (i < cub->map_h)
	{
		j = 0;
		while (map_strings[i][j])
		{
			cub->map[i][j] = ft_map_atoi(&map_strings[i][j], cub);
			j++;
		}
		free(map_strings[i]);
		map_strings[i] = NULL;
		i++;
	}
	free(map_strings);
	map_strings = NULL;
}

void	ft_convert_strings_to_map(t_cub *cub, char **map_strings)
{
	ft_malloc_map_array(cub);
	ft_map_array_fillers(cub);
	ft_fill_map(cub, map_strings);
	ft_set_player_position(cub);
}

int		ft_put_map_in_array(t_cub *cub, const char *s)
{
	char	**map_strings;

	map_strings = ft_split(s, '\n');
	ft_get_map_dimensions(cub, map_strings);
	ft_convert_strings_to_map(cub, map_strings);
	return (0);
}

void	ft_count_sprites(t_cub *cub)
{
	int i;
	int j;

	cub->amount_sprites = 0;
	i = 0;
	while (i < cub->map_h)
	{
		j = 0;
		while (j < cub->map_w)
		{
			if (cub->map[i][j] == 2 || cub->map[i][j] == 4)
				cub->amount_sprites += 1;
			j++;
		}
		i++;
	}
}
