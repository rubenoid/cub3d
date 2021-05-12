/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub_parse_map1.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-sch <rvan-sch@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/03 20:47:32 by rvan-sch      #+#    #+#                 */
/*   Updated: 2020/08/03 20:51:19 by rvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	ft_parse_line(t_cub *cub, char *line)
{
	int i;

	i = 0;
	while (cub->mapval.hatefull_eight == 0 && line[i] == ' ')
		i++;
	if (line[i] == 'R')
		ft_parse_resolution(cub, line + i + 1);
	if (line[i] == 'N' && line[i + 1] == 'O')
		ft_parse_texture(cub, line + i + 2, 0);
	if (line[i] == 'S' && line[i + 1] == 'O')
		ft_parse_texture(cub, line + i + 2, 1);
	if (line[i] == 'W' && line[i + 1] == 'E')
		ft_parse_texture(cub, line + i + 2, 2);
	if (line[i] == 'E' && line[i + 1] == 'A')
		ft_parse_texture(cub, line + i + 2, 3);
	if (line[i] == 'S' && line[i + 1] == ' ')
		ft_parse_texture(cub, line + i + 1, 4);
	if (line[i] == 'C' && line[i + 1] == ' ')
		ft_parse_texture(cub, line + i + 1, 5);
	if (line[i] == 'F' && line[i + 1] == ' ')
		ft_parse_texture(cub, line + i + 1, 6);
}

void	ft_init_mapval(t_mapval *mapval)
{
	mapval->r = 0;
	mapval->no = 0;
	mapval->so = 0;
	mapval->we = 0;
	mapval->ea = 0;
	mapval->s = 0;
	mapval->f = 0;
	mapval->c = 0;
	mapval->hatefull_eight = 0;
	mapval->map_started = 0;
	mapval->player_pos_found = 0;
}

int		ft_check_eight(t_mapval *mapval)
{
	if (mapval->r == 1 &&
		mapval->no == 1 &&
		mapval->so == 1 &&
		mapval->we == 1 &&
		mapval->ea == 1 &&
		mapval->s == 1 &&
		mapval->f == 1 &&
		mapval->c == 1)
	{
		mapval->hatefull_eight = 1;
		return (1);
	}
	return (0);
}

int		ft_check_map_chars(t_cub *cub, char c)
{
	if (c)
	{
		if (c == ' ' || c == '0' || c == '1' || c == '2' ||
			c == 'N' || c == 'S' || c == 'W' || c == 'E')
		{
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
				cub->mapval.player_pos_found += 1;
			if (cub->mapval.player_pos_found == 2)
				ft_error("Map contains two or more player positions", cub);
			return (1);
		}
		else
			ft_error("Map contains a not valid character", cub);
	}
	return (0);
}

void	ft_check_map_line(t_cub *cub, const char *line)
{
	int			i;
	static int	should_end;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (ft_strlen(line + i) != 0 && should_end)
		ft_error("Map contains empty line", cub);
	if (ft_strlen(line + i) == 0)
		should_end = 1;
	while (line[i] && should_end == 0)
	{
		ft_check_map_chars(cub, line[i]);
		i++;
	}
}
